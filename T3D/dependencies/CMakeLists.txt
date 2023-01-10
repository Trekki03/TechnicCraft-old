# File created with help of https://jonathanhamberg.com/post/2019-01-27-cmake-dependencies-fetch-content/

include(FetchContent)

# GLM
FetchContent_Declare(
        glm
        GIT_REPOSITORY https://github.com/g-truc/glm.git
        SOURCE_DIR ${CMAKE_BINARY_DIR}/T3D/dependencies/glm
)

FetchContent_GetProperties(glm)
if(NOT glm_POPULATED)
    FetchContent_Populate(glm)
endif()

set(glm_DIR ${CMAKE_BINARY_DIR}/T3D/dependencies/glm CACHE INTERNAL "")

# -----------------------------------------------------------------------
# STB
FetchContent_Declare(
        stb
        GIT_REPOSITORY https://github.com/nothings/stb.git
        SOURCE_DIR ${CMAKE_BINARY_DIR}/T3D/dependencies/stb
)

FetchContent_GetProperties(stb)
if(NOT stb_POPULATED)
    FetchContent_Populate(stb)
endif()

set(stb_DIR ${CMAKE_BINARY_DIR}/T3D/dependencies/stb CACHE INTERNAL "")

# -----------------------------------------------------------------------
#GLFW
FetchContent_Declare(
        glfw
        GIT_REPOSITORY https://github.com/glfw/glfw
)

FetchContent_GetProperties(glfw)
if(NOT glfw_POPULATED)
    FetchContent_Populate(glfw)

    set(GLFW_BUILD_EXAMPLES OFF CACHE INTERNAL "Build the GLFW example programs")
    set(GLFW_BUILD_TESTS OFF CACHE INTERNAL "Build the GLFW test programs")
    set(GLFW_BUILD_DOCS OFF CACHE INTERNAL "Build the GLFW documentation")
    set(GLFW_INSTALL OFF CACHE INTERNAL "Generate installation target")

    add_subdirectory(${glfw_SOURCE_DIR} ${glfw_BINARY_DIR})
endif()

# -----------------------------------------------------------------------
#GLAD
FetchContent_Declare(
        glad
        GIT_REPOSITORY https://github.com/Dav1dde/glad.git
)

FetchContent_GetProperties(glad)
if(NOT glad_POPULATED)
    FetchContent_Populate(glad)
    set(GLAD_PROFILE "core" CACHE STRING "OpenGL profile")
    set(GLAD_API "gl=" CACHE STRING "API type/version pairs, like \"gl=3.2,gles=\", no version means latest")
    set(GLAD_GENERATOR "c" CACHE STRING "Language to generate the binding for")
    add_subdirectory(${glad_SOURCE_DIR} ${glad_BINARY_DIR})
endif()
