#pragma once

#include "RenderStart.h"

#include "Camera.h"

#include "Shader.h"

#include "Texture.h"

#include "Frustum.h"

namespace VoxelEngine
{
	class Renderer
	{
	public:
		static void Init();

		static void Shutdown();

		static void BeginScene(const Camera& camera);
		static void EndScene();

		static void OnWindowResize(const uint32_t width, const uint32_t height);

		static void Submit(glm::mat4& transform);

		inline static RendererAPI::API GetAPI() { return RendererAPI::GetAPI(); }

		static void DrawCube(const glm::vec3& position, const glm::vec3& rotation,
			const glm::vec3& size, const std::shared_ptr<Texture>& texture);

		//convert data and then call RenderLine
		static void DrawLine(const glm::vec3& position, const glm::vec3& rotation, const float lenght);
		static void DrawLine(const glm::vec3& originPosition, const glm::vec3& endPosition); 

	private:

		static void RenderLine(const const glm::vec3& position, const glm::vec3& rotation, const float lenght); //sets up opengl and matrices then draws

		struct SceneData
		{
			glm::mat4 ViewProjectionMatrix;
			glm::mat4 ProjectionMatrix;
			glm::mat4 ViewMatrix;
		};

		static std::unique_ptr<SceneData> s_SceneData;
	};
}