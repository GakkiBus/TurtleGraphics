#include "turtlescene.h"

TurtleScene::TurtleScene(QObject *parent)
    : QGraphicsScene(parent)
{
    reset();
}

void TurtleScene::reset()
{
    clear();
    pixelScale = defaultPixelScale;
    isPenDown = defaultIsPenDown;
    penLocation = QPointF(defaultPenLocation);
    angle = defaultAngle;
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
    movePen(deltaX, 0, (deltaX < 0) ? 180 : 0);
}

void TurtleScene::movePenY(int deltaY)
{
    movePen(0, deltaY, (deltaY < 0) ? 90 : 270);
}

void TurtleScene::setAngle(int theta)
{
    angle = theta;
}

/*
 * In addition to the angle specified through instructions, an offset is needed
 * since angles in qt are relative to the x-axis
*/
void TurtleScene::movePen(int deltaX, int deltaY, int angleOffset)
{
    QPointF newLocation = penLocation + pixelScale * QPointF(deltaX, deltaY);
    QLineF line = QLineF(penLocation, newLocation);
    // clockwise roation of new point by specified angle
    line.setAngle(angleOffset + angle);
    QPen pen = QPen();
    if (!isPenDown)
        pen.setColor(QColorConstants::Transparent);

    addLine(line, pen);
    penLocation = line.p2();
}
