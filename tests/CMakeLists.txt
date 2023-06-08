cmake_minimum_required(VERSION 3.19.0)

# Include tests.

# gmap test.
project(gmap_test)
add_executable(gmap_test gmap_test.cpp
	../src/gmap.cpp
	)
