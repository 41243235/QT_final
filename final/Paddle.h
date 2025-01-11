#ifndef PADDLE_H
#define PADDLE_H


#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QGraphicsRotation>
#include <QGraphicsEllipseItem>
#include <QKeyEvent>
#include <QGraphicsItem>

class Paddle: public QGraphicsRectItem{
    public:
    Paddle(const QString& imagePath);
    void keyPressEvent(QKeyEvent * event);
    void rotate(qreal angle);
    Paddle();
    QGraphicsRectItem *getpaddlebox() const;

    QGraphicsRectItem *paddlebox;


};

#endif // PADDLE_H
