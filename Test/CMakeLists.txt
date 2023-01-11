
add_subdirectory(dependencies)
add_executable(Test ExampleTest.cpp)
target_link_libraries(Test PUBLIC gtest_main)

add_test(NAME Test COMMAND Test)