#include "Asset.h"
using namespace NAE;

TYPE_DEFINITIONS(Asset);

Asset::Asset() :
	NAEObject(""),
	mResourcePath(""),
	mLoaded(false)
{

}

Asset::Asset(const std::string& name) :
	NAEObject(name),
	mResourcePath(""),
	mLoaded(false)
{

}

Asset::Asset(const std::string& name, const std::string& resourcePath) :
	NAEObject(name),
	mResourcePath(resourcePath),
	mLoaded(false)
{

}

Asset::~Asset()
{

}