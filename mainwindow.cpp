#include "mainwindow.h"
#include "turtlescene.h"
#include "parser.h"
#include "turtlelang.h"
#include "instruction.h"

#include <QtWidgets>
#include <list>
#include <string>

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
    setWindowTitle("TurtleGraphics");

    connect(instructionConfirm, SIGNAL(released()), this, SLOT(onButtonReleased()));
}

void MainWindow::initializeMenu()
{
    menuBox = new QGroupBox();
    menuLayout = new QVBoxLayout();
    instructionEdit = new QPlainTextEdit();
    QFont font = QFont("Monospace");
    font.setStyleHint(QFont::Monospace);
    instructionEdit->setFont(font);
    instructionConfirm = new QPushButton("Draw Graphics");

    menuBox->setLayout(menuLayout);
    menuLayout->addWidget(instructionEdit);
    menuLayout->addWidget(instructionConfirm);
}

void MainWindow::onButtonReleased()
{
    turtleScene->reset();
    Parser parser{instructionEdit->toPlainText().toStdString()};
    parser.parse();
}
