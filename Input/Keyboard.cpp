#include "Keyboard.h"
using namespace NAE;

TYPE_DEFINITIONS(Keyboard);

Keyboard::Keyboard(const std::string& name) :
	InputDevice(name)
{
	memset(mCurrentState, 0, sizeof(mCurrentState));
	memset(mLastState, 0, sizeof(mLastState));
}

Keyboard::~Keyboard()
{

}