
add_executable(main main.cpp Persona.cpp)

set_target_properties(main PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR})

add_subdirectory(lexer)

target_link_libraries(main PRIVATE lexer_lib)

