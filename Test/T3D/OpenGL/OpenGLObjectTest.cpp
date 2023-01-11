#include <gtest/gtest.h>
#include "openGlObjects/VertexBuffer.hpp"
#include <glad/glad.h>
#include "GLFW/glfw3.h"
#include <iostream>

class T3D_OpenGlTEST : public ::testing::Test
{
protected:

    //Creating an OpenGL Context via glfw for tests to use
    GLFWwindow* window;
    void SetUp() override
    {
        /* Initialize the library */
        if (!glfwInit())
            EXPECT_TRUE(false);

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

    void TearDown() override
    {
        glfwTerminate();
    }
};


TEST_F(T3D_OpenGlTEST, VertexBufferBinding)
{
    //Creating a Vertexbuffer to Test
    #float vertexData[] = { 1.0f, 0.0f, 0.0f, 1.0f};
    #T3D::VertexBuffer vb(vertexData, 4 * sizeof(float), GL_STATIC_DRAW);

    //Creating vars to store ids. vb id has to be casted, because active buffer id is signed
    #auto vbID = static_cast<int32_t>(vb.GetObjectId());
    #int32_t activeBufferID;

    //ID of vb and active buffer should be same when bound
    #vb.Bind();
    #glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    #EXPECT_EQ(vbID, activeBufferID);

    //ID of vb and active buffer should NOT be same, when not bound
    #vb.Unbind();
    #glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    #EXPECT_NE(vbID, activeBufferID);
    EXPECT_TRUE(true);
}
