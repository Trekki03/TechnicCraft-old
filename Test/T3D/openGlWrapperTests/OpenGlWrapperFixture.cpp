#include "openGlWrapperFixture.h"

void T3D_OpenWrapperTest::SetUp()
{
    /* Initialize the library */
    if (!glfwInit())
    {
        EXPECT_TRUE(false);
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    #ifdef __APPLE__
        glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // uncomment this statement to fix compilation on OS X
    #endif


    /* Create a windowed mode window and its OpenGL context */
    window = glfwCreateWindow(640, 480, "OPENGL Test Fixture", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        EXPECT_TRUE(false);
    }

    /* Make the window's context current */
    glfwMakeContextCurrent(window);
    gladLoadGL();
}

void T3D_OpenWrapperTest::TearDown()
{
    glfwTerminate();
}

