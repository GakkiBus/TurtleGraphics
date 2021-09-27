cmake_minimum_required(VERSION 3.16.0)

project(TurtleGraphics VERSION 1.0.0 LANGUAGES CXX)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TurtleGraphics
    main.cpp
    parser.cpp
    turtlelang.cpp
    mainwindow.cpp
    turtlescene.cpp
    instruction.cpp
    symbolic_table.cpp
    lexer.cpp
)

target_link_libraries(TurtleGraphics
    PRIVATE Qt5::Widgets 
)
