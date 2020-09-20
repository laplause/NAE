#ifdef OS_WINDOWS

#include "WindowsKeyboard.h"
#include "NAEEngine.h"

#include <assert.h>

using namespace NAE;

TYPE_DEFINITIONS(WindowsKeyboard);

WindowsKeyboard::WindowsKeyboard() :
	Keyboard("WindowsKeyboard"),
	mDirectInputDevice(nullptr)
{
	
}

WindowsKeyboard::~WindowsKeyboard()
{
	if (mDirectInputDevice != nullptr)
	{
		mDirectInputDevice->Unacquire();
		mDirectInputDevice->Release();
		mDirectInputDevice = nullptr;
	}
}

void WindowsKeyboard::Init(const InputDeviceInitializer& deviceInitializer)
{
	
	deviceInitializer.directInput->CreateDevice(GUID_SysKeyboard, &mDirectInputDevice, nullptr);
	assert(mDirectInputDevice);

	if (FAILED(mDirectInputDevice->SetDataFormat(&c_dfDIKeyboard)))
	{
		assert(false);
	}

	mDirectInputDevice->SetCooperativeLevel(NAEEngine::Engine()->MainWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	mDirectInputDevice->Acquire();
}

void WindowsKeyboard::Update()
{
	if (mDirectInputDevice != nullptr)
	{
		memcpy(mLastState, mCurrentState, sizeof(mCurrentState));

		HRESULT rslt = mDirectInputDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState);
		if (FAILED(rslt))
		{
			rslt = mDirectInputDevice->Acquire();
			if (SUCCEEDED(rslt))
			{
				mDirectInputDevice->GetDeviceState(sizeof(mCurrentState), (LPVOID)mCurrentState);
			}
		}
	}
}

bool WindowsKeyboard::IsKeyUp(unsigned char key) const
{
	return ((mCurrentState[key] & 0x80) == 0);
}

bool WindowsKeyboard::IsKeyDown(unsigned char key) const
{
	return ((mCurrentState[key] & 0x80) != 0);
}

bool WindowsKeyboard::WasKeyUp(unsigned char key) const
{
	return ((mLastState[key] & 0x80) == 0);
}

bool WindowsKeyboard::WasKeyDown(unsigned char key) const
{
	return ((mLastState[key] & 0x80) != 0);
}

bool WindowsKeyboard::WasKeyPressedThisFrame(unsigned char key) const
{
	return (IsKeyDown(key) && WasKeyUp(key));
}

bool WindowsKeyboard::WasKeyReleasedThisFrame(unsigned char key) const
{
	return (IsKeyUp(key) && WasKeyDown(key));
}

bool WindowsKeyboard::IsKeyHeldDown(unsigned char key) const
{
	return (IsKeyDown(key) && WasKeyDown(key));
}

#endif //OS_WINDOWS