#ifndef VERTEXTYPES_H
#define VERTEXTYPES_H

#include <glm/glm.hpp>
#include <vulkan/vulkan.h>

#include <array>

namespace NAE
{
	// BASE TYPES
	struct SimpleVertex
	{
		glm::vec3 position;
		glm::vec3 color;
		glm::vec2 textureCoordinates;
	};

	// VULKAN TYPES
	struct VulkanSimpleVertex : public SimpleVertex
	{
		static VkVertexInputBindingDescription GetBindingDescription();
		static std::array<VkVertexInputAttributeDescription, 3> GetAttributeDescriptions();
	};
}
#endif
