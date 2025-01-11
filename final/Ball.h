#ifndef BALL_H
#define BALL_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsRotation>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QGraphicsItem>
#include <QTimer>
#include <QBrush>
#include <QPen>

class Ball: public QGraphicsEllipseItem{
    public:
    Ball();
    QGraphicsEllipseItem *getball() const;
    QGraphicsEllipseItem *ball;
    void move();
    void setDirection(int x, int y);
    int getDirectionX();
    int getDirectionY();
    void setSpeed(int speed);
    int getSpeed();
    void setDirectionX(int x);
    void setDirectionY(int y);
    void setPosX(int x);
    void setPosY(int y);
    int getPosX();
    int getPosY();
    void setRadius(int r);
    int getRadius();
    void setBallColor(QString color);
    QString getBallColor();
    void setBallColor2(QString color);
    QString getBallColor2();

    private:
    int speed;
    int directionX;
    int directionY;
    int posX;
    int posY;
    int radius;
};

#endif // BALL_H
