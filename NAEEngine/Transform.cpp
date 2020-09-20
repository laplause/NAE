#include "Transform.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace NAE;

TYPE_DEFINITIONS(Transform);

Transform::Transform() :
	Component("TransformComponent"),
	mPosition(0, 0, 0),
	mRotation(0, 0, 0),
	mVelocity(0)
{

}

Transform::Transform(const glm::vec3& position, const glm::vec3& rotation, const float& velocity) :
	Component("TransformComponent"),
	mPosition(position),
	mRotation(rotation),
	mVelocity(velocity)
{

}

Transform::~Transform()
{

}

const glm::mat4x4& Transform::GetTransform() const
{
	glm::mat4 rotation = glm::yawPitchRoll(mRotation.z, mRotation.y, mRotation.x);
	glm::mat4 translation = glm::translate(glm::mat4(1.0f), mPosition);

	return rotation * translation;
}