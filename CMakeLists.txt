project("Philosophers")
cmake_minimum_required(VERSION 2.6)

include_directories ("${PROJECT_SOURCE_DIR}/src")
add_subdirectory(src)

SET(GCC_COVERAGE_COMPILE_FLAGS "-pthread")

SET( CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${GCC_COVERAGE_COMPILE_FLAGS}" )
SET( CMAKE_EXE_LINKER_FLAGS  "${CMAKE_EXE_LINKER_FLAGS} ${GCC_COVERAGE_LINK_FLAGS}" )

add_executable(app main.cpp)
target_link_libraries (app philosopher_lib)
target_link_libraries (app fork_lib)
