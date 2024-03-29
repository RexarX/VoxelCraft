#pragma once

#include "Core.h"

#include "MouseButtonCodes.h"
#include "KeyCodes.h"

namespace VoxelEngine
{
	class VOXELENGINE_API Input
	{
	public:
		inline static bool IsKeyPressed(const KeyCode keycode) { return s_Instance->IsKeyPressedImpl(keycode); }

		inline static bool IsMouseButtonPressed(const KeyCode button) { return s_Instance->IsMouseButtonPressedImpl(button); }
		inline static std::pair<float, float> GetMousePosition() { return s_Instance->GetMousePositionImpl(); }
		inline static float GetMouseX() { return s_Instance->GetMouseXImpl(); }
		inline static float GetMouseY() { return s_Instance->GetMouseYImpl(); }

	protected:
		virtual bool IsKeyPressedImpl(const KeyCode keycode) = 0;

		virtual bool IsMouseButtonPressedImpl(const MouseCode button) = 0;
		virtual std::pair<float, float> GetMousePositionImpl() = 0;
		virtual float GetMouseXImpl() = 0;
		virtual float GetMouseYImpl() = 0;

	private:
		static std::unique_ptr<Input> s_Instance;
	};
}