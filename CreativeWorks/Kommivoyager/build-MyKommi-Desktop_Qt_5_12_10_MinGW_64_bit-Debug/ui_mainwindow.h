/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QTextEdit *mx5;
    QTextEdit *mx1;
    QTextEdit *mx2;
    QTextEdit *mx4;
    QTextEdit *mx6;
    QTextEdit *mx3;
    QLineEdit *sec_fir;
    QLineEdit *th_fir;
    QLineEdit *four_fir;
    QLineEdit *six_fir;
    QLineEdit *four_sec;
    QLineEdit *fith_sec;
    QLineEdit *six_sec;
    QLineEdit *fir_th;
    QLineEdit *sec_th;
    QLineEdit *four_th;
    QLineEdit *fith_th;
    QLineEdit *six_th;
    QLineEdit *fir_four;
    QLineEdit *sec_four;
    QLineEdit *th_four;
    QLineEdit *fith_four;
    QLineEdit *six_four;
    QLineEdit *fir_fith;
    QLineEdit *sec_fith;
    QLineEdit *th_fith;
    QLineEdit *six_fith;
    QLineEdit *fir_six;
    QLineEdit *sec_six;
    QLineEdit *th_six;
    QLineEdit *four_six;
    QLineEdit *fir_sec;
    QLineEdit *fith_six;
    QLineEdit *four_fith;
    QLineEdit *th_sec;
    QLineEdit *fith_fir;
    QPushButton *run;
    QLabel *title;
    QLabel *sign;
    QLabel *date_year;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(900, 580);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/prefix1/pics/4aa534605d1afc465c5bdc5dd80f1ecb.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QString::fromUtf8("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(360, 10, 530, 521));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        mx5 = new QTextEdit(verticalLayoutWidget);
        mx5->setObjectName(QString::fromUtf8("mx5"));

        gridLayout->addWidget(mx5, 5, 4, 1, 1);

        mx1 = new QTextEdit(verticalLayoutWidget);
        mx1->setObjectName(QString::fromUtf8("mx1"));

        gridLayout->addWidget(mx1, 1, 0, 1, 1);

        mx2 = new QTextEdit(verticalLayoutWidget);
        mx2->setObjectName(QString::fromUtf8("mx2"));

        gridLayout->addWidget(mx2, 2, 1, 1, 1);

        mx4 = new QTextEdit(verticalLayoutWidget);
        mx4->setObjectName(QString::fromUtf8("mx4"));

        gridLayout->addWidget(mx4, 4, 3, 1, 1);

        mx6 = new QTextEdit(verticalLayoutWidget);
        mx6->setObjectName(QString::fromUtf8("mx6"));

        gridLayout->addWidget(mx6, 6, 5, 1, 1);

        mx3 = new QTextEdit(verticalLayoutWidget);
        mx3->setObjectName(QString::fromUtf8("mx3"));

        gridLayout->addWidget(mx3, 3, 2, 1, 1);

        sec_fir = new QLineEdit(verticalLayoutWidget);
        sec_fir->setObjectName(QString::fromUtf8("sec_fir"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(sec_fir->sizePolicy().hasHeightForWidth());
        sec_fir->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(22);
        sec_fir->setFont(font);

        gridLayout->addWidget(sec_fir, 1, 1, 1, 1);

        th_fir = new QLineEdit(verticalLayoutWidget);
        th_fir->setObjectName(QString::fromUtf8("th_fir"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(th_fir->sizePolicy().hasHeightForWidth());
        th_fir->setSizePolicy(sizePolicy1);
        th_fir->setFont(font);

        gridLayout->addWidget(th_fir, 1, 2, 1, 1);

        four_fir = new QLineEdit(verticalLayoutWidget);
        four_fir->setObjectName(QString::fromUtf8("four_fir"));
        sizePolicy1.setHeightForWidth(four_fir->sizePolicy().hasHeightForWidth());
        four_fir->setSizePolicy(sizePolicy1);
        four_fir->setFont(font);

        gridLayout->addWidget(four_fir, 1, 3, 1, 1);

        six_fir = new QLineEdit(verticalLayoutWidget);
        six_fir->setObjectName(QString::fromUtf8("six_fir"));
        sizePolicy1.setHeightForWidth(six_fir->sizePolicy().hasHeightForWidth());
        six_fir->setSizePolicy(sizePolicy1);
        six_fir->setFont(font);

        gridLayout->addWidget(six_fir, 1, 5, 1, 1);

        four_sec = new QLineEdit(verticalLayoutWidget);
        four_sec->setObjectName(QString::fromUtf8("four_sec"));
        sizePolicy1.setHeightForWidth(four_sec->sizePolicy().hasHeightForWidth());
        four_sec->setSizePolicy(sizePolicy1);
        four_sec->setFont(font);

        gridLayout->addWidget(four_sec, 2, 3, 1, 1);

        fith_sec = new QLineEdit(verticalLayoutWidget);
        fith_sec->setObjectName(QString::fromUtf8("fith_sec"));
        sizePolicy1.setHeightForWidth(fith_sec->sizePolicy().hasHeightForWidth());
        fith_sec->setSizePolicy(sizePolicy1);
        fith_sec->setFont(font);

        gridLayout->addWidget(fith_sec, 2, 4, 1, 1);

        six_sec = new QLineEdit(verticalLayoutWidget);
        six_sec->setObjectName(QString::fromUtf8("six_sec"));
        sizePolicy1.setHeightForWidth(six_sec->sizePolicy().hasHeightForWidth());
        six_sec->setSizePolicy(sizePolicy1);
        six_sec->setFont(font);

        gridLayout->addWidget(six_sec, 2, 5, 1, 1);

        fir_th = new QLineEdit(verticalLayoutWidget);
        fir_th->setObjectName(QString::fromUtf8("fir_th"));
        sizePolicy1.setHeightForWidth(fir_th->sizePolicy().hasHeightForWidth());
        fir_th->setSizePolicy(sizePolicy1);
        fir_th->setFont(font);

        gridLayout->addWidget(fir_th, 3, 0, 1, 1);

        sec_th = new QLineEdit(verticalLayoutWidget);
        sec_th->setObjectName(QString::fromUtf8("sec_th"));
        sizePolicy1.setHeightForWidth(sec_th->sizePolicy().hasHeightForWidth());
        sec_th->setSizePolicy(sizePolicy1);
        sec_th->setFont(font);

        gridLayout->addWidget(sec_th, 3, 1, 1, 1);

        four_th = new QLineEdit(verticalLayoutWidget);
        four_th->setObjectName(QString::fromUtf8("four_th"));
        sizePolicy1.setHeightForWidth(four_th->sizePolicy().hasHeightForWidth());
        four_th->setSizePolicy(sizePolicy1);
        four_th->setFont(font);

        gridLayout->addWidget(four_th, 3, 3, 1, 1);

        fith_th = new QLineEdit(verticalLayoutWidget);
        fith_th->setObjectName(QString::fromUtf8("fith_th"));
        sizePolicy1.setHeightForWidth(fith_th->sizePolicy().hasHeightForWidth());
        fith_th->setSizePolicy(sizePolicy1);
        fith_th->setFont(font);

        gridLayout->addWidget(fith_th, 3, 4, 1, 1);

        six_th = new QLineEdit(verticalLayoutWidget);
        six_th->setObjectName(QString::fromUtf8("six_th"));
        sizePolicy1.setHeightForWidth(six_th->sizePolicy().hasHeightForWidth());
        six_th->setSizePolicy(sizePolicy1);
        six_th->setFont(font);

        gridLayout->addWidget(six_th, 3, 5, 1, 1);

        fir_four = new QLineEdit(verticalLayoutWidget);
        fir_four->setObjectName(QString::fromUtf8("fir_four"));
        sizePolicy1.setHeightForWidth(fir_four->sizePolicy().hasHeightForWidth());
        fir_four->setSizePolicy(sizePolicy1);
        fir_four->setFont(font);

        gridLayout->addWidget(fir_four, 4, 0, 1, 1);

        sec_four = new QLineEdit(verticalLayoutWidget);
        sec_four->setObjectName(QString::fromUtf8("sec_four"));
        sizePolicy1.setHeightForWidth(sec_four->sizePolicy().hasHeightForWidth());
        sec_four->setSizePolicy(sizePolicy1);
        sec_four->setFont(font);

        gridLayout->addWidget(sec_four, 4, 1, 1, 1);

        th_four = new QLineEdit(verticalLayoutWidget);
        th_four->setObjectName(QString::fromUtf8("th_four"));
        sizePolicy1.setHeightForWidth(th_four->sizePolicy().hasHeightForWidth());
        th_four->setSizePolicy(sizePolicy1);
        th_four->setFont(font);

        gridLayout->addWidget(th_four, 4, 2, 1, 1);

        fith_four = new QLineEdit(verticalLayoutWidget);
        fith_four->setObjectName(QString::fromUtf8("fith_four"));
        sizePolicy1.setHeightForWidth(fith_four->sizePolicy().hasHeightForWidth());
        fith_four->setSizePolicy(sizePolicy1);
        fith_four->setFont(font);

        gridLayout->addWidget(fith_four, 4, 4, 1, 1);

        six_four = new QLineEdit(verticalLayoutWidget);
        six_four->setObjectName(QString::fromUtf8("six_four"));
        sizePolicy1.setHeightForWidth(six_four->sizePolicy().hasHeightForWidth());
        six_four->setSizePolicy(sizePolicy1);
        six_four->setFont(font);

        gridLayout->addWidget(six_four, 4, 5, 1, 1);

        fir_fith = new QLineEdit(verticalLayoutWidget);
        fir_fith->setObjectName(QString::fromUtf8("fir_fith"));
        sizePolicy.setHeightForWidth(fir_fith->sizePolicy().hasHeightForWidth());
        fir_fith->setSizePolicy(sizePolicy);
        fir_fith->setFont(font);

        gridLayout->addWidget(fir_fith, 5, 0, 1, 1);

        sec_fith = new QLineEdit(verticalLayoutWidget);
        sec_fith->setObjectName(QString::fromUtf8("sec_fith"));
        sizePolicy1.setHeightForWidth(sec_fith->sizePolicy().hasHeightForWidth());
        sec_fith->setSizePolicy(sizePolicy1);
        sec_fith->setFont(font);

        gridLayout->addWidget(sec_fith, 5, 1, 1, 1);

        th_fith = new QLineEdit(verticalLayoutWidget);
        th_fith->setObjectName(QString::fromUtf8("th_fith"));
        sizePolicy1.setHeightForWidth(th_fith->sizePolicy().hasHeightForWidth());
        th_fith->setSizePolicy(sizePolicy1);
        th_fith->setFont(font);

        gridLayout->addWidget(th_fith, 5, 2, 1, 1);

        six_fith = new QLineEdit(verticalLayoutWidget);
        six_fith->setObjectName(QString::fromUtf8("six_fith"));
        sizePolicy1.setHeightForWidth(six_fith->sizePolicy().hasHeightForWidth());
        six_fith->setSizePolicy(sizePolicy1);
        six_fith->setFont(font);

        gridLayout->addWidget(six_fith, 5, 5, 1, 1);

        fir_six = new QLineEdit(verticalLayoutWidget);
        fir_six->setObjectName(QString::fromUtf8("fir_six"));
        sizePolicy1.setHeightForWidth(fir_six->sizePolicy().hasHeightForWidth());
        fir_six->setSizePolicy(sizePolicy1);
        fir_six->setFont(font);

        gridLayout->addWidget(fir_six, 6, 0, 1, 1);

        sec_six = new QLineEdit(verticalLayoutWidget);
        sec_six->setObjectName(QString::fromUtf8("sec_six"));
        sizePolicy1.setHeightForWidth(sec_six->sizePolicy().hasHeightForWidth());
        sec_six->setSizePolicy(sizePolicy1);
        sec_six->setFont(font);

        gridLayout->addWidget(sec_six, 6, 1, 1, 1);

        th_six = new QLineEdit(verticalLayoutWidget);
        th_six->setObjectName(QString::fromUtf8("th_six"));
        sizePolicy1.setHeightForWidth(th_six->sizePolicy().hasHeightForWidth());
        th_six->setSizePolicy(sizePolicy1);
        th_six->setFont(font);

        gridLayout->addWidget(th_six, 6, 2, 1, 1);

        four_six = new QLineEdit(verticalLayoutWidget);
        four_six->setObjectName(QString::fromUtf8("four_six"));
        sizePolicy1.setHeightForWidth(four_six->sizePolicy().hasHeightForWidth());
        four_six->setSizePolicy(sizePolicy1);
        four_six->setFont(font);

        gridLayout->addWidget(four_six, 6, 3, 1, 1);

        fir_sec = new QLineEdit(verticalLayoutWidget);
        fir_sec->setObjectName(QString::fromUtf8("fir_sec"));
        sizePolicy1.setHeightForWidth(fir_sec->sizePolicy().hasHeightForWidth());
        fir_sec->setSizePolicy(sizePolicy1);
        fir_sec->setFont(font);

        gridLayout->addWidget(fir_sec, 2, 0, 1, 1);

        fith_six = new QLineEdit(verticalLayoutWidget);
        fith_six->setObjectName(QString::fromUtf8("fith_six"));
        sizePolicy1.setHeightForWidth(fith_six->sizePolicy().hasHeightForWidth());
        fith_six->setSizePolicy(sizePolicy1);
        fith_six->setFont(font);

        gridLayout->addWidget(fith_six, 6, 4, 1, 1);

        four_fith = new QLineEdit(verticalLayoutWidget);
        four_fith->setObjectName(QString::fromUtf8("four_fith"));
        sizePolicy1.setHeightForWidth(four_fith->sizePolicy().hasHeightForWidth());
        four_fith->setSizePolicy(sizePolicy1);
        four_fith->setFont(font);

        gridLayout->addWidget(four_fith, 5, 3, 1, 1);

        th_sec = new QLineEdit(verticalLayoutWidget);
        th_sec->setObjectName(QString::fromUtf8("th_sec"));
        sizePolicy1.setHeightForWidth(th_sec->sizePolicy().hasHeightForWidth());
        th_sec->setSizePolicy(sizePolicy1);
        th_sec->setFont(font);

        gridLayout->addWidget(th_sec, 2, 2, 1, 1);

        fith_fir = new QLineEdit(verticalLayoutWidget);
        fith_fir->setObjectName(QString::fromUtf8("fith_fir"));
        sizePolicy1.setHeightForWidth(fith_fir->sizePolicy().hasHeightForWidth());
        fith_fir->setSizePolicy(sizePolicy1);
        fith_fir->setFont(font);

        gridLayout->addWidget(fith_fir, 1, 4, 1, 1);


        verticalLayout->addLayout(gridLayout);

        run = new QPushButton(verticalLayoutWidget);
        run->setObjectName(QString::fromUtf8("run"));
        sizePolicy.setHeightForWidth(run->sizePolicy().hasHeightForWidth());
        run->setSizePolicy(sizePolicy);
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(18);
        font1.setBold(true);
        font1.setWeight(75);
        run->setFont(font1);
        run->setStyleSheet(QString::fromUtf8("QPushButton{\n"
"	background-color: #F8F8FF;\n"
"	color: black;\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	background-color: #FAF0E6;\n"
"	color: black;\n"
"	border: 1px solid grey;\n"
"	padding: 5px;\n"
"}"));

        verticalLayout->addWidget(run);

        title = new QLabel(centralwidget);
        title->setObjectName(QString::fromUtf8("title"));
        title->setGeometry(QRect(10, 40, 341, 75));
        QFont font2;
        font2.setFamily(QString::fromUtf8("Times New Roman"));
        font2.setPointSize(25);
        font2.setBold(true);
        font2.setWeight(75);
        title->setFont(font2);
        sign = new QLabel(centralwidget);
        sign->setObjectName(QString::fromUtf8("sign"));
        sign->setGeometry(QRect(10, 220, 331, 101));
        sign->setFont(font);
        sign->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        date_year = new QLabel(centralwidget);
        date_year->setObjectName(QString::fromUtf8("date_year"));
        date_year->setGeometry(QRect(120, 510, 83, 19));
        QFont font3;
        font3.setFamily(QString::fromUtf8("Times New Roman"));
        font3.setPointSize(12);
        date_year->setFont(font3);
        date_year->setStyleSheet(QString::fromUtf8("color: rgb(255, 255, 255);"));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 900, 20));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);
        QObject::connect(run, SIGNAL(clicked()), MainWindow, SLOT(show()));

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        mx5->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        mx1->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        mx2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        mx4->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        mx6->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        mx3->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'MS Shell Dlg 2'; font-size:8.25pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-size:36pt;\">M</span></p></body></html>", nullptr));
        sec_fir->setText(QApplication::translate("MainWindow", "7", nullptr));
        th_fir->setText(QApplication::translate("MainWindow", "16", nullptr));
        four_fir->setText(QApplication::translate("MainWindow", "21", nullptr));
        six_fir->setText(QApplication::translate("MainWindow", "17", nullptr));
        four_sec->setText(QApplication::translate("MainWindow", "15", nullptr));
        fith_sec->setText(QApplication::translate("MainWindow", "43", nullptr));
        six_sec->setText(QApplication::translate("MainWindow", "23", nullptr));
        fir_th->setText(QApplication::translate("MainWindow", "25", nullptr));
        sec_th->setText(QApplication::translate("MainWindow", "3", nullptr));
        four_th->setText(QApplication::translate("MainWindow", "31", nullptr));
        fith_th->setText(QApplication::translate("MainWindow", "17", nullptr));
        six_th->setText(QApplication::translate("MainWindow", "9", nullptr));
        fir_four->setText(QApplication::translate("MainWindow", "13", nullptr));
        sec_four->setText(QApplication::translate("MainWindow", "10", nullptr));
        th_four->setText(QApplication::translate("MainWindow", "27", nullptr));
        fith_four->setText(QApplication::translate("MainWindow", "33", nullptr));
        six_four->setText(QApplication::translate("MainWindow", "12", nullptr));
        fir_fith->setText(QApplication::translate("MainWindow", "9", nullptr));
        sec_fith->setText(QApplication::translate("MainWindow", "2", nullptr));
        th_fith->setText(QApplication::translate("MainWindow", "19", nullptr));
        six_fith->setText(QApplication::translate("MainWindow", "51", nullptr));
        fir_six->setText(QApplication::translate("MainWindow", "42", nullptr));
        sec_six->setText(QApplication::translate("MainWindow", "17", nullptr));
        th_six->setText(QApplication::translate("MainWindow", "5", nullptr));
        four_six->setText(QApplication::translate("MainWindow", "9", nullptr));
        fir_sec->setText(QApplication::translate("MainWindow", "13", nullptr));
        fith_six->setText(QApplication::translate("MainWindow", "23", nullptr));
        four_fith->setText(QApplication::translate("MainWindow", "14", nullptr));
        th_sec->setText(QApplication::translate("MainWindow", "21", nullptr));
        fith_fir->setText(QApplication::translate("MainWindow", "2", nullptr));
        run->setText(QApplication::translate("MainWindow", "Calculate", nullptr));
        title->setText(QApplication::translate("MainWindow", "\320\242\320\262\320\276\321\200\321\207\320\265\321\201\320\272\320\260\321\217 \321\200\320\260\320\261\320\276\321\202\320\260 \342\204\2262\n"
"\320\227\320\260\320\264\320\260\321\207\320\260 \320\232\320\276\320\274\320\274\320\270\320\262\320\276\321\217\320\266\321\221\321\200\320\260", nullptr));
        sign->setText(QApplication::translate("MainWindow", "\320\222\321\213\320\277\320\276\320\273\320\275\320\270\320\273 \n"
"\321\201\321\202\321\203\320\264\320\265\320\275\321\202 \320\263\321\200\321\203\320\277\320\277\321\213 \320\230\320\222\320\242-20-2\320\221\n"
"\320\242\320\265\320\264\320\265\320\265\320\262 \320\220\320\273\320\265\320\272\321\201\320\260\320\275\320\264\321\200", nullptr));
        date_year->setText(QApplication::translate("MainWindow", "\320\237\320\265\321\200\320\274\321\214, 2021", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
