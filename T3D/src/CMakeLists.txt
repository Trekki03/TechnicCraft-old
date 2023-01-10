include_directories(${TechnicCraft_SOURCE_DIR}/T3D/include)

add_library(
        T3D
        ${TechnicCraft_SOURCE_DIR}/T3D/dependencies/glad/src/glad.c
        openGl/VertexBuffer.cpp
)

find_package(OpenGL REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIRS}
        "${TechnicCraft_SOURCE_DIR}/T3D/dependencies/glfw/include"
        "${TechnicCraft_SOURCE_DIR}/T3D/dependencies/glad/include"
        "${TechnicCraft_SOURCE_DIR}/T3D/dependencies/stb"
        "${TechnicCraft_SOURCE_DIR}/T3D/dependencies/glm"
)

target_link_libraries(
        T3D
        ${OPENGL_LIBRARIES}
        "${TechnicCraft_SOURCE_DIR}/T3D/dependencies/glfw/lib/libglfw3.a"
)

#add mac specific libraries
if(APPLE)
    find_library(COCOA_LIBRARY Cocoa)
    find_library(IOKIT_LIBRARY IOKit)
    target_link_libraries(
            T3D
            ${COCOA_LIBRARY}
            ${IOKIT_LIBRARY}
    )
endif()
