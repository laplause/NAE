#ifndef INPUT_COMPONENT_H
#define INPUT_COMPONENT_H

#include "Component.h"

#include <functional>
#include <map>

namespace NAE
{
	class InputComponent : public Component
	{
		TYPE_DECLARATIONS(InputComponent, Component);
	public:
		typedef std::function<void()> InputHandler;

		InputComponent();
		virtual ~InputComponent();

		void Initialize();
		void AddInputEvent(const std::string& eventName, InputHandler callback);
		void HandleInput(const std::string& actionName) const;

		inline const bool HandlerExists(const std::string& actionName) const { return mRegisteredCallbacks.find(actionName) != mRegisteredCallbacks.end(); };

	private:
		std::map<std::string, InputHandler> mRegisteredCallbacks;
	};
}
#endif
