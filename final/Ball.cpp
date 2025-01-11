#include "Ball.h"
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

Ball::Ball(){
    ball = new QGraphicsEllipseItem();
    ball->setRect(0,0,100,100);
    ball->setPos(0,0);
    ball->setBrush(QBrush(QColor("red")));
    ball->setPen(QPen(Qt::NoPen));
    setSpeed(10);
    setDirection(1,1);
    setRadius(50);
    setPosX(0);
    setPosY(0);
    setBallColor("red");
    setBallColor2("blue");
}

QGraphicsEllipseItem *Ball::getball() const{
    return ball;
}

void Ball::move(){
    setPos(getPosX()+getDirectionX()*getSpeed(),getPosY()+getDirectionY()*getSpeed());
}

void Ball::setDirection(int x, int y){
    setDirectionX(x);
    setDirectionY(y);
}

int Ball::getDirectionX(){
    return directionX;
}

int Ball::getDirectionY(){
    return directionY;
}

void Ball::setSpeed(int speed){
    this->speed = speed;
}

int Ball::getSpeed(){
    return speed;
}

void Ball::setDirectionX(int x){
    directionX = x;
}

void Ball::setDirectionY(int y){
    directionY = y;
}

void Ball::setPosX(int x){
    posX = x;
}

void Ball::setPosY(int y){
    posY = y;
}

int Ball::getPosX(){
    return posX;
}

int Ball::getPosY(){
    return posY;
}

void Ball::setRadius(int r){
    radius = r;
}

int Ball::getRadius(){
    return radius;
}

void Ball::setBallColor(QString color){
    ball->setBrush(QBrush(QColor(color)));
}

QString Ball::getBallColor(){
    return ball->brush().color().name();
}

void Ball::setBallColor2(QString color){
    ball->setBrush(QBrush(QColor(color)));
}

QString Ball::getBallColor2(){
    return ball->brush().color().name();
}

// Compare this snippet from main.cpp:
