
add_subdirectory(dependencies)


add_executable(T3D_TEST T3D/OpenGL/OpenGLObjectTest.cpp)

target_link_libraries(T3D_TEST PUBLIC gtest_main T3D)

add_test(NAME T3D_TEST COMMAND T3D_TEST)

