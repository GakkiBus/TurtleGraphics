#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QWidget>

class QGridLayout;
class TurtleScene;
class QGraphicsView;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    QGridLayout* layout;
    // scene where turtle graphic is drawn
    TurtleScene* turtleScene;
    // viewport of turtle graphic is displayed
    QGraphicsView* turtleView;
};

#endif
