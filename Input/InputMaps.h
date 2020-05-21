#ifndef INPUT_MAPS_H
#define INPUT_MAPS_H

#if defined(OS_WINDOWS)
#include "dinput.h"
#endif

#include <map>

namespace NAE
{
	enum MouseButtons
	{
		MOUSELEFT = 0,
		MOUSERIGHT,
		MOUSEMIDDLE,
		MOUSEX1,
		MOUSEBUTTONSMAX

	};

	enum Keys
	{
		KEY_ESCAPE = 0,
		KEY_1,
		KEY_2,
		KEY_3,
		KEY_4,
		KEY_5,
		KEY_6,
		KEY_7,
		KEY_8,
		KEY_9,
		KEY_0,
		KEY_MINUS,
		KEY_EQUALS,
		KEY_BACK,
		KEY_TAB,
		KEY_Q,
		KEY_W,
		KEY_E,
		KEY_R,
		KEY_T,
		KEY_Y,
		KEY_U,
		KEY_I,
		KEY_O,
		KEY_P,
		KEY_LBRACKET,
		KEY_RBRACKET,
		KEY_BACKSLASH,
		KEY_A,
		KEY_S,
		KEY_D,
		KEY_F,
		KEY_G,
		KEY_H,
		KEY_J,
		KEY_K,
		KEY_L,
		KEY_SEMICOLON,
		KEY_APOSTROPHE,
		KEY_ENTER,
		KEY_LSHIFT,
		KEY_Z,
		KEY_X,
		KEY_C,
		KEY_V,
		KEY_B,
		KEY_N,
		KEY_M,
		KEY_COMMA,
		KEY_PERIOD,
		KEY_SLASH,
		KEY_RSHIFT,
		KEY_LCONTROL,
		KEY_SPACE,
		KEY_RCONTROL,
		KEYSMAX
	};
}

extern const std::map<NAE::Keys, int> WindowsKeyMap;
#endif
