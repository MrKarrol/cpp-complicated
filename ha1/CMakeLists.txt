# CMakeList.txt : CMake project for ha1, include source and define
# project specific logic here.
#
cmake_minimum_required (VERSION 3.8)
set(CMAKE_CXX_STANDARD 20)
project ("ha1")

# Add source to this project's executable.
add_executable (ha1 "ha1.cpp"  "Person.h" "Person.cpp" "PhoneNumber.cpp" "PhoneNumber.h" "PhoneBook.cpp" "PhoneBook.h")

# TODO: Add tests and install targets if needed.
