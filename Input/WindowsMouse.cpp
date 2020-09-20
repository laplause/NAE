#ifdef OS_WINDOWS

#include "WindowsMouse.h"
#include "NAEEngine.h"

#include <assert.h>

using namespace NAE;

TYPE_DEFINITIONS(WindowsMouse);

WindowsMouse::WindowsMouse() :
	Mouse("WindowsMouse")
{
	memset(&mCurrentState, 0, sizeof(mCurrentState));
	memset(&mLastState, 0, sizeof(mLastState));
}

WindowsMouse::~WindowsMouse()
{
	if (mDirectInputDevice != nullptr)
	{
		mDirectInputDevice->Unacquire();
		mDirectInputDevice->Release();
		mDirectInputDevice = nullptr;
	}
}

void WindowsMouse::Init(const InputDeviceInitializer& deviceInitializer)
{
	deviceInitializer.directInput->CreateDevice(GUID_SysMouse, &mDirectInputDevice, nullptr);
	assert(mDirectInputDevice != nullptr);

	if (FAILED(mDirectInputDevice->SetDataFormat(&c_dfDIMouse)))
	{
		assert(false);
	}

	mDirectInputDevice->SetCooperativeLevel(NAEEngine::Engine()->MainWindowHandle(), DISCL_FOREGROUND | DISCL_NONEXCLUSIVE);
	mDirectInputDevice->Acquire();
}

void WindowsMouse::Update()
{
	if (mDirectInputDevice != nullptr)
	{
		memcpy(&mLastState, &mCurrentState, sizeof(mCurrentState));

		if (FAILED(mDirectInputDevice->GetDeviceState(sizeof(mCurrentState), &mCurrentState)))
		{
			if (SUCCEEDED(mDirectInputDevice->Acquire()))
			{
				if (FAILED(mDirectInputDevice->GetDeviceState(sizeof(mCurrentState), &mCurrentState)))
				{
					return;
				}
			}
		}

		mX += mCurrentState.lX;
		mY += mCurrentState.lY;
		mWheel += mCurrentState.lZ;
	}
}

bool WindowsMouse::IsButtonUp(MouseButtons button) const
{
	return ((mCurrentState.rgbButtons[button] & 0x80) == 0);
}

bool WindowsMouse::IsButtonDown(MouseButtons button) const
{
	return ((mCurrentState.rgbButtons[button] & 0x80) != 0);
}

bool WindowsMouse::WasButtonUp(MouseButtons button) const
{
	return ((mLastState.rgbButtons[button] & 0x80) == 0);
}

bool WindowsMouse::WasButtonDown(MouseButtons button) const
{
	return ((mLastState.rgbButtons[button] & 0x80) != 0);
}

bool WindowsMouse::WasButtonPressedThisFrame(MouseButtons button) const
{
	return (IsButtonDown(button) && WasButtonUp(button));
}

bool WindowsMouse::WasButtonReleasedThisFrame(MouseButtons button) const
{
	return (IsButtonUp(button) && WasButtonDown(button));
}

bool WindowsMouse::IsButtonHeldDown(MouseButtons button) const
{
	return (IsButtonDown(button) && WasButtonDown(button));
}

#endif // OS_WINDOWS