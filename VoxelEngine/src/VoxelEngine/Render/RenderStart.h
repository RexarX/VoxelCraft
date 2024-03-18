#pragma once

#include "RendererAPI.h"

namespace VoxelEngine
{
	class RenderCommand
	{
	public:
		inline static void Init()
		{
			s_RendererAPI->Init();
		}

		static void SetViewport(const uint32_t& x, const uint32_t& y, const uint32_t& width, const uint32_t& height)
		{
			s_RendererAPI->SetViewport(x, y, width, height);
		}

		inline static void SetClearColor(const glm::vec4& color)
		{
			s_RendererAPI->SetClearColor(color);
		}

		inline static void Clear()
		{
			s_RendererAPI->Clear();
		}

		inline static void DrawIndexed(const std::shared_ptr<VertexArray>& vertexArray)
		{
			s_RendererAPI->DrawIndexed(vertexArray);
		}

	private:
		static std::unique_ptr<RendererAPI> s_RendererAPI;
	};
}