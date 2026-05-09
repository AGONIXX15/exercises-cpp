cmake_minimum_required(VERSION 3.10)
project(MyProject)

set(CMAKE_CXX_STANDARD 23)


include_directories(include)
file(GLOB SOURCES "src/*.cpp")

add_executable(my_program ${SOURCES})
