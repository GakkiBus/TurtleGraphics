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
    rotationAngle = defaultRotationAngle;
}

void TurtleScene::penDown()
{
    isPenDown = true;
}

void TurtleScene::penUp()
{
    isPenDown = false;
}

void TurtleScene::movePenX(double deltaX)
{
    movePen(deltaX, 0.0, (deltaX < 0.0) ? 180.0 : 0.0);
}

void TurtleScene::movePenY(double deltaY)
{
    movePen(0.0, deltaY, (deltaY < 0.0) ? 90.0 : 270.0);
}

void TurtleScene::setRotationAngle(double angle)
{
    rotationAngle += angle;
}

/*
 * In addition to the angle specified through instructions, an offset is needed
 * since angles in qt are relative to the x-axis
*/
void TurtleScene::movePen(double deltaX, double deltaY, double angleOffset)
{
    QPointF newLocation = penLocation + pixelScale * QPointF(deltaX, deltaY);
    QLineF line = QLineF(penLocation, newLocation);
    // clockwise roation of new point by specified angle
    line.setAngle(angleOffset + rotationAngle);
    QPen pen = QPen();
    if (!isPenDown)
        pen.setColor(QColorConstants::Transparent);

    addLine(line, pen);
    penLocation = line.p2();
}
