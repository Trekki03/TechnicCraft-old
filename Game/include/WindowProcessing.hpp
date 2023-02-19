#ifndef TECHNICCRAFT_WINDOWPROCESSING_HPP
#define TECHNICCRAFT_WINDOWPROCESSING_HPP

#include <GLFW/glfw3.h>

namespace Game
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height);
    void processInput(GLFWwindow* window);
    void mouse_callback(GLFWwindow* window, double xPos, double yPos);
    void scroll_callback(GLFWwindow* window, double xOffset, double yOffset);
}
#endif //TECHNICCRAFT_WINDOWPROCESSING_HPP
