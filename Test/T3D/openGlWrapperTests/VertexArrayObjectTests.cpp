#include "openGlWrapperFixture.h"
#include "T3D/openGlWrappper/VertexArrayObject.hpp"

TEST_F(T3D_OpenGlWrapperTest, VertexArrayObjectBinding)
{
    //Create a VertexArrayObject to test
    T3D::OpenGl::VertexArrayObject vao {};

    //Creating vars to store ids. vao id has to be cast, because active vao id is signed
    auto vaoID = static_cast<int32_t>(vao.GetObjectId());
    int32_t activeVaoID;

    //ID of vao and active vao should be same when bound
    vao.Bind();
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &activeVaoID);
    EXPECT_EQ(vaoID, activeVaoID);

    //ID of vao and active vao should not be same when unbound
    vao.Unbind();
    glGetIntegerv(GL_VERTEX_ARRAY_BINDING, &activeVaoID);
    EXPECT_NE(vaoID, activeVaoID);
}

TEST_F(T3D_OpenGlWrapperTest, VertexArrayObjectIndexBuffer)
{
    //Create a VertexArrayObject to test
    T3D::OpenGl::VertexArrayObject vao {};

    //Create an index buffer and add to VAO
    uint32_t indexData[] = {1, 2, 3, 4};
    T3D::OpenGl::IndexBuffer ib(indexData, 4*sizeof(uint32_t), GL_STATIC_DRAW);
    vao.SetIndexBuffer(ib);

    //Test if vao has saved correct Index Count
    EXPECT_EQ(vao.GetIndexCount(), 4);

    //Creating vars to store ids. ib id has to be cast, because active buffer id is signed
    auto ibID = static_cast<int32_t>(ib.GetObjectId());
    int32_t activeBufferID;

    //ID of ib and active ib should be same, if vao is bound
    vao.Bind();
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_EQ(ibID, activeBufferID);

    //ID of ib and active ib should not be same, if vao is unbound
    vao.Unbind();
    glGetIntegerv(GL_ELEMENT_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_NE(ibID, activeBufferID);
}

TEST_F(T3D_OpenGlWrapperTest, VertexArrayObjectVertexBuffer)
{
    //Create a VertexArrayObject to test
    T3D::OpenGl::VertexArrayObject vao {};

    //Create an index buffer and add to VAO
    float vertexData[] = {1.0f, 2.0f, 3.0f, 4.0f, 5.0f};
    T3D::OpenGl::VertexBuffer  vb(vertexData, 5*sizeof(float), GL_STATIC_DRAW);
    vao.SetVertexBuffer(vb);

    //Test if vao has saved correct Vertex Count
    EXPECT_EQ(vao.GetVertexCount(), 5);

    //Creating vars to store ids. ib id has to be cast, because active buffer id is signed
    auto vbID = static_cast<int32_t>(vb.GetObjectId());
    int32_t activeBufferID;

    //ID of ib and active ib should be same, if vao is bound
    vao.Bind();
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_EQ(vbID, activeBufferID);

    //ID of ib and active ib should not be same, if vao is unbound
    vao.Unbind();
    glGetIntegerv(GL_ARRAY_BUFFER_BINDING, &activeBufferID);
    EXPECT_NE(vbID, activeBufferID);
}