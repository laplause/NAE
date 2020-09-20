#pragma once

#include "System.h"

namespace NAE
{
	class PhysicsManager : public System
	{
		TYPE_DECLARATIONS(PhysicsManager, System);
	public: 
		PhysicsManager(const std::string& name);
		virtual ~PhysicsManager();

		void Update(const GameClock& clock);
	};
}