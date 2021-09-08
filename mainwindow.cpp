#include "mainwindow.h"
#include "turtlescene.h"

#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent)
    : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    turtleScene = new TurtleScene();
    turtleView = new QGraphicsView(turtleScene);
    initializeMenu();

    layout->addWidget(turtleView, 66);
    layout->addWidget(menuBox, 33);
    setLayout(layout);
    setWindowTitle("Turtle Graphics");
}

MainWindow::~MainWindow()
{
    delete turtleScene;
    delete turtleView;
    delete layout;
}

void MainWindow::initializeMenu()
{
    menuBox = new QGroupBox();
    menuLayout = new QVBoxLayout();
    instructionEdit = new QTextEdit();
    instructionConfirm = new QPushButton("Draw Graphics");

    menuBox->setLayout(menuLayout);
    menuLayout->addWidget(instructionEdit);
    menuLayout->addWidget(instructionConfirm);
}
