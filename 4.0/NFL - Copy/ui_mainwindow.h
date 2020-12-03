/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QListWidget *totalDistance;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_3;
    QComboBox *comboBoxTraversals_2;
    QListWidget *listWidget_3;
    QLabel *label;
    QPushButton *pushButton_4;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QPushButton *pushButton_5;
    QPushButton *pushButton;
    QPushButton *pushButton_6;
    QPushButton *pushButton_2;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_6;
    QPushButton *Edit_button;
    QPushButton *pushButton_3;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1395, 577);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        totalDistance = new QListWidget(centralwidget);
        totalDistance->setObjectName(QString::fromUtf8("totalDistance"));
        totalDistance->setGeometry(QRect(920, 1000, 171, 31));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 30, 1121, 491));
        verticalLayout_3 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        comboBoxTraversals_2 = new QComboBox(layoutWidget_2);
        comboBoxTraversals_2->setObjectName(QString::fromUtf8("comboBoxTraversals_2"));

        verticalLayout_3->addWidget(comboBoxTraversals_2);

        listWidget_3 = new QListWidget(layoutWidget_2);
        listWidget_3->setObjectName(QString::fromUtf8("listWidget_3"));

        verticalLayout_3->addWidget(listWidget_3);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 10, 141, 16));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(1170, 330, 161, 28));
        widget = new QWidget(centralwidget);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(1170, 170, 159, 135));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        pushButton_5 = new QPushButton(widget);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        verticalLayout->addWidget(pushButton_5);

        pushButton = new QPushButton(widget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        verticalLayout->addWidget(pushButton);

        pushButton_6 = new QPushButton(widget);
        pushButton_6->setObjectName(QString::fromUtf8("pushButton_6"));

        verticalLayout->addWidget(pushButton_6);

        pushButton_2 = new QPushButton(widget);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        verticalLayout->addWidget(pushButton_2);

        widget1 = new QWidget(centralwidget);
        widget1->setObjectName(QString::fromUtf8("widget1"));
        widget1->setGeometry(QRect(1290, 40, 95, 65));
        verticalLayout_6 = new QVBoxLayout(widget1);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        verticalLayout_6->setContentsMargins(0, 0, 0, 0);
        Edit_button = new QPushButton(widget1);
        Edit_button->setObjectName(QString::fromUtf8("Edit_button"));

        verticalLayout_6->addWidget(Edit_button);

        pushButton_3 = new QPushButton(widget1);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        verticalLayout_6->addWidget(pushButton_3);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1395, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Filter team information:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "Team Info / Traversals", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "New England Patriots Trip", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "Custom Trip(In-Order)", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "Custom Trip (Closest)", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "Green Bay Packers Trip", nullptr));
        Edit_button->setText(QCoreApplication::translate("MainWindow", "Edit", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "Reload", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
