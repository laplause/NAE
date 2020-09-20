#include "InputManager.h"
#include "Keyboard.h"
#include "Mouse.h"
using namespace NAE;

TYPE_DEFINITIONS(InputManager);

InputManager::InputManager(const std::string& name) :
	System(name),
	mKeyboard(nullptr),
	mMouse(nullptr),
	mComponents(),
	mActionToKeyMappings(),
	mActionToMouseMappings()
{
	// TODO: Start with 100 for now. Would be nice to initialize this to a number that comes from the
	// editor
	mComponents.resize(100);
}

InputManager::~InputManager()
{
	if (mKeyboard != nullptr)
	{
		delete mKeyboard;
		mKeyboard = nullptr;
	}

	if (mMouse != nullptr)
	{
		delete mMouse;
		mMouse = nullptr;
	}
}

void InputManager::Update()
{
	mKeyboard->Update();
	mMouse->Update();
}

void InputManager::AddComponent(uint32_t gameObjectId)
{
	InputComponent& newComponent = mComponents[gameObjectId];
	newComponent.Initialize();
}

void InputManager::AddActionInputMapping(const std::string& inputAction, Keys keyboardKey)
{
	if (keyboardKey < 0 || keyboardKey > Keys::KEYSMAX)
	{
		return;
	}

	mActionToKeyMappings[inputAction] = keyboardKey;
}

void InputManager::AddActionInputMapping(const std::string& inputAction, MouseButtons mouseButton)
{
	if (mouseButton < 0 || mouseButton > MouseButtons::MOUSEBUTTONSMAX)
	{
		return;
	}

	mActionToMouseMappings[inputAction] = mouseButton;
}
