#include "Mouse.h"
using namespace NAE;

TYPE_DEFINITIONS(Mouse);

Mouse::Mouse(const std::string& name) :
	InputDevice(name),
	mX(0),
	mY(0),
	mWheel(0)
{

}

Mouse::~Mouse()
{

}