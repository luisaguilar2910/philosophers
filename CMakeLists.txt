project("Philosophers")
cmake_minimum_required(VERSION 2.6)

include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

add_executable(app main.cpp)
target_link_libraries (app philosopher_lib)
target_link_libraries (app fork_lib)
