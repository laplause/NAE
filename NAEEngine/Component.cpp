#include "Component.h"
using namespace NAE;

TYPE_DEFINITIONS(Component);

Component::Component() :
	NAEObject(""),
	mActive(true)
{

}

Component::Component(const std::string& name) :
	NAEObject(name),
	mActive(true)
{

}

Component::~Component()
{

}