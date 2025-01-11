#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QVBoxLayout>

QT_BEGIN_NAMESPACE
namespace Ui {
class Widget;
}
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();
    QVBoxLayout* layout1;
    QVBoxLayout* layout2;
    QPushButton* soloplayButton;
    QPushButton* solo1Button;
    QPushButton* solo2Button;
    QPushButton* multiButton;

private:
    void soloplaybtn();
    void multibtn();
    void solo1btn();
    void solo2btn();

    Ui::Widget *ui;
};
#endif // WIDGET_H
