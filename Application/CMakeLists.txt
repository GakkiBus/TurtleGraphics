add_executable(TurtleGraphics
    main.cpp
    mainwindow.cpp
    turtlescene.cpp
    turtle_statement.cpp
)

target_link_libraries(TurtleGraphics 
    LINK_PUBLIC Compiler
    LINK_PUBLIC TurtleLanguage
)

target_link_libraries(TurtleGraphics 
    PRIVATE Qt5::Widgets 
)
