#include "Entity.h"
#include <assert.h>
using namespace NAE;

TYPE_DEFINITIONS(Entity);

uint32_t Entity::sNextGameObjectId = 0;

Entity::Entity() :
	NAEObject("")
{
	assert(sNextGameObjectId < UINT32_MAX);
	mId = sNextGameObjectId++;
}

Entity::Entity(const std::string& name) :
	NAEObject(name)
{
	assert(sNextGameObjectId < UINT32_MAX);
	mId = sNextGameObjectId++;
}

Entity::~Entity()
{

}