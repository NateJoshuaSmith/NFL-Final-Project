/********************************************************************************
** Form generated from reading UI file 'dijkstratrip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRATRIP_H
#define UI_DIJKSTRATRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dijkstratrip
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dijkstratrip)
    {
        if (dijkstratrip->objectName().isEmpty())
            dijkstratrip->setObjectName(QString::fromUtf8("dijkstratrip"));
        dijkstratrip->resize(800, 600);
        menubar = new QMenuBar(dijkstratrip);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        dijkstratrip->setMenuBar(menubar);
        centralwidget = new QWidget(dijkstratrip);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dijkstratrip->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(dijkstratrip);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dijkstratrip->setStatusBar(statusbar);

        retranslateUi(dijkstratrip);

        QMetaObject::connectSlotsByName(dijkstratrip);
    } // setupUi

    void retranslateUi(QMainWindow *dijkstratrip)
    {
        dijkstratrip->setWindowTitle(QCoreApplication::translate("dijkstratrip", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dijkstratrip: public Ui_dijkstratrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRATRIP_H
