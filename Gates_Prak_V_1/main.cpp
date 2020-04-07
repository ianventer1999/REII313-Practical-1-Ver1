#include "environment.h"

#include <QApplication>
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Environment Scene;

    QGraphicsView view(&Scene);
    view.showMaximized();
    return a.exec();
}
