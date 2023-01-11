include_directories(T3D ${TechnicCraft_SOURCE_DIR}/T3D/include)

add_library(
        T3D
        openGl/VertexBuffer.cpp

)

target_include_directories(T3D PUBLIC ${TechnicCraft_SOURCE_DIR}/T3D/include)

find_package(OpenGL REQUIRED)

include_directories(
        ${OPENGL_INCLUDE_DIRS}
        ${glm_DIR}
        ${stb_DIR}
)

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
