#include "mainwindow.h"
#include "qgraph.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);    
    MainWindow w;
    w.setWindowTitle("My graph");
    w.show();
    return a.exec();
}
