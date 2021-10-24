cmake_minimum_required(VERSION 3.8)
project(ha1)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)
add_subdirectory(libs/googletest)