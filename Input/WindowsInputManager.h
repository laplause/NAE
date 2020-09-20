#ifdef OS_WINDOWS

#ifndef WINDOWS_INPUT_MANAGER_H
#define WINDOWS_INPUT_MANAGER_H

#define INITGUID

#include "InputManager.h"

#include "dinput.h"

namespace NAE
{
	class WindowsInputManager : public InputManager
	{
		TYPE_DECLARATIONS(WindowsInputManager, InputManager);
	public:
		WindowsInputManager();
		virtual ~WindowsInputManager();

		virtual void Update();

	private:
		LPDIRECTINPUT8 mDirectInput;
	};
}
#endif

#endif // OS_WINDOWS
