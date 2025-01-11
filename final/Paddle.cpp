#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>

#include "Paddle.h"

Paddle::Paddle(const QString& imagePath)
{
    paddlebox = new QGraphicsRectItem();
    paddlebox->setRect(0,0,100,100);
    paddlebox->setPos(0,0);
    paddlebox->setBrush(QBrush(QImage(imagePath)));

}

void Paddle::keyPressEvent(QKeyEvent * event)
{
    if(event->key() == Qt::Key_A){//move left
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_D){//move right
        setPos(x()+10,y());

    }
    else if(event->key() == Qt::Key_W){
        rotate(-10);
    }
    else if(event->key() == Qt::Key_S){
        rotate(10);
    }
}

void Paddle::rotate(qreal angle)
{
    setRotation(rotation()+angle);
}

QGraphicsRectItem *Paddle::getpaddlebox() const
{
    return paddlebox;
}

Paddle::Paddle()
{
    paddlebox = new QGraphicsRectItem();
    paddlebox->setRect(0,0,100,100);
    paddlebox->setPos(0,0);
    paddlebox->setBrush(QBrush(QColor("blue")));
}
// Compare this snippet from main.cpp:
