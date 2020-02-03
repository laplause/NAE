#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <glm/glm.hpp>

class GameClock;

class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	inline void SetPosition(float x, float y, float z);
	inline void SetPosition(glm::vec3& position);
	inline void SetEnabled(bool enable);
	inline void SetVisible(bool visible);

	inline const bool isEnabled() const;
	inline const bool isVisible() const;
	inline const glm::vec3& GetPosition() const;

	virtual void Update(const GameClock& gameClock);

protected:
	glm::vec3 mPosition;
	float mVelocity;

private:
	bool mEnabled;
	bool mVisible;
};
#endif
