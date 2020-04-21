#ifndef VULKANMODEL_H
#define VULKANMODEL_H

#include "Model.h"
#include "VertexTypes.h"

#include <vector>

namespace NAE
{
	class VulkanModel : public Model
	{
	public:
		VulkanModel();
		virtual ~VulkanModel();

		virtual void Load();
		virtual void Unload();

		inline const VkBuffer VertexBuffer() const { return mVertexBuffer; };
		inline const VkBuffer IndexBuffer() const { return mIndexBuffer; };

	protected:
		void CreateBuffers(const std::vector<SimpleVertex>& vertices, const std::vector<uint16_t>& indices);

	private:

		VkBuffer mVertexBuffer;
		VkDeviceMemory mVertexBufferMemory;
		VkBuffer mIndexBuffer;
		VkDeviceMemory mIndexBufferMemory;
	};
}
#endif
