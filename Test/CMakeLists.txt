
add_subdirectory(dependencies)


add_executable(T3D_TEST
        T3D/openGlWrapperTests/openGlWrapperFixture.h
        T3D/openGlWrapperTests/OpenGlWrapperFixture.cpp
        T3D/openGlWrapperTests/VertexBufferTest.cpp
        T3D/openGlWrapperTests/IndexBufferTests.cpp
        T3D/openGlWrapperTests/VertexArrayObjectTests.cpp)

target_link_libraries(T3D_TEST PUBLIC gtest_main T3D)

add_test(NAME T3D_TEST COMMAND T3D_TEST)

