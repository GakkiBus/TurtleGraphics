#include "turtlescene.h"

TurtleScene::TurtleScene(QObject *parent)
    : QGraphicsScene(parent)
{
    penLocation = new QPointF();
}

TurtleScene::~TurtleScene()
{
}
