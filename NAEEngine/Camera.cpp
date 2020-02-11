#include "Camera.h"
using namespace NAE;

Camera::Camera() :
	GameObject(),
	mViewMatrix(),
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

const glm::mat4x4& Camera::ViewMatrix()
{
	return mViewMatrix;
}

const glm::mat4x4& Camera::ProjectionMatrix()
{
	return mProjectionMatrix;
}

const glm::mat4x4& Camera::ViewProjectionMatrix()
{
	return mViewMatrix * mProjectionMatrix;
}