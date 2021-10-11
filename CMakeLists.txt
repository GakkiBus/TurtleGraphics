cmake_minimum_required(VERSION 3.16.0)

project(TurtleGraphics VERSION 1.0.0 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

if (MSVC)
    add_compile_options(/W4 /WX)
else()
    add_compile_options(-Wall -Wextra -pedantic -Werror)
endif()

find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_subdirectory(Application)
add_subdirectory(Compiler)
add_subdirectory(TurtleLanguage)
