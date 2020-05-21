#include "InputComponent.h"
using namespace NAE;

TYPE_DEFINITIONS(InputComponent);

InputComponent::InputComponent() :
	Component(),
	mRegisteredCallbacks()
{

}

InputComponent::~InputComponent()
{

}

void InputComponent::Initialize()
{
	mEnabled = true;
}

void InputComponent::AddInputEvent(const std::string& eventName, InputHandler callback)
{
	mRegisteredCallbacks[eventName] = callback;
}

void InputComponent::HandleInput(const std::string& actionName) const
{
	InputHandler handler = (mRegisteredCallbacks.find(actionName))->second;
	handler();
}

