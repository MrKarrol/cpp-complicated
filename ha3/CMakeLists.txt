# CMakeList.txt : CMake project for ha3, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)

project ("ha3")

# Add source to this project's executable.
add_executable (ha3 "ha3.cpp"  "matrix.h" "matrix.cpp")

# TODO: Add tests and install targets if needed.
