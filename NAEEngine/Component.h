#ifndef COMPONENT_H
#define COMPONENT_H

#include "Type.h"

namespace NAE
{
	class Component : public Type
	{
		TYPE_DECLARATIONS(Component, Type);
	public:
		Component();
		virtual ~Component();

		inline const bool Enabled() const { return mEnabled; };

		bool mEnabled;
	};
}
#endif
