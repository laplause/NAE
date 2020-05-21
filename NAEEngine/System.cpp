#include "System.h"
using namespace NAE;

TYPE_DEFINITIONS(System);

System::System(const std::string& name) :
	mName(name)
{

}

System::~System()
{

}

void System::Update(const GameClock& clock)
{

}

void System::AddComponent(uint32_t gameObjectId)
{
	
}