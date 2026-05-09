add_library(lexer_lib STATIC Lexer.cpp Token.cpp utils.cpp)

target_include_directories(lexer_lib PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)
