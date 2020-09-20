#ifndef KEYBOARD_H
#define KEYBOARD_H

#include "InputDevice.h"

namespace NAE
{
	class Keyboard : public InputDevice
	{
		TYPE_DECLARATIONS(Keyboard, InputDevice);
	public:
		explicit Keyboard(const std::string& name);
		virtual ~Keyboard();

		virtual void Update() = 0;
		virtual void Init(const InputDeviceInitializer& deviceInitializer) = 0;

		virtual bool IsKeyUp(unsigned char key) const = 0;
		virtual bool IsKeyDown(unsigned char key) const = 0;
		virtual bool WasKeyUp(unsigned char key) const = 0;
		virtual bool WasKeyDown(unsigned char key) const = 0;
		virtual bool WasKeyPressedThisFrame(unsigned char key) const = 0;
		virtual bool WasKeyReleasedThisFrame(unsigned char key) const = 0;
		virtual bool IsKeyHeldDown(unsigned char key) const = 0;

	protected:
		static const int sKeyCount = 256;

		unsigned char mCurrentState[sKeyCount];
		unsigned char mLastState[sKeyCount];
	};
}
#endif
