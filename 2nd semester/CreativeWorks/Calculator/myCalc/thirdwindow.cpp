#include "thirdwindow.h"
#include "ui_thirdwindow.h"
#include <cmath>

double firstD;
const double toConvertDegToRad = 0.01745329251;

ThirdWindow::ThirdWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ThirdWindow)
{
    ui->setupUi(this);

    connect(ui->button_null, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_one, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_two, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_three, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_four, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_five, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_six, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_seven, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_eight, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_nine, SIGNAL(clicked()), this, SLOT(digit_numbers()));
    connect(ui->button_plus_minus, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_division, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->button_multiplication, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->button_minus, SIGNAL(clicked()), this, SLOT(math_operations()));
    connect(ui->button_plus, SIGNAL(clicked()), this, SLOT(math_operations()));
    ui->button_division->setCheckable(true);
    ui->button_multiplication->setCheckable(true);
    ui->button_minus->setCheckable(true);
    ui->button_plus->setCheckable(true);
    connect(ui->button_sin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_cos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_tan, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_cot, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_arcsin, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_arccos, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_arctg, SIGNAL(clicked()), this, SLOT(operations()));
    connect(ui->button_arcctg, SIGNAL(clicked()), this, SLOT(operations()));
}


void ThirdWindow::SetFunction(double result, QString degrees)
{
    degrees = QString::number(result, 'g', 5);
    //radians = result * toConvertDegToRad;
    //rad = QString::number(radians, 'g', 10);
    //degrees += "°";
    ui->degree_result->setText(degrees);
    //ui->radians_result->setText(rad);
    double minutes = result * 60;
    double seconds = minutes * 60;
    QString mins = QString::number(minutes, 'g', 5);
    QString secs = QString::number(seconds, 'g', 7);
    //ui->radians_result->setText(rad);
    //mins += "'";
    //secs += "''";
    ui->minutes_result->setText(mins);
    ui->seconds_result->setText(secs);
    //ui->degree_result->setText(ui->degree_result->text() + tr("°"));
}

ThirdWindow::~ThirdWindow()
{
    delete ui;
}

void ThirdWindow::digit_numbers()
{
    QPushButton *key=(QPushButton *)sender();
    QString degrees;
    double all_numbers;
    if ((ui->degree_result->text() + key->text()).toDouble() >= 361)
        return;
    if (ui->degree_result->text().contains(".") && key->text() == "0"){
        degrees = ui->degree_result->text() + key->text();       
        ui->degree_result->setText(degrees);
    }
    else{
        all_numbers = (ui->degree_result->text() + key->text()).toDouble();        
        SetFunction(all_numbers, degrees);
    }

}

void ThirdWindow::operations()
{    
    QPushButton *key=(QPushButton *)sender();
    QString degrees, rad;
    double all_numbers = (ui->degree_result->text()).toDouble();
    double newDegrees = all_numbers;
    if (key->text() == "+/-"){
        all_numbers *= -1;
        if (all_numbers < 0){
        degrees = QString::number(all_numbers, 'g', 5);        
        ui->degree_result->setText(degrees);                 
        ui->minutes_result->setText("error");
        ui->seconds_result->setText("error");
        }
        else{
            SetFunction(all_numbers, degrees);
        }
    }
    if (key->text() == "sin"){
       newDegrees = sin(newDegrees * toConvertDegToRad);
       QString sinus;
       sinus = QString::number(newDegrees, 'g', 4);
       ui->trig_func->setText(sinus);
    }
    if (key->text() == "cos"){
        if (newDegrees != 90 && newDegrees != -90){
        newDegrees = cos(newDegrees * toConvertDegToRad);
        QString cosinus;
        cosinus = QString::number(newDegrees, 'g', 5);
        ui->trig_func->setText(cosinus);
        }
        else{
            ui->trig_func->setText("0");
        }
    }
    if (key->text() == "tg"){
        if (all_numbers != 90 && all_numbers != -90){
        newDegrees = sin(newDegrees * toConvertDegToRad) / cos(newDegrees * toConvertDegToRad);
        QString tangen = QString::number(newDegrees, 'g', 3);
        ui->trig_func->setText(tangen);
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->trig_func->setText("error");
        }
    }
    if (key->text() == "ctg"){
        if (all_numbers != 0 && all_numbers != 180){
            if (all_numbers != 90 && all_numbers != -90){
        newDegrees = (cos(newDegrees * toConvertDegToRad) / sin(newDegrees * toConvertDegToRad));
        QString cot = QString::number(newDegrees, 'g', 4);
        ui->trig_func->setText(cot);
            }
            else { ui->trig_func->setText("0"); }
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->trig_func->setText("Error");
        }
    }
    if (key->text() == "arcsin"){
        if (all_numbers >= -90 && all_numbers <= 90){
        newDegrees = asin(newDegrees * toConvertDegToRad);        
        QString arcsin = QString::number(newDegrees, 'g', 4);
        if (all_numbers > 57){
            QMessageBox::warning(this, "Ошибка вычисления", "Почему-то встроенная функция не считает эту фунцию для углов, больших 57");
        }
        ui->obr_trig_func->setText(arcsin);
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->obr_trig_func->setText("Error");
        }
    }
    if (key->text() == "arccos"){
        if (all_numbers >= 0 && all_numbers <= 180){
        newDegrees = acos(newDegrees * toConvertDegToRad);
        QString arccos = QString::number(newDegrees, 'g', 4);
        if (all_numbers > 57){
            QMessageBox::warning(this, "Ошибка вычисления", "Почему-то встроенная функция не считает эту фунцию для углов, больших 57");
        }
        ui->obr_trig_func->setText(arccos);
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->obr_trig_func->setText("Error");
        }
    }
    if (key->text()== "arctg"){
        if (all_numbers > -90 && all_numbers < 90){
        newDegrees = atan(newDegrees * toConvertDegToRad);
        QString arctan = QString::number(newDegrees, 'g', 4);
        ui->obr_trig_func->setText(arctan);
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->obr_trig_func->setText("Error");
        }
    }
    if (key->text() == "arcctg"){
        if (all_numbers > 0 && all_numbers < 180){
        newDegrees = atan(1 / (newDegrees * toConvertDegToRad));
        QString arccot = QString::number(newDegrees, 'g', 4);
        ui->obr_trig_func->setText(arccot);
        }
        else{
            QMessageBox::warning(this, "Ошибка вычисления", "Невозможно определить точное значение!");
            ui->obr_trig_func->setText("Error");
        }
    }
}

void ThirdWindow::math_operations()
{
    QPushButton *key=(QPushButton *)sender();
    firstD = ui->degree_result->text().toDouble();
    ui->degree_result->setText("");
    key->setChecked(true);
}

void ThirdWindow::on_button_dot_clicked()
{
   if (!(ui->degree_result->text().contains('.'))){       
       ui->degree_result->setText(ui->degree_result->text() + tr("."));
    }
}

void ThirdWindow::on_button_equal_clicked()
{
    double result, secondD;
    QString degrees;
    secondD = ui->degree_result->text().toDouble();

   if (ui->button_division->isChecked()){
       if (secondD != 0){
        result = firstD / secondD;       
        SetFunction(result, degrees);
       }else{
            QMessageBox::warning(this, "Error", "На нуль лучше не делить");
       }
        ui->button_division->setChecked(false);
   } else if (ui->button_multiplication->isChecked()){
        result = firstD * secondD;        
        SetFunction(result, degrees);        
        ui->button_multiplication->setChecked(false);
   } else if (ui->button_minus->isChecked()){
        result = firstD - secondD;        
        SetFunction(result, degrees);       
        ui->button_minus->setChecked(false);
   } else if (ui->button_plus->isChecked()){
        result = firstD + secondD;        
        SetFunction(result, degrees);
        ui->button_plus->setChecked(false);
   }
}

void ThirdWindow::on_button_erase_all_clicked()
{
    ui->button_division->setChecked(false);
    ui->button_multiplication->setChecked(false);
    ui->button_minus->setChecked(false);
    ui->button_plus->setChecked(false);
    ui->degree_result->setText("0");    
    ui->minutes_result->setText("0");
    ui->seconds_result->setText("0");
    ui->trig_func->setText("0");
    ui->obr_trig_func->setText("0");
}

void ThirdWindow::on_button_clear_clicked()
{
    ui->button_division->setChecked(false);
    ui->button_multiplication->setChecked(false);
    ui->button_minus->setChecked(false);
    ui->button_plus->setChecked(false);
    QString degrees = ui->degree_result->text();
    degrees.chop(1);
    double result = degrees.toDouble();
    SetFunction(result, degrees);
}
