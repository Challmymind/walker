cmake_minimum_required(VERSION 3.19.0)

# For clangd autocompletion.
set(CMAKE_EXPORT_COMPILE_COMMANDS On)

# Define project.
project(walker)

# Add submodule
add_subdirectory(extern/escape-tui)

# Create executable.
add_executable(${PROJECT_NAME} main.cpp)

# Get source files.
file(GLOB_RECURSE WALKER_SOURCES src/*.cpp)

# Include source files into executable.
target_sources(${PROJECT_NAME} PRIVATE ${WALKER_SOURCES})

# Link target with libraries.
target_link_libraries(${PROJECT_NAME} PRIVATE 
	escape-tui
	pthread
	)

# Add include directory.
# Private so only this executable will poses it's contents.
target_include_directories(${PROJECT_NAME} PRIVATE inc)
