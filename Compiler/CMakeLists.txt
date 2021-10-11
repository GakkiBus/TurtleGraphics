add_library(Compiler 
    grammar.cpp
    lexer.cpp
    parser.cpp
    parse_table.cpp
    code_generation.cpp)

target_link_libraries(Compiler 
    LINK_PUBLIC TurtleLanguage 
)

target_include_directories(Compiler PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
