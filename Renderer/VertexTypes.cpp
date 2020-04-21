#include "VertexTypes.h"
using namespace NAE;

VkVertexInputBindingDescription VulkanSimpleVertex::GetBindingDescription()
{
	VkVertexInputBindingDescription bindindDescription = {};
	bindindDescription.binding = 0;
	bindindDescription.stride = sizeof(VulkanSimpleVertex);
	bindindDescription.inputRate = VK_VERTEX_INPUT_RATE_VERTEX;

	return bindindDescription;
}

std::array<VkVertexInputAttributeDescription, 3> VulkanSimpleVertex::GetAttributeDescriptions()
{
	std::array<VkVertexInputAttributeDescription, 3> attributeDescriptions = {};
	attributeDescriptions[0].binding = 0;
	attributeDescriptions[0].location = 0;
	attributeDescriptions[0].format = VK_FORMAT_R32G32B32_SFLOAT;
	attributeDescriptions[0].offset = offsetof(VulkanSimpleVertex, position);

	attributeDescriptions[1].binding = 0;
	attributeDescriptions[1].location = 1;
	attributeDescriptions[1].format = VK_FORMAT_R32G32B32_SFLOAT;
	attributeDescriptions[1].offset = offsetof(VulkanSimpleVertex, color);

	attributeDescriptions[2].binding = 0;
	attributeDescriptions[2].location = 2;
	attributeDescriptions[2].format = VK_FORMAT_R32G32_SFLOAT;
	attributeDescriptions[2].offset = offsetof(VulkanSimpleVertex, textureCoordinates);

	return attributeDescriptions;
}