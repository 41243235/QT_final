#include "widget.h"
#include "ball.h"
#include "paddle.h"
#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsRectItem>
#include <QApplication>



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    QGraphicsScene *scene = new QGraphicsScene();
    QGraphicsView *view = new QGraphicsView(scene);
    view->setFixedSize(800,600);
    scene->setSceneRect(0,0,800,600);
    Ball *ball = new Ball();
    scene->addItem(ball->getball());
    Paddle *paddle = new Paddle();
    scene->addItem(paddle->getpaddlebox());
    view->show();

    return a.exec();
}
