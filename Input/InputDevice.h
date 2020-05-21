#ifndef INPUTDEVICE_H
#define INPUTDEVICE_H

#include "InputDeviceInitializer.h"
#include "GameClock.h"

#include <string>

namespace NAE
{
	class InputDevice : public Type
	{
		TYPE_DECLARATIONS(InputDevice, Type);
	public:
		explicit InputDevice(const std::string& name);
		virtual ~InputDevice();

		virtual void Update(const GameClock& clock) = 0;
		virtual void Init(const InputDeviceInitializer& deviceInitializer) = 0;

	private:
		std::string mName;
	};
}
#endif
