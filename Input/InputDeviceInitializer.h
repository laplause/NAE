#ifndef INPUT_DEVICE_INITIALIZER_H
#define INPUT_DEVICE_INITIALIZER_H

#ifdef OS_WINDOWS
#include "dinput.h"
#endif

namespace NAE
{
	struct InputDeviceInitializer
	{
	#ifdef OS_WINDOWS
		LPDIRECTINPUT8 directInput;
	#endif
	};
}

#endif
