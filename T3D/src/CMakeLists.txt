add_library(
        T3D
        openGlWrapper/VertexBuffer.cpp
        openGlWrapper/IndexBuffer.cpp
        openGlWrapper/VertexArrayObject.cpp
        openGlWrapper/Texture2D.cpp
        openGlWrapper/ShaderProgram.cpp
        util/FileIO.cpp
        openGlRender/openGlCamera/Camera.cpp
        openGlRender/openGlCamera/CameraController.cpp
        glfw/inputHandling/KeyProcessing.cpp 
        glfw/windowHandling/windowProcessing.cpp
)

target_include_directories(
        T3D PUBLIC
        ${TechnicCraft_SOURCE_DIR}/T3D/include
        ${OPENGL_INCLUDE_DIRS}
        ${glm_DIR}
        ${stb_DIR})

find_package(OpenGL REQUIRED)


target_link_libraries(
        T3D PUBLIC
        ${OPENGL_LIBRARIES}
        glad
        glfw
)

#add mac specific libraries
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    target_link_libraries(
            T3D PUBLIC
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
    )
endif()
