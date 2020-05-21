#ifndef PERSPECTIVECAMERA_H
#define PERSPECTIVECAMERA_H

#include "Camera.h"
#include "glm/glm.hpp"
#include "glm/gtc/matrix_transform.hpp"

namespace NAE
{
	class PerspectiveCamera : public Camera
	{
		TYPE_DECLARATIONS(PerspectiveCamera, Camera);
	public:
		PerspectiveCamera();
		PerspectiveCamera(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);
		virtual ~PerspectiveCamera();

		virtual void Update(const GameClock& gameClock);

		void SetCameraParameters(float fieldOfView, float aspectRatio, float nearPlaneDistance, float farPlaneDistance);

		void MoveForward();
		void MoveBack();

		static constexpr float sDefaultFieldOfView = glm::radians(45.0f);
		static constexpr float sDefaultNearPlaneDistance = 0.1f;
		static constexpr float sDefaultFarPlaneDistance = 10.0f;

	protected:
		float mFieldOfView;
		float mAspectRatio;
		float mNearPlaneDistance;
		float mFarPlaneDistance;
	};
}
#endif
