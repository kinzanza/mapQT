#include "mainwindow.h"

#include <QApplication>
#include "mapa.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    //MainWindow w;
    //w.show();
    Mapa m;
    m.show();
    return a.exec();
}
