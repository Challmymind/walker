cmake_minimum_required(VERSION 3.19.0)

set(CMAKE_CXX_COMPILER g++)

# Include tests.

# gmap test.
project(gmap_test)
add_executable(gmap_test gmap_test.cpp
	../src/gmap.cpp
	)

project(polling)
add_executable(polling polling.cpp
	../src/gmap.cpp
	../src/game.cpp
	../src/launcher.cpp
	../src/gterminal.cpp
	)
