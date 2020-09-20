#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H

#include "System.h"
#include "InputComponent.h"
#include "GameObject.h"
#include "InputMaps.h"

#include <vector>
#include <map>

namespace NAE
{
	// Forward declarations
	class Keyboard;
	class Mouse;

	class InputManager : public System
	{
		TYPE_DECLARATIONS(InputManager, System);
	public:
		explicit InputManager(const std::string& name);
		virtual ~InputManager();

		virtual void Update() = 0;
		virtual void AddComponent(uint32_t gameObjectId);

		void AddActionInputMapping(const std::string& inputAction, Keys keyboardKey);
		void AddActionInputMapping(const std::string& inputAction, MouseButtons mouseButton);

		template<typename T, typename Function>
		void RegisterInputEvent(const std::string& inputAction, T* subscriber, Function callback)
		{
			//GameObject* go = subscriber->As<GameObject*>();
			//if (go != nullptr)
			{
				InputComponent& ic = mComponents[subscriber->Id()];
				if (!ic.Enabled())
				{
					AddComponent(subscriber->Id());
				}
				ic.AddInputEvent(inputAction, std::bind(callback, subscriber));
			}
		}

	protected:
		Keyboard* mKeyboard;
		Mouse* mMouse;

		std::map<std::string, Keys> mActionToKeyMappings;
		std::map<std::string, MouseButtons> mActionToMouseMappings;

		std::vector<InputComponent> mComponents;
	};
}
#endif
