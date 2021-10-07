add_library(TurtleLanguage 
    rational.cpp)

target_include_directories(TurtleLanguage PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_link_libraries(TurtleGraphics 
    LINK_PUBLIC Compiler
)
