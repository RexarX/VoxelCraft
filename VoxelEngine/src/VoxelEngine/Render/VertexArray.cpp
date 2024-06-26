#include "VertexArray.h"
#include "Renderer.h"

#include "vepch.h"

#include "Platform/OpenGL/OpenGLVertexArray.h"
#include "Platform/Vulkan/VulkanVertexArray.h"

namespace VoxelEngine
{
	std::unique_ptr<VertexArray> VertexArray::Create(const char* name)
	{
		switch (Renderer::GetAPI())
		{
		case RendererAPI::API::None:    VE_CORE_ASSERT(false, "RendererAPI::None is currently not supported!"); return nullptr;
		case RendererAPI::API::OpenGL:  return std::make_unique<OpenGLVertexArray>(name);
		case RendererAPI::API::Vulkan:  return std::make_unique<VulkanVertexArray>(name);
		}

		VE_CORE_ASSERT(false, "Unknown RendererAPI!");
		return nullptr;
	}
}