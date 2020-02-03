#ifndef GAMECLOCK_H
#define GAMECLOCK_H

#include <windows.h>

class GameClock
{
public:
	GameClock();
	~GameClock();

	const double TotalGameTime() const;
	const double DeltaTime() const;

	void UpdateTime();
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
#endif
