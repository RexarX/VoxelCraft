#pragma once

#include "Core.h"

#include "Timestep.h"

#include "Events/Event.h"

namespace VoxelEngine
{
	class VOXELENGINE_API Layer
	{
	public:
		Layer(const std::string& name = "Layer");
		virtual ~Layer();

		virtual void OnAttach() {}
		virtual void OnDetach() {}
		virtual void OnUpdate(const Timestep ts) {}
		virtual void OnEvent(Event& event) {}

		virtual void Draw() {}

		inline const std::string& GetName() const { return m_Name; }

	protected:
		std::string m_Name;
	};
}