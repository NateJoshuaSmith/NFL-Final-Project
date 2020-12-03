/********************************************************************************
** Form generated from reading UI file 'dijkstra.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRA_H
#define UI_DIJKSTRA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dijkstra
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dijkstra)
    {
        if (dijkstra->objectName().isEmpty())
            dijkstra->setObjectName(QString::fromUtf8("dijkstra"));
        dijkstra->resize(800, 600);
        menubar = new QMenuBar(dijkstra);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        dijkstra->setMenuBar(menubar);
        centralwidget = new QWidget(dijkstra);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dijkstra->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(dijkstra);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dijkstra->setStatusBar(statusbar);

        retranslateUi(dijkstra);

        QMetaObject::connectSlotsByName(dijkstra);
    } // setupUi

    void retranslateUi(QMainWindow *dijkstra)
    {
        dijkstra->setWindowTitle(QCoreApplication::translate("dijkstra", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dijkstra: public Ui_dijkstra {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRA_H
