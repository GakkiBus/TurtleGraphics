add_library(TurtleLanguage 
    rational.cpp
    expression.cpp
    bool_expression.cpp
    statement.cpp
    symbol_table.cpp)

target_include_directories(TurtleLanguage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
