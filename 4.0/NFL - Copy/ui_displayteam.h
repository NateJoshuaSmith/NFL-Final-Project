/********************************************************************************
** Form generated from reading UI file 'displayteam.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DISPLAYTEAM_H
#define UI_DISPLAYTEAM_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_displayteam
{
public:
    QWidget *centralwidget;
    QLabel *label_2;
    QListWidget *listWidget_5;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_4;
    QComboBox *comboBoxTraversals_3;
    QListWidget *listWidget_4;
    QListWidget *totalDistance;
    QLabel *label_4;
    QWidget *layoutWidget_2;
    QVBoxLayout *verticalLayout_2;
    QComboBox *comboBoxTraversals;
    QListWidget *listWidget_2;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *displayteam)
    {
        if (displayteam->objectName().isEmpty())
            displayteam->setObjectName(QString::fromUtf8("displayteam"));
        displayteam->resize(1051, 580);
        centralwidget = new QWidget(displayteam);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 10, 311, 16));
        listWidget_5 = new QListWidget(centralwidget);
        listWidget_5->setObjectName(QString::fromUtf8("listWidget_5"));
        listWidget_5->setGeometry(QRect(20, 260, 381, 121));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(21, 31, 381, 221));
        verticalLayout_5 = new QVBoxLayout(layoutWidget);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(0, 0, 0, 0);
        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        comboBoxTraversals_3 = new QComboBox(layoutWidget);
        comboBoxTraversals_3->setObjectName(QString::fromUtf8("comboBoxTraversals_3"));

        verticalLayout_4->addWidget(comboBoxTraversals_3);


        verticalLayout_5->addLayout(verticalLayout_4);

        listWidget_4 = new QListWidget(layoutWidget);
        listWidget_4->setObjectName(QString::fromUtf8("listWidget_4"));

        verticalLayout_5->addWidget(listWidget_4);

        totalDistance = new QListWidget(centralwidget);
        totalDistance->setObjectName(QString::fromUtf8("totalDistance"));
        totalDistance->setGeometry(QRect(480, 480, 171, 31));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(460, 10, 231, 16));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(460, 40, 571, 431));
        verticalLayout_2 = new QVBoxLayout(layoutWidget_2);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        comboBoxTraversals = new QComboBox(layoutWidget_2);
        comboBoxTraversals->setObjectName(QString::fromUtf8("comboBoxTraversals"));

        verticalLayout_2->addWidget(comboBoxTraversals);

        listWidget_2 = new QListWidget(layoutWidget_2);
        listWidget_2->setObjectName(QString::fromUtf8("listWidget_2"));

        verticalLayout_2->addWidget(listWidget_2);

        displayteam->setCentralWidget(centralwidget);
        menubar = new QMenuBar(displayteam);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 1051, 26));
        displayteam->setMenuBar(menubar);
        statusbar = new QStatusBar(displayteam);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        displayteam->setStatusBar(statusbar);

        retranslateUi(displayteam);

        QMetaObject::connectSlotsByName(displayteam);
    } // setupUi

    void retranslateUi(QMainWindow *displayteam)
    {
        displayteam->setWindowTitle(QCoreApplication::translate("displayteam", "MainWindow", nullptr));
        label_2->setText(QCoreApplication::translate("displayteam", "Display information & souvenirs related to one team:", nullptr));
        label_4->setText(QCoreApplication::translate("displayteam", "BFS, DFS, MST:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class displayteam: public Ui_displayteam {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DISPLAYTEAM_H
