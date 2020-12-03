/********************************************************************************
** Form generated from reading UI file 'customtrip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIP_H
#define UI_CUSTOMTRIP_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customtrip
{
public:
    QWidget *centralwidget;
    QListWidget *listWidget_custom_2;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *comboBox_custom;
    QListWidget *listWidget_custom;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QListWidget *listWidget_custom_6;
    QLabel *label_4;
    QLabel *label_5;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QSpinBox *spinBox;
    QLabel *label_6;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_custom_4;
    QListWidget *listWidget_custom_7;
    QWidget *layoutWidget2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_custom_3;
    QListWidget *listWidget_custom_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *customtrip)
    {
        if (customtrip->objectName().isEmpty())
            customtrip->setObjectName(QString::fromUtf8("customtrip"));
        customtrip->resize(934, 615);
        centralwidget = new QWidget(customtrip);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        listWidget_custom_2 = new QListWidget(centralwidget);
        listWidget_custom_2->setObjectName(QString::fromUtf8("listWidget_custom_2"));
        listWidget_custom_2->setGeometry(QRect(30, 30, 651, 181));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 50, 201, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        comboBox_custom = new QComboBox(layoutWidget);
        comboBox_custom->setObjectName(QString::fromUtf8("comboBox_custom"));

        verticalLayout->addWidget(comboBox_custom);

        listWidget_custom = new QListWidget(layoutWidget);
        listWidget_custom->setObjectName(QString::fromUtf8("listWidget_custom"));

        verticalLayout->addWidget(listWidget_custom);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 10, 291, 16));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 250, 291, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 30, 291, 16));
        listWidget_custom_6 = new QListWidget(centralwidget);
        listWidget_custom_6->setObjectName(QString::fromUtf8("listWidget_custom_6"));
        listWidget_custom_6->setGeometry(QRect(550, 280, 371, 201));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(690, 260, 291, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(550, 490, 291, 16));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 510, 161, 28));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 500, 115, 28));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(220, 240, 42, 22));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 250, 291, 16));
        layoutWidget1 = new QWidget(centralwidget);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(570, 510, 291, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget1);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_custom_4 = new QListWidget(layoutWidget1);
        listWidget_custom_4->setObjectName(QString::fromUtf8("listWidget_custom_4"));

        horizontalLayout->addWidget(listWidget_custom_4);

        listWidget_custom_7 = new QListWidget(layoutWidget1);
        listWidget_custom_7->setObjectName(QString::fromUtf8("listWidget_custom_7"));

        horizontalLayout->addWidget(listWidget_custom_7);

        layoutWidget2 = new QWidget(centralwidget);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 270, 521, 221));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget_custom_3 = new QListWidget(layoutWidget2);
        listWidget_custom_3->setObjectName(QString::fromUtf8("listWidget_custom_3"));

        horizontalLayout_2->addWidget(listWidget_custom_3);

        listWidget_custom_5 = new QListWidget(layoutWidget2);
        listWidget_custom_5->setObjectName(QString::fromUtf8("listWidget_custom_5"));

        horizontalLayout_2->addWidget(listWidget_custom_5);

        customtrip->setCentralWidget(centralwidget);
        menubar = new QMenuBar(customtrip);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 934, 26));
        customtrip->setMenuBar(menubar);
        statusbar = new QStatusBar(customtrip);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        customtrip->setStatusBar(statusbar);

        retranslateUi(customtrip);

        QMetaObject::connectSlotsByName(customtrip);
    } // setupUi

    void retranslateUi(QMainWindow *customtrip)
    {
        customtrip->setWindowTitle(QCoreApplication::translate("customtrip", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("customtrip", "Current Stadium: ", nullptr));
        label_2->setText(QCoreApplication::translate("customtrip", "Souvenirs:                         ", nullptr));
        label_3->setText(QCoreApplication::translate("customtrip", "Choose teams to travel to:", nullptr));
        label_4->setText(QCoreApplication::translate("customtrip", "Final receipt:", nullptr));
        label_5->setText(QCoreApplication::translate("customtrip", "Total miles:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("customtrip", "Finish", nullptr));
        pushButton_3->setText(QCoreApplication::translate("customtrip", "Start / Next city", nullptr));
        label_6->setText(QCoreApplication::translate("customtrip", "Selected items:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customtrip: public Ui_customtrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIP_H
