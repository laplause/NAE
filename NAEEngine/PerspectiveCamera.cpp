#include "PerspectiveCamera.h"
#include "NAEEngine.h"
#include "InputManager.h"
using namespace NAE;

TYPE_DEFINITIONS(PerspectiveCamera);

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

	NAEEngine::Input()->RegisterInputEvent("MoveForward", this, &PerspectiveCamera::MoveForward);
	NAEEngine::Input()->RegisterInputEvent("MoveBack", this, &PerspectiveCamera::MoveBack);
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

void PerspectiveCamera::MoveForward()
{
	mPosition.z -= 0.02f;
}

void PerspectiveCamera::MoveBack()
{
	mPosition.z += 0.02f;
}