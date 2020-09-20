#ifdef OS_WINDOWS

#ifndef WINDOWS_MOUSE_H
#define WINDOWS_MOUSE_H

#include "Mouse.h"

#include "dinput.h"

namespace NAE
{
	class WindowsMouse : public Mouse
	{
		TYPE_DECLARATIONS(WindowsMouse, Mouse);
	public:
		WindowsMouse();
		virtual ~WindowsMouse();

		virtual void Update();
		virtual void Init(const InputDeviceInitializer& deviceInitializer);

		virtual bool IsButtonUp(MouseButtons button) const;
		virtual bool IsButtonDown(MouseButtons button) const;
		virtual bool WasButtonUp(MouseButtons button) const;
		virtual bool WasButtonDown(MouseButtons button) const;
		virtual bool WasButtonPressedThisFrame(MouseButtons button) const;
		virtual bool WasButtonReleasedThisFrame(MouseButtons button) const;
		virtual bool IsButtonHeldDown(MouseButtons button) const;

	private:
		LPDIRECTINPUTDEVICE8 mDirectInputDevice;
		DIMOUSESTATE mCurrentState;
		DIMOUSESTATE mLastState;
	};
}
#endif

#endif //OS_WINDOWS
