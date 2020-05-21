#ifndef CAMERA_H
#define CAMERA_H

#include "GameObject.h"

namespace NAE
{

	class Camera : public GameObject
	{
		TYPE_DECLARATIONS(Camera, GameObject);
	public:
		Camera();
		virtual ~Camera();

		const glm::mat4x4& ViewMatrix() const;
		inline const glm::mat4x4& ProjectionMatrix() const { return mProjectionMatrix; };
		inline const glm::mat4x4& ViewProjectionMatrix() const { return mProjectionMatrix * ViewMatrix(); };

		virtual void Update(const GameClock& gameClock) = 0;

	protected:
		glm::mat4x4 mProjectionMatrix;
	};
}
#endif
