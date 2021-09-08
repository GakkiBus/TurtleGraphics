#ifndef TURTLESCENE_H
#define TURTLESCENE_H

#include <QGraphicsScene>

class QObject;
class QPointF;

class TurtleScene : public QGraphicsScene
{
    Q_OBJECT

public:
    explicit TurtleScene(QObject *parent = 0);

    void penDown();
    void penUp();
    void movePenX(int deltaX);
    void movePenY(int deltaY);

private:
    bool isPenDown;
    QPointF penLocation;

    void movePen(int deltaX, int deltaY);
};

#endif
