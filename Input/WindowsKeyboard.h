#ifdef OS_WINDOWS

#ifndef WINDOWS_KEYBOARD_H
#define WINDOWS_KEYBOARD_H

#include "Keyboard.h"

#include <dinput.h>

namespace NAE
{
	class WindowsKeyboard : public Keyboard
	{
		TYPE_DECLARATIONS(WindowsKeyboard, Keyboard);
	public:
		WindowsKeyboard();
		virtual ~WindowsKeyboard();

		virtual void Update(const GameClock& clock);
		virtual void Init(const InputDeviceInitializer& deviceInitializer);

		virtual bool IsKeyUp(unsigned char key) const;
		virtual bool IsKeyDown(unsigned char key) const;
		virtual bool WasKeyUp(unsigned char key) const;
		virtual bool WasKeyDown(unsigned char key) const;
		virtual bool WasKeyPressedThisFrame(unsigned char key) const;
		virtual bool WasKeyReleasedThisFrame(unsigned char key) const;
		virtual bool IsKeyHeldDown(unsigned char key) const;

	private:
		LPDIRECTINPUTDEVICE8 mDirectInputDevice;
	};
}
#endif

#endif //OS_WINDOWS
