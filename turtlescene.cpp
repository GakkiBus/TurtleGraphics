#include "turtlescene.h"

TurtleScene::TurtleScene(QObject *parent)
    : QGraphicsScene(parent)
{
    reset();
}

void TurtleScene::reset()
{
    clear();
    isPenDown = defaultIsPenDown;
    penLocation = QPointF(defaultPenLocation);
}

void TurtleScene::penDown()
{
    isPenDown = true;
}

void TurtleScene::penUp()
{
    isPenDown = false;
}

void TurtleScene::movePenX(int deltaX)
{
    movePen(deltaX, 0);
}

void TurtleScene::movePenY(int deltaY)
{
    movePen(0, deltaY);
}

void TurtleScene::movePen(int deltaX, int deltaY)
{
    QPointF newLocation = penLocation + QPointF(deltaX, deltaY);
    QLineF line = QLineF(penLocation, newLocation);
    QPen pen = QPen();
    if (!isPenDown)
        pen.setColor(QColorConstants::Transparent);

    addLine(line, pen);
    penLocation = newLocation;
}
