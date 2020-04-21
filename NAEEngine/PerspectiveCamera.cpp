#include "PerspectiveCamera.h"
using namespace NAE;

PerspectiveCamera::PerspectiveCamera() :
	Camera(),
	mFieldOfView(sDefaultFieldOfView),
	mNearPlaneDistance(sDefaultNearPlaneDistance),
	mFarPlaneDistance(sDefaultFarPlaneDistance)
{

}

PerspectiveCamera::PerspectiveCamera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance) :
	Camera(),
	mFieldOfView(fieldOfView),
	mAspectRatio(aspectRatio),
	mNearPlaneDistance(nearPlaneDistance),
	mFarPlaneDistance(farPlaneDistance)
{
	mProjectionMatrix = glm::perspective(glm::radians(mFieldOfView), mAspectRatio, mNearPlaneDistance, mFarPlaneDistance);
	// Fix this later. Need to reverse y direction cause of Vulkan coordinate system
	mProjectionMatrix[1][1] *= -1;
}

PerspectiveCamera::~PerspectiveCamera()
{

}

void PerspectiveCamera::Update(const GameClock& gameClock)
{

}

void PerspectiveCamera::SetCameraParameters(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance)
{
	mFieldOfView = fieldOfView;
	mAspectRatio = aspectRatio;
	mNearPlaneDistance = nearPlaneDistance;
	mFarPlaneDistance = farPlaneDistance;
}