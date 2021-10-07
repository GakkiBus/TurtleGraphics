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
    void setRotationAngle(int angle);

private:
    // amount of pixels moved per instruction unit
    static constexpr int defaultPixelScale{1};
    static constexpr bool defaultIsPenDown{true};
    static constexpr QPointF defaultPenLocation{QPointF(0, 0)};
    static constexpr int defaultRotationAngle{0};

    int pixelScale;
    bool isPenDown;
    QPointF penLocation;
    int rotationAngle;

    void movePen(int deltaX, int deltaY, int angleOffset);
};

#endif
