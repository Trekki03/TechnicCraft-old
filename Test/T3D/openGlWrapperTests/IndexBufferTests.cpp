#include "openGlWrapperFixture.h"
#include "T3D/openGlWrapper/IndexBuffer.hpp"

TEST_F(T3D_OpenGlWrapperTest, IndexBufferBinding)
{
    //Creating a IndexBuffer to Test
    uint32_t indexData[] = {1, 5, 0, 56456};
    t3d::openGl::IndexBuffer ib(indexData, 4 * sizeof(uint32_t), GL_STATIC_DRAW);

    //Creating vars to store ids. ib id has to be cast, because active buffer id is signed
    auto ibID = static_cast<int32_t>(ib.GetObjectId());
    int32_t activeBufferID;

    //ID of ib and active buffer should be same when bound
    ib.Bind();
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_EQ(ibID, activeBufferID);

    //ID of ib and active buffer should NOT be same, when not bound
    ib.Unbind();
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_NE(ibID, activeBufferID);
}

TEST_F(T3D_OpenGlWrapperTest, IndexBufferBufferData)
{
    //Creating and binding a IndexBuffer to Test
    uint32_t indexData[] = {1, 5, 0, 56456};
    t3d::openGl::IndexBuffer ib(indexData, 4 * sizeof(uint32_t), GL_STATIC_DRAW);
    ib.Bind();

    //Getting data from IndexBuffer
    auto *bufferData = static_cast<uint32_t *>(ib.GetBufferData());

    //Testing if received data is equal to set data
    for (int i = 0; i < 4; i++)
    {
        EXPECT_EQ(bufferData[i], indexData[i]);
    }
}
