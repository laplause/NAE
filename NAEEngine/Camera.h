#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

namespace NAE
{

	class Camera : public GameObject
	{
	public:
		Camera();
		virtual ~Camera();

		inline const glm::mat4x4& ViewMatrix();
		inline const glm::mat4x4& ProjectionMatrix();
		inline const glm::mat4x4& ViewProjectionMatrix();

		virtual void Update(const GameClock& gameClock) = 0;

	protected:
		glm::mat4x4 mViewMatrix;
		glm::mat4x4 mProjectionMatrix;
	};
}
#endif
