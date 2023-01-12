#ifndef TECHNICCRAFT_OPENGLWRAPPERFIXTURE_H
#define TECHNICCRAFT_OPENGLWRAPPERFIXTURE_H

#include <gtest/gtest.h>
#include <glad/glad.h>
#include <GLFW/glfw3.h>

class T3D_OpenWrapperTest : public ::testing::Test
{
protected:
    GLFWwindow* window;
    void SetUp() override;
    void TearDown() override;
};

#endif //TECHNICCRAFT_OPENGLWRAPPERFIXTURE_H
