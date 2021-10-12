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
    void movePenX(double deltaX);
    void movePenY(double deltaY);
    void setRotationAngle(double angle);

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

    void movePen(double deltaX, double deltaY, double angleOffset);
};

#endif
