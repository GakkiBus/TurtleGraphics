#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "parser.h"

#include <QWidget>

class QHBoxLayout;
class TurtleScene;
class QGraphicsView;
class QGroupBox;
class QVBoxLayout;
class QTextEdit;
class QPushButton;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

private:
    QHBoxLayout* layout;
    // scene where turtle graphic is drawn
    TurtleScene* turtleScene;
    // viewport of turtle graphic is displayed
    QGraphicsView* turtleView;
    QGroupBox* menuBox;
    QVBoxLayout* menuLayout;
    QTextEdit* instructionEdit;
    QPushButton* instructionConfirm;

    void initializeMenu();

private slots:
    void onButtonReleased();
};

#endif
