#ifndef GAME_COMPONENTS_H
#define GAME_COMPONENTS_H

#include <QGraphicsPixmapItem>
#include <QGraphicsEllipseItem>
#include <QGraphicsRectItem>
#include <QObject>
#include <QKeyEvent>
#include <QTimer>
#include <QGraphicsView>

class Paddle : public QGraphicsPixmapItem {
public:
    Paddle(const QString& imagePath);
    void keyPressEvent(QKeyEvent* event) override;
    void rotate(qreal angle);
    QGraphicsRectItem* getHitbox() const;

private:
    QGraphicsRectItem* hitbox;
};

class Ball : public QObject, public QGraphicsEllipseItem {
    Q_OBJECT

public:
    Ball();
    void move();
    void reverseY();
    void reverseX();

signals:
    void gameOver();

private:
    int dx, dy;
};

class Brick : public QGraphicsRectItem {
public:
    Brick(qreal x, qreal y);
};

class GameManager : public QObject {
    Q_OBJECT

public:
    GameManager(QGraphicsView* view, QTimer* timer);

public slots:
    void handleGameOver();

private:
    QGraphicsView* view;
    QTimer* timer;
};

#endif // GAME_COMPONENTS_H
