#include "mainwindow.h"

#include <QApplication>
#include <QtWidgets>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    QWidget widget;
    QVBoxLayout *layout = new QVBoxLayout(&widget);

    QPushButton *button = new QPushButton("Click Me",&widget);

    QLabel *label = new QLabel("Hello World", &widget);
    label->setVisible(false);

    layout -> addWidget(button);
    layout -> addWidget(label);

    QObject::connect(button, &QPushButton::clicked, [&label](){
        label -> setVisible(!label->isVisible());
    });

    widget.show();

    return a.exec();
}
