#include "GameClock.h"

GameClock::GameClock() :
	mTotalGameTime(0),
	mDeltaTime(0),
	mStartTime(),
	mCurrentTime(),
	mLasTime(),
	mFrequency()
{
	mFrequency = GetFrequency();
	Reset();
}

GameClock::~GameClock()
{

}

const double GameClock::TotalGameTime() const
{
	return mTotalGameTime;
}

const double GameClock::DeltaTime() const
{
	return mDeltaTime;
}

void GameClock::UpdateTime()
{
	QueryPerformanceCounter(&mCurrentTime);
	mTotalGameTime = (mCurrentTime.QuadPart - mStartTime.QuadPart) / mFrequency;
	mDeltaTime = (mCurrentTime.QuadPart - mLasTime.QuadPart) / mFrequency;
	mLasTime = mCurrentTime;
}

const double GameClock::GetFrequency()
{
	LARGE_INTEGER frequency;
	QueryPerformanceFrequency(&frequency);
	return (double)frequency.QuadPart;
}

void GameClock::Reset()
{
	QueryPerformanceCounter(&mStartTime);
	mCurrentTime = mStartTime;
	mLasTime = mCurrentTime;
}