#include "T3D/glfw/windowHandling/WindowProcessing.hpp"

namespace t3d::glfw
{
    void framebuffer_size_callback(GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    }
}