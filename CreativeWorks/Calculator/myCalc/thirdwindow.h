#ifndef THIRDWINDOW_H
#define THIRDWINDOW_H

#include <QDialog>
#include <QMessageBox>
#include <QString>
#include <QPushButton>
#include <QMessageBox>
#include <QPalette>
#include <QPixmap>
namespace Ui {
class ThirdWindow;
}

class ThirdWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ThirdWindow(QWidget *parent = nullptr);
    ~ThirdWindow();

private:
    Ui::ThirdWindow *ui;
    void SetFunction(double result, QString degrees);

private slots:
    void digit_numbers();
    void operations();
    void math_operations();
    void on_button_dot_clicked();
    void on_button_equal_clicked();
    void on_button_erase_all_clicked();
    void on_button_clear_clicked();
};

#endif // THIRDWINDOW_H
