#include "openGlWrapperFixture.h"
#include "T3D/openGlWrapper/Texture2D.hpp"

TEST_F(T3D_OpenGlWrapperTest, Texture2DBinding)
{
    // Creating a Texture. Path relative to ${CMAKE_BINARY_DIR}/Test
    const char* texPath = "Test/res/img/TextureTest.jpg";
    T3D::OpenGl::Texture2D texture(texPath, GL_RGB, GL_RGB, GL_REPEAT, GL_REPEAT, GL_NEAREST, GL_NEAREST, false);

    // Creating vars to store ids. textureID has to be cast, because activeTextureID is signed
    auto textureID = static_cast<int32_t>(texture.GetObjectId());
    int32_t activeTextureID;

    // Test Binding
    texture.Bind();
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &activeTextureID);
    EXPECT_EQ(textureID, activeTextureID);

    // Test Unbinding
    texture.Unbind();
    glGetIntegerv(GL_TEXTURE_BINDING_2D, &activeTextureID);
    EXPECT_NE(textureID, activeTextureID);
}
