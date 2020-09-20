#ifndef COMPONENT_H
#define COMPONENT_H

#include "NAEObject.h"
#include "GameClock.h"

namespace NAE
{
	class Component : public NAEObject
	{
		TYPE_DECLARATIONS(Component, NAEObject);
	public:
		Component();
		explicit Component(const std::string& name);
		virtual ~Component();

		// Since components are stored in std::vectors we use this to denote free spaces
		// in the vector instead of calling erase which will invalidate the index maps
		bool mActive;
	};
}
#endif
