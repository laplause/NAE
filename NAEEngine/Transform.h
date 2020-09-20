#pragma once

#include "Component.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>

namespace NAE
{
	class Transform : public Component
	{
		TYPE_DECLARATIONS(Transform, Component);
	public:
		Transform();
		Transform(const glm::vec3& position, const glm::vec3& rotation, const float& velocity);
		virtual ~Transform();

		inline void SetPosition(float x, float y, float z) { mPosition = glm::vec3(x, y, z); };
		inline void SetPosition(const glm::vec3& position) { mPosition = position; };

		inline void SetRoll(float roll) { mRotation.x = glm::radians(roll); };
		inline void SetPitch(float pitch) { mRotation.y = glm::radians(pitch); };
		inline void SetYaw(float yaw) { mRotation.z = glm::radians(yaw); };
		inline void SetRotationFromEulerAngles(float roll, float pitch, float yaw) { mRotation = glm::vec3(glm::radians(roll), glm::radians(pitch), glm::radians(yaw)); };
		inline void SetRotationFromEulerAngles(const glm::vec3& rotation) { mRotation = glm::radians(rotation); };

		inline void SetVelocity(const float velocity) { mVelocity = velocity; };

		inline const glm::vec3& GetPosition() const { return mPosition; };
		inline const glm::vec3& GetRotationAsEulerAngles() const { return mRotation; };
		const glm::mat4x4& GetTransform() const;

	protected:
		glm::vec3 mPosition;
		glm::vec3 mRotation;
		float mVelocity;
	};
}