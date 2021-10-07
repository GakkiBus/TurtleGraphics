add_library(Compiler 
    grammar.cpp
    lexer.cpp
    parser.cpp
    parse_table.cpp
    symbol_table.cpp)

target_include_directories(Compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
