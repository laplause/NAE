#ifndef COMMAND_H
#define COMMAND_H

#include "Type.h"

namespace NAE
{
	class Command : public Type
	{
		TYPE_DECLARATIONS(Command, Type);
	public:
		Command();
		virtual ~Command();

		virtual void Execute() = 0;
	};
}
#endif
