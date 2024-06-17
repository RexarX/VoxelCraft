#pragma once

#include "RenderStart.h"

#include "Camera.h"

#include "Shader.h"

#include "Texture.h"

#include "Chunk.h"

namespace VoxelEngine
{
	class Renderer
	{
	public:
		static void Init();

		static void Shutdown();

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		static void OnWindowResize(const uint32_t width, const uint32_t height);

		static void BeginScene(const Camera& camera);
		static void EndScene();

		static void DrawTriangle(const glm::vec3& position, const glm::vec3& rotation, const glm::vec3& size);

		static void DrawCube(const glm::vec3& position, const glm::vec3& rotation,
												 const glm::vec3& size, const std::shared_ptr<Texture>& texture);

		static void DrawCubesInstanced(const std::vector<glm::mat3>& cubes, const std::shared_ptr<Texture>& texture);

		static void DrawLine(const glm::vec3& position, const glm::vec3& rotation,
												 const float lenght);

		static void DrawSkybox(const std::shared_ptr<Texture>& texture);

		static void SetGenerateMipmaps(const bool value) { Texture::SetGenerateMipmaps(value); }
		static void SetAnisoLevel(const float value) { Texture::SetAnisoLevel(value); }

	private:
		static void DrawChunk(const Chunk& chunk);

	private:
		struct SceneData
		{
      glm::mat4 ProjectionViewMatrix;
			glm::mat4 TransformMatrix;
		};

		static std::unique_ptr<SceneData> s_SceneData;
	};
}