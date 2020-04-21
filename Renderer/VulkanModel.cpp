#include "VulkanModel.h"
#include "Renderer.h"
using namespace NAE;

VulkanModel::VulkanModel() :
	Model()
{

}

VulkanModel::~VulkanModel()
{

}

void VulkanModel::Load()
{

}

void VulkanModel::Unload()
{
	if (Loaded())
	{
		VkDevice device = Renderer::Device();

		vkDestroyBuffer(device, mVertexBuffer, nullptr);
		vkFreeMemory(device, mVertexBufferMemory, nullptr);

		vkDestroyBuffer(device, mIndexBuffer, nullptr);
		vkFreeMemory(device, mIndexBufferMemory, nullptr);
	}
}

void VulkanModel::CreateBuffers(const std::vector<SimpleVertex>& vertices, const std::vector<uint16_t>& indices)
{
	VkDevice device = Renderer::Device();

	// Vertex buffer creaion
	VkDeviceSize bufferSize = sizeof(vertices[0]) * vertices.size();

	VkBuffer stagingBuffer;
	VkDeviceMemory stagingBufferMemory;
	Renderer::CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

	void* stagingData;
	vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &stagingData);
	memcpy(stagingData, vertices.data(), (size_t)bufferSize);
	vkUnmapMemory(device, stagingBufferMemory);

	Renderer::CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, mVertexBuffer, mVertexBufferMemory);
	Renderer::CopyBuffer(stagingBuffer, mVertexBuffer, bufferSize);

	vkDestroyBuffer(device, stagingBuffer, nullptr);
	vkFreeMemory(device, stagingBufferMemory, nullptr);

	// Index Buffer creation
	bufferSize = sizeof(indices[0]) * indices.size();

	Renderer::CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_SRC_BIT, VK_MEMORY_PROPERTY_HOST_VISIBLE_BIT | VK_MEMORY_PROPERTY_HOST_COHERENT_BIT, stagingBuffer, stagingBufferMemory);

	void* indexStagingData;
	vkMapMemory(device, stagingBufferMemory, 0, bufferSize, 0, &indexStagingData);
	memcpy(indexStagingData, indices.data(), (size_t)bufferSize);
	vkUnmapMemory(device, stagingBufferMemory);

	Renderer::CreateBuffer(bufferSize, VK_BUFFER_USAGE_TRANSFER_DST_BIT | VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VK_MEMORY_PROPERTY_DEVICE_LOCAL_BIT, mIndexBuffer, mIndexBufferMemory);
	Renderer::CopyBuffer(stagingBuffer, mIndexBuffer, bufferSize);

	vkDestroyBuffer(device, stagingBuffer, nullptr);
	vkFreeMemory(device, stagingBufferMemory, nullptr);

	mLoaded = true;
	mNumIndices = indices.size();
}