#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qgraph.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QGraph gr;
    scene = new QGraphicsScene();
    scene->setSceneRect(0, 0, ui->graphicsView->width(), ui->graphicsView->height());
    gr.DrawGraph(scene);
    ui->graphicsView->setScene(scene);    
    scene->clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}

