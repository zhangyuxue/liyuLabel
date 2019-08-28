#include "ly_mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ly_MainWindow w;
    w.resize(800,600);
    w.show();

    return a.exec();
}
