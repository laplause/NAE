#ifndef NAEOBJECT_H
#define NAEOBJECT_H

#include "Type.h"

#include <string>

namespace NAE
{
	class NAEObject : public Type
	{
		TYPE_DECLARATIONS(NAEObject, Type);
	public:
		explicit NAEObject(const std::string& name);
		virtual ~NAEObject();

		inline const std::string& Name() { return mName; };

	private:
		std::string mName;
	};
}
#endif
