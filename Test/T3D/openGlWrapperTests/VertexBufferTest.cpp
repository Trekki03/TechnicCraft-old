#include "openGlWrapperFixture.h"
#include <T3D/openGlWrapper/VertexBuffer.hpp>

TEST_F(T3D_OpenGlWrapperTest, VertexBufferBinding)
{
    //Creating a Vertexbuffer to Test
    float vertexData[] = {1.0f, 0.0f, 0.0f, 1.0f};
    T3D::OpenGl::VertexBuffer vb(vertexData, 4 * sizeof(float), GL_STATIC_DRAW);

    //Creating vars to store ids. vb id has to be cast, because active buffer id is signed
    auto vbID = static_cast<int32_t>(vb.GetObjectId());
    int32_t activeBufferID;

    //ID of vb and active buffer should be same when bound
    vb.Bind();
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_EQ(vbID, activeBufferID);

    //ID of vb and active buffer should NOT be same, when not bound
    vb.Unbind();
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_NE(vbID, activeBufferID);
}

TEST_F(T3D_OpenGlWrapperTest, VertexBufferData)
{
    //Creating and binding a Vertexbuffer to Test
    float vertexData[] = {1.0f, 0.0f, 0.0f, 1.0f};
    T3D::OpenGl::VertexBuffer vb(vertexData, 4 * sizeof(float), GL_STATIC_DRAW);
    vb.Bind();

    //Getting data from Vertexbuffer
    auto *bufferData = static_cast<float *>(vb.GetBufferData());

    //Testing if received data is equal to set data
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(bufferData[i], vertexData[i]);
    }
}
