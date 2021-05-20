#include "secondwindow.h"
#include "ui_secondwindow.h"

SecondWindow::SecondWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SecondWindow)
{
    ui->setupUi(this);
    QPixmap secondpic(":/img/img/s.PNG");
    int w = ui->background2->width();
    int h = ui->background2->height();
    ui->background2->setPixmap(secondpic.scaled(w,h,Qt::KeepAspectRatio));
}

SecondWindow::~SecondWindow()
{
    delete ui;
}
