#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QGraphicsDropShadowEffect>
#include <QIcon>
#include <QPixmap>
#include <QPalette>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPixmap agnles(":/img/img/1050_16x9-1618578324bDO3AETSRnd1g2D3lle6OJ3ZQwNPKEwiEGoQIdV4.jpeg");
    agnles = agnles.scaled(this->size(), Qt::IgnoreAspectRatio);
    QPalette palette;
    palette.setBrush(QPalette::Background, agnles);
    this->setPalette(palette);

    QGraphicsDropShadowEffect *eff = new QGraphicsDropShadowEffect(this);
    eff->setOffset(2, 2);
    eff->setBlurRadius(0.5);
    eff->setColor(Qt::black);
    ui->sign->setGraphicsEffect(eff);
    QGraphicsDropShadowEffect *eff2 = new QGraphicsDropShadowEffect(this);
    eff2->setOffset(1, 1);
    eff2->setBlurRadius(0.5);
    eff2->setColor(Qt::black);
    ui->place_year->setGraphicsEffect(eff2);
    QGraphicsDropShadowEffect *eff3 = new QGraphicsDropShadowEffect(this);
    eff3->setOffset(1, 1);
    eff3->setBlurRadius(1);
    eff3->setColor(Qt::white);
    ui->title->setGraphicsEffect(eff3);

}

MainWindow::~MainWindow()
{
    delete ui, window, window2;
}

void MainWindow::on_pushButton_info_clicked()
{
    window2 = new SecondWindow(this);
    window2->setWindowTitle("Постановка задачи");
    window2->show();
}

void MainWindow::on_pushButton_calc_clicked()
{
    window = new ThirdWindow(this);
    window->setWindowTitle("Calculator");
    window->show();
}
