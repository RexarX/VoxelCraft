#pragma once

#include "Core.h"

#include "Window.h"

#include "LayerStack.h"

#include "Timestep.h"
#include "Utils/Timer.h"

#include "Events/Event.h"
#include "Events/ApplicationEvent.h"

namespace VoxelEngine
{
	class VOXELENGINE_API Application {
	public:
		Application();
		virtual ~Application();

		void Run();

		void OnEvent(Event& e);

		void PushLayer(Layer* layer);
		void PushOverlay(Layer* layer);

		inline Timestep GetDeltaTime() { return m_DeltaTime; }

		inline Window& GetWindow() { return *m_Window; }

		inline static Application& Get() { return *s_Instance; }
	
	private:
		bool OnWindowClose(WindowCloseEvent& e);

	private:
		std::unique_ptr<Window> m_Window;

		LayerStack m_LayerStack;

		Timestep m_DeltaTime;

		double m_FramerateLimit = 0.0;

		bool m_Running = true;

		static Application* s_Instance;
	};

	Application* CreateApplication();
}