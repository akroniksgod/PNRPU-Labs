/********************************************************************************
** Form generated from reading UI file 'graph.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPH_H
#define UI_GRAPH_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Graph
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout;
    QLabel *templateForText;
    QVBoxLayout *verticalLayout;
    QLabel *path;
    QLabel *len;
    QGraphicsView *graphicsView;

    void setupUi(QDialog *Graph)
    {
        if (Graph->objectName().isEmpty())
            Graph->setObjectName(QString::fromUtf8("Graph"));
        Graph->resize(700, 580);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/prefix1/pics/4aa534605d1afc465c5bdc5dd80f1ecb.png"), QSize(), QIcon::Normal, QIcon::Off);
        Graph->setWindowIcon(icon);
        horizontalLayout_2 = new QHBoxLayout(Graph);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        templateForText = new QLabel(Graph);
        templateForText->setObjectName(QString::fromUtf8("templateForText"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(templateForText->sizePolicy().hasHeightForWidth());
        templateForText->setSizePolicy(sizePolicy);
        QFont font;
        font.setFamily(QString::fromUtf8("Times New Roman"));
        font.setPointSize(16);
        templateForText->setFont(font);
        templateForText->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);\n"
"border-color: rgb(0, 0, 0);"));

        horizontalLayout->addWidget(templateForText);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        path = new QLabel(Graph);
        path->setObjectName(QString::fromUtf8("path"));
        path->setFont(font);
        path->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(path);

        len = new QLabel(Graph);
        len->setObjectName(QString::fromUtf8("len"));
        len->setFont(font);
        len->setStyleSheet(QString::fromUtf8("color: rgb(0, 0, 0);"));

        verticalLayout->addWidget(len);


        horizontalLayout->addLayout(verticalLayout);


        verticalLayout_2->addLayout(horizontalLayout);

        graphicsView = new QGraphicsView(Graph);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setStyleSheet(QString::fromUtf8("background-color: transparent"));

        verticalLayout_2->addWidget(graphicsView);


        horizontalLayout_2->addLayout(verticalLayout_2);


        retranslateUi(Graph);

        QMetaObject::connectSlotsByName(Graph);
    } // setupUi

    void retranslateUi(QDialog *Graph)
    {
        Graph->setWindowTitle(QApplication::translate("Graph", "Dialog", nullptr));
        templateForText->setText(QApplication::translate("Graph", "\320\237\321\203\321\202\321\214:\n"
"\320\224\320\273\320\270\320\275\320\260 \320\277\321\203\321\202\320\270:", nullptr));
        path->setText(QString());
        len->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class Graph: public Ui_Graph {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPH_H
