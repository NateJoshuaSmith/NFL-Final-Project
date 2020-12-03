/********************************************************************************
** Form generated from reading UI file 'graphtraversal.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRAPHTRAVERSAL_H
#define UI_GRAPHTRAVERSAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_graphtraversal
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *graphtraversal)
    {
        if (graphtraversal->objectName().isEmpty())
            graphtraversal->setObjectName(QString::fromUtf8("graphtraversal"));
        graphtraversal->resize(800, 600);
        menubar = new QMenuBar(graphtraversal);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        graphtraversal->setMenuBar(menubar);
        centralwidget = new QWidget(graphtraversal);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        graphtraversal->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(graphtraversal);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        graphtraversal->setStatusBar(statusbar);

        retranslateUi(graphtraversal);

        QMetaObject::connectSlotsByName(graphtraversal);
    } // setupUi

    void retranslateUi(QMainWindow *graphtraversal)
    {
        graphtraversal->setWindowTitle(QCoreApplication::translate("graphtraversal", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class graphtraversal: public Ui_graphtraversal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRAPHTRAVERSAL_H
