#ifndef RENDERER_H
#define RENDERER_H

#include "Window.h"
#include "Camera.h"
#include "VulkanDebugCube.h"

#include <vulkan/vulkan.h>
#include <vector>
#include <array>
#include <optional>

#define GLM_ENABLE_EXPERIMENTAL
#include <glm/gtx/hash.hpp>
#include <glm/glm.hpp>


#define VK_KHR_WIN32_SURFACE_EXTENSION_NAME "VK_KHR_win32_surface"

namespace NAE
{
	// Forward Declarations
	struct DsiplaySettings;

	class Renderer
	{
	public:
		Renderer();
		~Renderer();

		void Init(const DisplaySettings& displaySettings);
		void Draw();
		void WaitForDevice();
		void HandleWindowResize(uint32_t newWidth, uint32_t newHeight);

		uint32_t GetRenderWidth();
		uint32_t GetRenderHeight();

		inline void SetCurrentCamera(Camera* camera) { mCurrentCamera = camera; };

		static void CreateBuffer(VkDeviceSize size, VkBufferUsageFlags usage, VkMemoryPropertyFlags properties, VkBuffer& buffer, VkDeviceMemory& bufferMemory);
		static void CopyBuffer(VkBuffer srcBuffer, VkBuffer dstBuffer, VkDeviceSize size);
		static VkCommandBuffer BeginSingleTimeCommands();
		static void EndSingleTimeCommands(VkCommandBuffer commandBuffer);

		static VkDevice Device() { return sDevice; };

		struct Vertex
		{
			glm::vec3 position;
			glm::vec3 color;
			glm::vec2 texCoord;

			static VkVertexInputBindingDescription GetBindingDescription();
			static std::array<VkVertexInputAttributeDescription, 3> GetAttributeDescriptions();

			bool operator==(const Vertex& other) const;
		};

	private:
		struct QueueFamilyIndices
		{
			std::optional<unsigned int> graphicsFamily;
			std::optional<unsigned int> presentFamily;

			bool IsComplete() 
			{ 
				return graphicsFamily.has_value() && presentFamily.has_value(); 
			};
		};

		struct SwapChainSupportDetails
		{
			VkSurfaceCapabilitiesKHR capabilities;
			std::vector<VkSurfaceFormatKHR> formats;
			std::vector<VkPresentModeKHR> presentModes;
		};

		struct UniformBufferObject
		{
			glm::mat4 model;
			glm::mat4 view;
			glm::mat4 proj;
		};

		void CreateInstance(const DisplaySettings& displaySettings);
		void SetupDebugMessenger();
		void CreateSurface();
		void PickPhysicalDevice();
		void CreateLogicalDevice();
		void CreateSwapChain();
		void CreateImageViews();
		void CreateRenderPass();
		void CreateDescriptorSetLayout();
		void CreateGraphicsPipeline();
		void CreateFrameBuffers();
		void CreateCommandPool();
		void CreateImage(uint32_t width, uint32_t height, VkFormat format, VkImageTiling tiling, VkImageUsageFlags usage, VkMemoryPropertyFlags properties, VkImage& image, VkDeviceMemory& imageMemory);
		VkImageView CreateImageView(VkImage image, VkFormat format, VkImageAspectFlags aspectFlags);
		void CopyBufferToImage(VkBuffer buffer, VkImage image, uint32_t width, uint32_t height);
		void CreateDepthResources();
		void CreateTextureImage();
		void CreateTextureImageView();
		void CreateTextureSampler();
		void LoadModels();
		void CreateUniformBuffers();
		void CreateDescriptorPool();
		void CreateDescriptorSets();
		void CreateCommandBuffers();
		void CreateSyncObjects();
		void TransitionImageLayout(VkImage image, VkFormat format, VkImageLayout oldLayout, VkImageLayout newLayout);

		void UpdateUniformBuffer(uint32_t currentImage);
		void RecreateSwapChain();
		void CleaUpSwapChain();

		void GetInstanceExtensions(unsigned int& enabledExtensionCount, const char** extensionNames);
		bool CheckDeviceExtensionSupport(VkPhysicalDevice device);
		bool CheckValidationLayerSupport();
		bool HasStencilComponent(VkFormat format);
		VkFormat FindSupportedFormat(const std::vector<VkFormat>& candidates, VkImageTiling tiling, VkFormatFeatureFlags features);
		VkFormat FindDepthFormat();
		void CreateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT& createInfo);
		void DestroyDebugMessenger();
		bool IsDeviceSuitable(VkPhysicalDevice device);
		QueueFamilyIndices FindQueueFamilies(VkPhysicalDevice device);
		SwapChainSupportDetails QuerySwapChainSupport(VkPhysicalDevice device);
		VkSurfaceFormatKHR ChooseSwapSurfaceFormat(const std::vector<VkSurfaceFormatKHR>& availableFormats);
		VkPresentModeKHR ChooseSwapPresentMode(const std::vector<VkPresentModeKHR>& availablePresentModes);
		VkExtent2D ChooseSwapExtent(const VkSurfaceCapabilitiesKHR& capabilities);
		VkShaderModule CreateShaderModule(const std::vector<char>& code);

		static VKAPI_ATTR VkBool32 VKAPI_CALL DebugCallback(VkDebugUtilsMessageSeverityFlagBitsEXT messageSeverity, VkDebugUtilsMessageTypeFlagsEXT messageType, const VkDebugUtilsMessengerCallbackDataEXT* pCallbackData, void* pUserData);
		static uint32_t FindMemoryType(uint32_t typeFilter, VkMemoryPropertyFlags properties);

		static VkDevice sDevice;
		static VkPhysicalDevice sPhysicalDevice;
		static VkCommandPool sCommandPool;
		static VkQueue sGraphicsQueue;

		uint32_t mRenderWidth;
		uint32_t mRenderHeight;

		Window mWindow;
		Camera* mCurrentCamera;
		VulkanDebugCube mDebugCube;

		VkInstance mInstance;
		VkQueue mPresentQueue;
		VkSurfaceKHR mSurface;
		VkSwapchainKHR mSwapChain;
		std::vector<VkImage> mSwapChainImages;
		std::vector<VkImageView> mSwapChainImageViews;
		std::vector<VkFramebuffer> mSwapChainFrameBuffers;
		VkFormat mSwapChainImageFormat;
		VkExtent2D mSwapChainExtent;
		VkRenderPass mRenderPass;
		VkDescriptorSetLayout mDescriptorSetLayout;
		VkPipelineLayout mPipelineLayout;
		VkPipeline mGraphicsPipeline;
		VkDescriptorPool mDescriptorPool;
		VkImage mTextureImage;
		VkDeviceMemory mTextureImageMemory;
		VkImageView mTextureImageView;
		VkImage mDepthImage;
		VkDeviceMemory mDepthImageMemory;
		VkImageView mDepthImageView;
		VkSampler mTextureSampler;
		std::vector<VkDescriptorSet> mDescriptorSets;
		std::vector<VkBuffer> mUniformBuffers;
		std::vector<VkDeviceMemory> mUniformBuffersMemory;
		std::vector<VkCommandBuffer> mCommandBuffers;
		std::vector<VkSemaphore> mImageAvailableSemaphores;
		std::vector<VkSemaphore> mRenderFinishedSemaphores;
		std::vector<VkFence> mInFlightFences;
		std::vector<VkFence> mImagesInFlight;
		const uint32_t mMaxFramesInFlight = 2;
		uint64_t mCurrentFrame = 0;

		bool mWindowResized;

#ifdef NDEBUG
		const bool mEnableValidationLayers = false;
#else
		const std::vector<const char*> mValidationLayers = {"VK_LAYER_LUNARG_standard_validation"};
		const std::vector<const char*> mDeviceExtensions = { VK_KHR_SWAPCHAIN_EXTENSION_NAME };
		const bool mEnableValidationLayers = true;
		VkDebugUtilsMessengerEXT mDebugMessenger;
#endif
	};
}

template<> struct std::hash<NAE::Renderer::Vertex>
{
	size_t operator()(NAE::Renderer::Vertex const& vertex) const
	{
		return ((std::hash<glm::vec3>()(vertex.position) ^
			(std::hash<glm::vec3>()(vertex.color) << 1)) >> 1) ^
			(std::hash<glm::vec2>()(vertex.texCoord) << 1);
	}
};
#endif
