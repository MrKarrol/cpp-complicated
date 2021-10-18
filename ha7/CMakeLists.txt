cmake_minimum_required (VERSION 3.8)

project ("ha7")

set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

include_directories(./../../protobuf/install/include)

find_library(LIBPROTOBUF_RELEASE NAMES libprotobuf.lib HINTS  ${PROJECT_SOURCE_DIR})
find_library(LIBPROTOBUF_DEBUG NAMES libprotobufd.lib HINTS  ${PROJECT_SOURCE_DIR})

set(LIBPROTOBUF_LIBRARIES debug ${LIBPROTOBUF_DEBUG} optimized ${LIBPROTOBUF_RELEASE})

add_executable (ha7 "ha7.cpp" "StudentsGroup.h" "StudentsGroup.cpp"  "FullName.pb.h" "FullName.pb.cc" "Student.pb.h" "Student.pb.cc" "StudentsGroup.pb.h" "StudentsGroup.pb.cc")
target_link_libraries(${CMAKE_PROJECT_NAME} ${LIBPROTOBUF_LIBRARIES})
