add_subdirectory(src)

add_custom_target(
        copy-files ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory
        ${TechnicCraft_SOURCE_DIR}/Game/res
        ${CMAKE_BINARY_DIR}/res
)
add_dependencies(Game copy-files)