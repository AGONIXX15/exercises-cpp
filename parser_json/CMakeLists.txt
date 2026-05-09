cmake_minimum_required(VERSION 3.23)

project(parser_json)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
# add_executable(parser_json main.cpp)
add_subdirectory(src)

