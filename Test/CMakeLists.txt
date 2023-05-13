
add_subdirectory(dependencies)


add_executable(OpenGlWrapperTests
        T3D/openGlWrapperTests/openGlWrapperFixture.h
        T3D/openGlWrapperTests/OpenGlWrapperFixture.cpp
        T3D/openGlWrapperTests/VertexBufferTest.cpp
        T3D/openGlWrapperTests/IndexBufferTests.cpp
        T3D/openGlWrapperTests/VertexArrayObjectTests.cpp
        T3D/openGlWrapperTests/Textur2DTests.cpp
        T3D/openGlWrapperTests/ShaderProgramTest.cpp
        )

add_executable(OpenGlRenderTests
        T3D/OpenGlRenderTests/CameraTests.cpp
)
add_custom_target(
        copy-files-test ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${TechnicCraft_SOURCE_DIR}/Test/res
        ${CMAKE_BINARY_DIR}/Test/res
)
add_dependencies(T3D copy-files-test)


target_link_libraries(OpenGlWrapperTests PUBLIC gtest_main T3D)
target_link_libraries(OpenGlRenderTests PUBLIC gtest_main T3D)

add_test(NAME OpenGlWrapperTests COMMAND OpenGlWrapperTests)
add_test(NAME OpenGlRenderTests COMMAND OpenGlRenderTests)

