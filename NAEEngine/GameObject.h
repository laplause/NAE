#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include "GameClock.h"

#define GLM_FORCE_RADIANS
#define GLM_FORCE_DEPTH_ZERO_TO_ONE
#include <glm/glm.hpp>
#include <string>

namespace NAE
{
	class GameObject
	{
	public:
		GameObject();
		virtual ~GameObject();

		inline void SetPosition(float x, float y, float z) { mPosition = glm::vec3(x, y, z); };
		inline void SetPosition(const glm::vec3& position) { mPosition = position; };
		
		inline void SetRoll(float roll) { mRotation.x = glm::radians(roll); };
		inline void SetPitch(float pitch) { mRotation.y = glm::radians(pitch); };
		inline void SetYaw(float yaw) { mRotation.z = glm::radians(yaw); };
		inline void SetRotationFromEulerAngles(float roll, float pitch, float yaw) { mRotation = glm::vec3(glm::radians(roll), glm::radians(pitch), glm::radians(yaw)); };
		inline void SetRotationFromEulerAngles(const glm::vec3& rotation) { mRotation = glm::radians(rotation); };

		inline void SetEnabled(bool enable) { mEnabled = enable; };
		inline void SetVisible(bool visible) { mVisible = visible; };

		inline const bool IsEnabled() const { return mEnabled; };
		inline const bool IsVisible() const { return mVisible; };
		inline const std::string& Name() { return mName; };

		inline const glm::vec3& GetPosition() const { return mPosition; };
		inline const glm::vec3& GetRotationAsEulerAngles() const { return mRotation; };
		const glm::mat4x4& GetTransform() const;

		virtual void Update(const GameClock& gameClock) = 0;

	protected:
		glm::vec3 mPosition;
		glm::vec3 mRotation;
		float mVelocity;

	private:
		bool mEnabled;
		bool mVisible;
		std::string mName;
	};
}
#endif
