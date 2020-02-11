#include "GameObject.h"
using namespace NAE;

GameObject::GameObject() :
	mPosition(0, 0, 0),
	mVelocity(0),
	mEnabled(false),
	mVisible(true)
{

}

GameObject::~GameObject()
{

}

void GameObject::Update(const GameClock& gameClock)
{

}

void GameObject::SetPosition(float x, float y, float z)
{
	mPosition.x = x;
	mPosition.y = y;
	mPosition.z = z;
}

void GameObject::SetPosition(glm::vec3& position)
{
	mPosition = position;
}

void GameObject::SetEnabled(bool enable)
{
	mEnabled = enable;
}

void GameObject::SetVisible(bool visible)
{
	mVisible = visible;
}

const bool GameObject::isEnabled() const
{
	return mEnabled;
}

const bool GameObject::isVisible() const
{
	return mVisible;
}

const glm::vec3& GameObject::GetPosition() const
{
	return mPosition;
}