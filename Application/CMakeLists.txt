find_package(Qt5 COMPONENTS Widgets REQUIRED)

add_executable(TurtleGraphics
    main.cpp
    mainwindow.cpp
    turtlescene.cpp
)

target_link_libraries(TurtleGraphics 
    LINK_PUBLIC Compiler
)

target_link_libraries(TurtleGraphics 
    PRIVATE Qt5::Widgets 
)
