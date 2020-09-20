#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include "NAEObject.h"

#include <windows.h>

namespace NAE
{
	class GameClock : public NAEObject
	{
		TYPE_DECLARATIONS(GameClock, NAEObject);
	public:
		GameClock();
		virtual ~GameClock();

		const double TotalGameTime() const;
		const double DeltaTime() const;

		virtual void Update();
		void Reset();

	private:
		GameClock(const GameClock& other);
		GameClock& operator=(const GameClock& rhs);

		const double GetFrequency();

		double mFrequency;
		double mTotalGameTime;
		double mDeltaTime;

		LARGE_INTEGER mStartTime;
		LARGE_INTEGER mCurrentTime;
		LARGE_INTEGER mLasTime;
	};
}
#endif
