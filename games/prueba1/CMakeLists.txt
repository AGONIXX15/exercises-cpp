cmake_minimum_required(VERSION 3.20)
project(prueba1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

find_package(SFML CONFIG REQUIRED COMPONENTS Graphics Window System)

add_executable(MySFMLGame src/main.cpp)

target_link_libraries(MySFMLGame PRIVATE
    SFML::Graphics
    SFML::Window
    SFML::System
)

