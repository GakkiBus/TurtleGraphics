#include "mainwindow.h"
#include "turtlescene.h"
#include "compiler.h"
#include "statement.h"
#include "turtle_statement.h"
#include "symbol_table.h"

#include <QtWidgets>
#include <list>
#include <string>
#include <memory>
#include <iostream>

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
    std::list<std::shared_ptr<Turtle::Statement>> mainBody{};
    Turtle::ProcedureStatement penUp{"pen_up", std::list<std::string>{}, std::make_shared<PenUpStatement>(PenUpStatement{turtleScene})};
    mainBody.push_back(std::make_shared<Turtle::ProcedureStatement>(penUp));
    Turtle::ProcedureStatement penDown{"pen_down", std::list<std::string>{}, std::make_shared<PenDownStatement>(PenDownStatement{turtleScene})};
    mainBody.push_back(std::make_shared<Turtle::ProcedureStatement>(penDown));
    Turtle::ProcedureStatement move{"move", std::list<std::string>{"x"}, std::make_shared<MoveStatement>(MoveStatement{turtleScene})};
    mainBody.push_back(std::make_shared<Turtle::ProcedureStatement>(move));
    Turtle::ProcedureStatement rotate{"rotate", std::list<std::string>{"x"}, std::make_shared<RotateStatement>(RotateStatement{turtleScene})};
    mainBody.push_back(std::make_shared<Turtle::ProcedureStatement>(rotate));

    std::shared_ptr<Turtle::Statement> code{compile(instructionEdit->toPlainText().toStdString())};
    mainBody.push_back(code);
    Turtle::BlockStatement main{mainBody};
    SymbolTable table{};
    main.execute(table);
}
