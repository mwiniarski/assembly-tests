cmake_minimum_required(VERSION 3.9)
project(SampleProject)

set(CMAKE_CXX_STANDARD 17)

add_executable(sample main.cpp)

include_directories(src)

add_subdirectory(src)
add_subdirectory(tests)

target_link_libraries(sample src)