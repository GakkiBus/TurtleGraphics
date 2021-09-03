#include "mainwindow.h"
#include "turtlescene.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    layout = new QGridLayout();
    turtleScene = new TurtleScene();
    turtleView = new QGraphicsView(turtleScene);

    layout->addWidget(turtleView,0,0);
    turtleScene->addText("Hello World");

    setLayout(layout);
    setWindowTitle("Turtle Graphics");
}

MainWindow::~MainWindow()
{
    delete turtleScene;
    delete turtleView;
    delete layout;
}
