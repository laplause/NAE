#ifndef SYSTEM_H
#define SYSTEM_H

#include "GameClock.h"
#include "Component.h"

#include <string>

namespace NAE
{
	class System : public Type
	{
		TYPE_DECLARATIONS(System, Type);
	public:
		explicit System(const std::string& name);
		virtual ~System();

		virtual void Update(const GameClock& clock) = 0;
		virtual void AddComponent(uint32_t gameObjectId);

		inline const std::string& Name() { return mName; };

	private:
		std::string mName;
	};
}
#endif
