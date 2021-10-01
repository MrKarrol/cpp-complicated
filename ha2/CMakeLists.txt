# CMakeList.txt : CMake project for ha2, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ha2")

# Add source to this project's executable.
add_executable (ha2 "ha2.cpp"  "templates.h" "count.h")

# TODO: Add tests and install targets if needed.
