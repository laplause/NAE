#include "GameObject.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace NAE;

GameObject::GameObject() :
	mPosition(0, 0, 0),
	mRotation(0, 0, 0),
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

const glm::mat4x4& GameObject::GetTransform() const
{
	glm::mat4 rotation = glm::yawPitchRoll(mRotation.z, mRotation.y, mRotation.x);
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), mPosition);

	return rotation * translation;
}