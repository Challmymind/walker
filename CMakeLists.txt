cmake_minimum_required(VERSION 3.19.0)

# For clangd autocompletion.
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

# All targets need this directory.
include_directories(inc)

# Add lining commands
add_compile_options(-pthread)
add_link_options(-lpthread)

# Tests subdirectory.
add_subdirectory(tests build_test)

# Main project.
project(walker)
add_executable(walker main.cpp)

# Run tests.
include(CTest)
add_test(NAME GMAP_TEST COMMAND gmap_test)
