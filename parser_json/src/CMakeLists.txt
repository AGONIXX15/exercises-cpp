

add_subdirectory(regex)


add_executable(parser_json main.cpp)


target_include_directories(parser_json PRIVATE include)
target_include_directories(regex_library PUBLIC include)


target_link_libraries(parser_json PRIVATE regex_library)
