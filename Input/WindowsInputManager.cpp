#ifdef OS_WINDOWS

#include "WindowsInputManager.h"
#include "WindowsKeyboard.h"
#include "WindowsMouse.h"
#include "NAEEngine.h"
using namespace NAE;

TYPE_DEFINITIONS(WindowsInputManager);

WindowsInputManager::WindowsInputManager() :
	InputManager("WindowsInputManager")
{
	DirectInput8Create(NAEEngine::Engine()->MainWindowInstance(), DIRECTINPUT_VERSION, IID_IDirectInput8, (LPVOID*)&mDirectInput, nullptr);

	InputDeviceInitializer deviceInitializer;
	deviceInitializer.directInput = mDirectInput;

	mKeyboard = new WindowsKeyboard();
	mMouse = new WindowsMouse();

	mKeyboard->Init(deviceInitializer);
	mMouse->Init(deviceInitializer);
}

WindowsInputManager::~WindowsInputManager()
{

}

void WindowsInputManager::Update(const GameClock& clock)
{
	InputManager::Update(clock);

	for (auto it = mActionToKeyMappings.begin(); it != mActionToKeyMappings.end(); ++it)
	{
		Keys key = it->second;
		const std::string& inputAction = it->first;

		int winKey = WindowsKeyMap.find(key)->second;
		if (mKeyboard->IsKeyDown(WindowsKeyMap.find(key)->second))
		{
			for (size_t i = 0; i < mComponents.size(); ++i)
			{
				const InputComponent& ic = mComponents[i];
				if (ic.HandlerExists(inputAction))
				{
					ic.HandleInput(inputAction);
				}
			}
		}
	}

	for (auto it = mActionToMouseMappings.begin(); it != mActionToMouseMappings.end(); ++it)
	{
		MouseButtons button = it->second;
		const std::string& inputAction = it->first;

		if (mMouse->IsButtonDown(button))
		{
			for (size_t i = 0; i < mComponents.size(); ++i)
			{
				const InputComponent& ic = mComponents[i];
				if (ic.HandlerExists(inputAction))
				{
					ic.HandleInput(inputAction);
				}
			}
		}
	}
}

#endif //OS_WINDOWS