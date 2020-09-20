#ifndef MOUSE_H
#define MOUSE_H

#include "InputDevice.h"
#include "InputMaps.h"

namespace NAE
{
	class Mouse : public InputDevice
	{
		TYPE_DECLARATIONS(Mouse, InputDevice);
	public:
		explicit Mouse(const std::string& name);
		virtual ~Mouse();

		virtual void Update() = 0;
		virtual void Init(const InputDeviceInitializer& deviceInitializer) = 0;

		virtual bool IsButtonUp(MouseButtons button) const = 0;
		virtual bool IsButtonDown(MouseButtons button) const = 0;
		virtual bool WasButtonUp(MouseButtons button) const = 0;
		virtual bool WasButtonDown(MouseButtons button) const = 0;
		virtual bool WasButtonPressedThisFrame(MouseButtons button) const = 0;
		virtual bool WasButtonReleasedThisFrame(MouseButtons button) const = 0;
		virtual bool IsButtonHeldDown(MouseButtons button) const = 0;

		inline long X() const { return mX; };
		inline long Y() const { return mY; }
		inline long Wheel() const { return mWheel; }

	protected:
		long mX;
		long mY;
		long mWheel;
	};
}
#endif
