#include "VulkanDebugCube.h"
using namespace NAE;

VulkanDebugCube::VulkanDebugCube() :
	VulkanModel()
{
}

VulkanDebugCube::~VulkanDebugCube()
{
}

void VulkanDebugCube::Load()
{
	// position color texture coordinate
	// {}		{}	  [}
	SimpleVertex vertexData[] = {
		{{-1.0f, 1.0f, 1.0f},	{0, 0, 0},			{0, 0}},
		{{1.0f, 1.0f, 1.0f},	{0, 0, 1.0f},		{0, 0}},
		{{-1.0f, -1.0f, 1.0f},	{0, 1.0f, 0},		{0, 0}},
		{{1.0f, -1.0f, 1.0f},	{0, 1.0f, 1.0f},	{0, 0}},
		{{-1.0f, 1.0f, -1.0f},	{1.0f, 0, 0},		{0, 0}},
		{{1.0f, 1.0f, -1.0f},	{1.0f, 0, 1.0f},	{0, 0}},
		{{-1.0f, -1.0f, -1.0f},	{1.0f, 1.0f, 0},	{0, 0}},
		{{1.0f, -1.0f, -1.0f},	{1.0f, 1.0f, 1.0f},	{0, 0}}
	};

	// CCW
	uint16_t indexData[] = {
		// Front Face
		0, 2, 1,
		1, 2, 3,
		// Left Face
		4, 6, 0,
		0, 6, 2,
		// Right Face
		1, 3, 5,
		5, 3, 7,
		// Top Face
		4, 0, 5,
		5, 0, 1,
		// Bottom Face
		2, 6, 3,
		3, 6, 7,
		// Back Face
		5, 7, 4,
		4, 7, 6
	};

	std::vector<uint16_t> indices(std::begin(indexData), std::end(indexData));
	std::vector<SimpleVertex> vertices(std::begin(vertexData), std::end(vertexData));

	CreateBuffers(vertices, indices);
}
