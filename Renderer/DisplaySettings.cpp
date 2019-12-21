#include "DisplaySettings.h"
using namespace NAE;

DisplaySettings::DisplaySettings() :
	mFullScreen(false),
	mBorderless(false),
	mRequestedWidth(1920),
	mRequestedHeight(1080),
	mAppName(""),
	creator(nullptr)
{

}

DisplaySettings::~DisplaySettings()
{

}