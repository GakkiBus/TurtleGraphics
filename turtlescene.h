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

    void reset();
    void penDown();
    void penUp();
    void movePenX(int deltaX);
    void movePenY(int deltaY);

private:
    static constexpr bool defaultIsPenDown{true};
    static constexpr QPointF defaultPenLocation{QPointF(0, 0)};
    bool isPenDown;
    QPointF penLocation;

    void movePen(int deltaX, int deltaY);
};

#endif
