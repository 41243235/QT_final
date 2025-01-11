#include "game_components.h"
#include <QApplication>
#include <QGraphicsScene>
#include <QBrush>
#include <QVector>
#include <QPixmap>
#include <QObject>

Paddle::Paddle(const QString& imagePath) {
    QPixmap paddlePixmap(imagePath);
    setPixmap(paddlePixmap);
    setTransformationMode(Qt::SmoothTransformation);
    hitbox = new QGraphicsRectItem(boundingRect(), this);
    hitbox->setPen(Qt::NoPen);
}

void Paddle::keyPressEvent(QKeyEvent* event) {
    if (event->key() == Qt::Key_Left && x() > 0) {
        setPos(x() - 20, y());
    } else if (event->key() == Qt::Key_Right && x() + boundingRect().width() < 800) {
        setPos(x() + 20, y());
    } else if (event->key() == Qt::Key_A) {
        rotate(-10); // Rotate counter-clockwise
    } else if (event->key() == Qt::Key_D) {
        rotate(10); // Rotate clockwise
    }
}

void Paddle::rotate(qreal angle) {
    QTransform transform;
    transform.translate(x() + boundingRect().width() / 2, y() + boundingRect().height() / 2);
    transform.rotate(angle);
    transform.translate(-(x() + boundingRect().width() / 2), -(y() + boundingRect().height() / 2));
    setTransform(transform, true);
}

QGraphicsRectItem* Paddle::getHitbox() const {
    return hitbox;
}

Ball::Ball() {
    setRect(0, 0, 15, 15);
    dx = 4;
    dy = -4;
}

void Ball::move() {
    setPos(x() + dx, y() + dy);

    if (x() <= 0 || x() + rect().width() >= 800) {
        dx = -dx;
    }
    if (y() <= 0) {
        dy = -dy;
    }

    if (y() > 600) {
        emit gameOver();
    }
}

void Ball::reverseY() {
    dy = -dy;
}

void Ball::reverseX() {
    dx = -dx;
}

Brick::Brick(qreal x, qreal y) {
    setRect(0, 0, 60, 20);
    setPos(x, y);
    setBrush(QBrush(Qt::blue));
}

GameManager::GameManager(QGraphicsView* view, QTimer* timer) : view(view), timer(timer) {}

void GameManager::handleGameOver() {
    timer->stop();
    view->close();
}

int main(int argc, char* argv[]) {
    QApplication app(argc, argv);

    QGraphicsScene* scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, 800, 600);

    QGraphicsView* view = new QGraphicsView(scene);
    view->setFixedSize(800, 600);

    Paddle* paddle = new Paddle("C:/Users/USER/Desktop/QT_homwork/test/paddle.png");
    paddle->setPos(350, 550);
    scene->addItem(paddle);
    paddle->setFlag(QGraphicsItem::ItemIsFocusable);
    paddle->setFocus();

    Ball* ball = new Ball();
    ball->setBrush(QBrush(Qt::green));
    ball->setPos(390, 530);
    scene->addItem(ball);

    QVector<Brick*> bricks;
    for (int i = 0; i < 5; ++i) {
        for (int j = 0; j < 10; ++j) {
            Brick* brick = new Brick(j * 70, i * 30);
            bricks.append(brick);
            scene->addItem(brick);
        }
    }

    QTimer* timer = new QTimer();
    QObject::connect(timer, &QTimer::timeout, [&]() {
        ball->move();

        if (ball->collidesWithItem(paddle->getHitbox())) {
            ball->reverseY();
        }

        for (Brick* brick : bricks) {
            if (ball->collidesWithItem(brick)) {
                scene->removeItem(brick);
                bricks.removeOne(brick);
                delete brick;
                ball->reverseY();
                break;
            }
        }
    });
    timer->start(16);

    GameManager* manager = new GameManager(view, timer);
    QObject::connect(ball, &Ball::gameOver, manager, &GameManager::handleGameOver);

    view->show();

    return app.exec();
}

