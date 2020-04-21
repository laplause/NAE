#ifndef SYSTEM_H
#define SYSTEM_H

#include "GameClock.h"

#include <string>

namespace NAE
{
	class System
	{
	public:
		System();
		virtual ~System();

		virtual void Update(const GameClock& clock) = 0;

		inline const std::string& Name() { return mName; };

	private:
		std::string mName;
	};
}
#endif
