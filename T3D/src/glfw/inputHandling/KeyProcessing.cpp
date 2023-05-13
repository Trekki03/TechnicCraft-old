#include "T3D/glfw/inputHandling/KeyProcessing.hpp"

namespace t3d::glfw
{

	constexpr auto USEABLE_KEY_COUNT = 97;

	static const unsigned int glfwKeyMapping[] = {
		GLFW_KEY_SPACE,
		GLFW_KEY_COMMA,
		GLFW_KEY_MINUS,
		GLFW_KEY_PERIOD,
		GLFW_KEY_ESCAPE,
		GLFW_KEY_ENTER,
		GLFW_KEY_TAB,
		GLFW_KEY_BACKSPACE,
		GLFW_KEY_LEFT_SHIFT,
		GLFW_KEY_LEFT_CONTROL,
		GLFW_KEY_LEFT_ALT,
		GLFW_KEY_RIGHT_SHIFT,
		GLFW_KEY_RIGHT_CONTROL,
		GLFW_KEY_RIGHT_ALT,
		GLFW_KEY_RIGHT,
		GLFW_KEY_LEFT,
		GLFW_KEY_DOWN,
		GLFW_KEY_UP,
		GLFW_KEY_0,
		GLFW_KEY_1,
		GLFW_KEY_2,
		GLFW_KEY_3,
		GLFW_KEY_4,
		GLFW_KEY_5,
		GLFW_KEY_6,
		GLFW_KEY_7,
		GLFW_KEY_8,
		GLFW_KEY_9,
		GLFW_KEY_A,
		GLFW_KEY_B,
		GLFW_KEY_C,
		GLFW_KEY_D,
		GLFW_KEY_E,
		GLFW_KEY_F,
		GLFW_KEY_G,
		GLFW_KEY_H,
		GLFW_KEY_I,
		GLFW_KEY_J,
		GLFW_KEY_K,
		GLFW_KEY_L,
		GLFW_KEY_M,
		GLFW_KEY_N,
		GLFW_KEY_O,
		GLFW_KEY_P,
		GLFW_KEY_Q,
		GLFW_KEY_R,
		GLFW_KEY_S,
		GLFW_KEY_T,
		GLFW_KEY_U,
		GLFW_KEY_V,
		GLFW_KEY_W,
		GLFW_KEY_X,
		GLFW_KEY_Y,
		GLFW_KEY_Z,
		GLFW_KEY_F1,
		GLFW_KEY_F2,
		GLFW_KEY_F3,
		GLFW_KEY_F4,
		GLFW_KEY_F5,
		GLFW_KEY_F6,
		GLFW_KEY_F7,
		GLFW_KEY_F8,
		GLFW_KEY_F9,
		GLFW_KEY_F10,
		GLFW_KEY_F11,
		GLFW_KEY_F12,
		GLFW_KEY_F13,
		GLFW_KEY_F14,
		GLFW_KEY_F15,
		GLFW_KEY_F16,
		GLFW_KEY_F17,
		GLFW_KEY_F18,
		GLFW_KEY_F19,
		GLFW_KEY_F20,
		GLFW_KEY_F21,
		GLFW_KEY_F22,
		GLFW_KEY_F23,
		GLFW_KEY_F24,
		GLFW_KEY_F25
	};
	static void (*handlerFunctions[97]) (bool) = { nullptr };
	static const char* names[97] = {};

	void SetKeyEvent(KeyCode key, void (*handlerFunction)(bool keyPressed), const char* handlerName)
	{
		handlerFunctions[key] = handlerFunction;
		names[key] = handlerName;
	}

	const char* GetKeyEventName(KeyCode key)
	{
		const char* name = names[key];

		if (name == nullptr)
		{
			return "No Set";
		}
		
		return name;
	}

	void ProcessKeyInput(GLFWwindow* window)
	{
		for (int i = 0; i < USEABLE_KEY_COUNT; i++)
		{
			if (nullptr == handlerFunctions[i]) { continue; }
			int keyState = glfwGetKey(window, glfwKeyMapping[i]);

			if (GLFW_PRESS == keyState)
			{
				handlerFunctions[i](true);
			}
			else
			{
				handlerFunctions[i](false);
			}
		}
	}
}