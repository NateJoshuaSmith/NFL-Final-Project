/********************************************************************************
** Form generated from reading UI file 'dijkstrastrip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIJKSTRASTRIP_H
#define UI_DIJKSTRASTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dijkstrasTrip
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *dijkstrasTrip)
    {
        if (dijkstrasTrip->objectName().isEmpty())
            dijkstrasTrip->setObjectName(QString::fromUtf8("dijkstrasTrip"));
        dijkstrasTrip->resize(800, 600);
        menubar = new QMenuBar(dijkstrasTrip);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        dijkstrasTrip->setMenuBar(menubar);
        centralwidget = new QWidget(dijkstrasTrip);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        dijkstrasTrip->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(dijkstrasTrip);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        dijkstrasTrip->setStatusBar(statusbar);

        retranslateUi(dijkstrasTrip);

        QMetaObject::connectSlotsByName(dijkstrasTrip);
    } // setupUi

    void retranslateUi(QMainWindow *dijkstrasTrip)
    {
        dijkstrasTrip->setWindowTitle(QCoreApplication::translate("dijkstrasTrip", "MainWindow", nullptr));
    } // retranslateUi

};

namespace Ui {
    class dijkstrasTrip: public Ui_dijkstrasTrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIJKSTRASTRIP_H
