#ifndef ENTITY_H
#define ENTITY_H

#include "NAEObject.h"

namespace NAE
{
	class Entity : public NAEObject
	{
		TYPE_DECLARATIONS(Entity, NAEObject);
	public:
		Entity();
		explicit Entity(const std::string& name);
		virtual ~Entity();

		inline const uint32_t Id() { return mId; };

	protected:
		static uint32_t sNextGameObjectId;

	private:
		uint32_t mId;
	};
}
#endif