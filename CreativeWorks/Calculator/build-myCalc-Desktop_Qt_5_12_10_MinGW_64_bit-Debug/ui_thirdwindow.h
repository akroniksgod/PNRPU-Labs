/********************************************************************************
** Form generated from reading UI file 'thirdwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_THIRDWINDOW_H
#define UI_THIRDWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_ThirdWindow
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLCDNumber *lcdNumber;
    QLCDNumber *lcdNumber_2;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label;
    QLabel *label_2;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout;
    QPushButton *three;
    QPushButton *null_2;
    QPushButton *seven;
    QPushButton *four;
    QPushButton *plus_minus;
    QPushButton *eight;
    QPushButton *nine;
    QPushButton *five;
    QPushButton *comma;
    QPushButton *one;
    QPushButton *six;
    QPushButton *two;

    void setupUi(QDialog *ThirdWindow)
    {
        if (ThirdWindow->objectName().isEmpty())
            ThirdWindow->setObjectName(QString::fromUtf8("ThirdWindow"));
        ThirdWindow->resize(623, 540);
        verticalLayout = new QVBoxLayout(ThirdWindow);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        lcdNumber = new QLCDNumber(ThirdWindow);
        lcdNumber->setObjectName(QString::fromUtf8("lcdNumber"));

        horizontalLayout_2->addWidget(lcdNumber);

        lcdNumber_2 = new QLCDNumber(ThirdWindow);
        lcdNumber_2->setObjectName(QString::fromUtf8("lcdNumber_2"));

        horizontalLayout_2->addWidget(lcdNumber_2);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label = new QLabel(ThirdWindow);
        label->setObjectName(QString::fromUtf8("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(18);
        label->setFont(font);

        horizontalLayout_3->addWidget(label, 0, Qt::AlignRight);

        label_2 = new QLabel(ThirdWindow);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout_3->addWidget(label_2, 0, Qt::AlignRight);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        verticalLayout->addItem(horizontalSpacer);

        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setHorizontalSpacing(2);
        gridLayout->setVerticalSpacing(9);
        gridLayout->setContentsMargins(0, -1, -1, -1);
        three = new QPushButton(ThirdWindow);
        three->setObjectName(QString::fromUtf8("three"));
        QFont font1;
        font1.setFamily(QString::fromUtf8("Times New Roman"));
        font1.setPointSize(14);
        three->setFont(font1);

        gridLayout->addWidget(three, 2, 3, 1, 1);

        null_2 = new QPushButton(ThirdWindow);
        null_2->setObjectName(QString::fromUtf8("null_2"));
        null_2->setFont(font1);

        gridLayout->addWidget(null_2, 3, 2, 1, 1);

        seven = new QPushButton(ThirdWindow);
        seven->setObjectName(QString::fromUtf8("seven"));
        seven->setFont(font1);

        gridLayout->addWidget(seven, 0, 0, 1, 1);

        four = new QPushButton(ThirdWindow);
        four->setObjectName(QString::fromUtf8("four"));
        four->setFont(font1);

        gridLayout->addWidget(four, 1, 0, 1, 1);

        plus_minus = new QPushButton(ThirdWindow);
        plus_minus->setObjectName(QString::fromUtf8("plus_minus"));
        plus_minus->setFont(font1);

        gridLayout->addWidget(plus_minus, 3, 0, 1, 1);

        eight = new QPushButton(ThirdWindow);
        eight->setObjectName(QString::fromUtf8("eight"));
        eight->setFont(font1);

        gridLayout->addWidget(eight, 0, 2, 1, 1);

        nine = new QPushButton(ThirdWindow);
        nine->setObjectName(QString::fromUtf8("nine"));
        nine->setFont(font1);

        gridLayout->addWidget(nine, 0, 3, 1, 1);

        five = new QPushButton(ThirdWindow);
        five->setObjectName(QString::fromUtf8("five"));
        five->setFont(font1);

        gridLayout->addWidget(five, 1, 2, 1, 1);

        comma = new QPushButton(ThirdWindow);
        comma->setObjectName(QString::fromUtf8("comma"));
        comma->setFont(font1);

        gridLayout->addWidget(comma, 3, 3, 1, 1);

        one = new QPushButton(ThirdWindow);
        one->setObjectName(QString::fromUtf8("one"));
        one->setFont(font1);

        gridLayout->addWidget(one, 2, 0, 1, 1);

        six = new QPushButton(ThirdWindow);
        six->setObjectName(QString::fromUtf8("six"));
        six->setFont(font1);

        gridLayout->addWidget(six, 1, 3, 1, 1);

        two = new QPushButton(ThirdWindow);
        two->setObjectName(QString::fromUtf8("two"));
        two->setFont(font1);

        gridLayout->addWidget(two, 2, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);


        retranslateUi(ThirdWindow);

        QMetaObject::connectSlotsByName(ThirdWindow);
    } // setupUi

    void retranslateUi(QDialog *ThirdWindow)
    {
        ThirdWindow->setWindowTitle(QApplication::translate("ThirdWindow", "Dialog", nullptr));
        label->setText(QApplication::translate("ThirdWindow", "\320\223\321\200\320\260\320\264\321\203\321\201\321\213", nullptr));
        label_2->setText(QApplication::translate("ThirdWindow", "\320\240\320\260\320\264\320\270\320\260\320\275\321\213", nullptr));
        three->setText(QApplication::translate("ThirdWindow", "3", nullptr));
        null_2->setText(QApplication::translate("ThirdWindow", "0", nullptr));
        seven->setText(QApplication::translate("ThirdWindow", "7", nullptr));
        four->setText(QApplication::translate("ThirdWindow", "4", nullptr));
        plus_minus->setText(QApplication::translate("ThirdWindow", "+/-", nullptr));
        eight->setText(QApplication::translate("ThirdWindow", "8", nullptr));
        nine->setText(QApplication::translate("ThirdWindow", "9", nullptr));
        five->setText(QApplication::translate("ThirdWindow", "5", nullptr));
        comma->setText(QApplication::translate("ThirdWindow", ",", nullptr));
        one->setText(QApplication::translate("ThirdWindow", "1", nullptr));
        six->setText(QApplication::translate("ThirdWindow", "6", nullptr));
        two->setText(QApplication::translate("ThirdWindow", "2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ThirdWindow: public Ui_ThirdWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_THIRDWINDOW_H
