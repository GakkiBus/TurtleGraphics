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
    ~TurtleScene();

private:
    bool isPenDown{false};
    QPointF* penLocation;
};

#endif
