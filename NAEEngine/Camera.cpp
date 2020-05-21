#include "Camera.h"
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>
using namespace NAE;

TYPE_DEFINITIONS(Camera);

Camera::Camera() :
	GameObject(),
	mProjectionMatrix()
{
	SetEnabled(true);
	SetVisible(false);
}

Camera::~Camera()
{

}

void Camera::Update(const GameClock& gameClock)
{

}

const glm::mat4x4& Camera::ViewMatrix() const
{
	glm::mat4 translation = glm::lookAt(mPosition, glm::vec3(0, 0, 0), glm::vec3(0, 1.0f, 0));
	glm::mat4 rotation = glm::mat4(1);//glm::yawPitchRoll(mRotation.z, mRotation.y, mRotation.x);

	return rotation * translation;
}