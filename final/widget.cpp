#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    layout1 = new QVBoxLayout;
    soloplayButton = new QPushButton("單機遊玩");
    multiButton = new QPushButton("多人連機");
    solo1Button = new QPushButton("單機單人");
    solo2Button = new QPushButton("單機雙人");


    layout1->addWidget(soloplayButton);
    layout1->addWidget(multiButton);


    setLayout(layout1);
    setWindowTitle("主選單");
    setFixedSize(300, 200);

    QObject::connect(soloplayButton, &QPushButton::clicked, this, &Widget::soloplaybtn);
    QObject::connect(multiButton, &QPushButton::clicked, this, &Widget::multibtn);
    QObject::connect(solo1Button, &QPushButton::clicked, this, &Widget::solo1btn);
    QObject::connect(solo2Button, &QPushButton::clicked, this, &Widget::solo2btn);

}

Widget::~Widget()
{
    delete ui;
}

void Widget::soloplaybtn()
{
    layout1->removeWidget(soloplayButton);
    layout1->removeWidget(multiButton);
    layout1->addWidget(solo1Button);
    layout1->addWidget(solo2Button);
}

void Widget::multibtn()
{
    layout1->removeWidget(soloplayButton);
    layout1->removeWidget(multiButton);

}

void Widget::solo1btn()
{
    layout1->removeWidget(solo1Button);
    layout1->removeWidget(solo2Button);
}

void Widget::solo2btn()
{
    layout1->removeWidget(solo1Button);
    layout1->removeWidget(solo2Button);
}

// Compare this snippet from main.cpp:
