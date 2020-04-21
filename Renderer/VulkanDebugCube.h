#ifndef VULKANDEBUGCUBE_H
#define VULKANDEBUGCUBE_H

#include  "VulkanModel.h"

namespace NAE
{
	class VulkanDebugCube : public VulkanModel
	{
	public:
		VulkanDebugCube();
		virtual ~VulkanDebugCube();

		virtual void Load();
	};
}
#endif
