/********************************************************************************
** Form generated from reading UI file 'customtrip_2.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMTRIP_2_H
#define UI_CUSTOMTRIP_2_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_customtrip_2
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QLabel *label_3;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QListWidget *listWidget_custom_4;
    QListWidget *listWidget_custom_7;
    QPushButton *pushButton_4;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *listWidget_custom_3;
    QListWidget *listWidget_custom_5;
    QListWidget *listWidget_custom_2;
    QSpinBox *spinBox;
    QLabel *label_5;
    QListWidget *listWidget_custom_6;
    QLabel *label_6;
    QPushButton *pushButton_3;
    QLabel *label_2;
    QComboBox *comboBox_custom;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *customtrip_2)
    {
        if (customtrip_2->objectName().isEmpty())
            customtrip_2->setObjectName(QString::fromUtf8("customtrip_2"));
        customtrip_2->resize(932, 613);
        centralwidget = new QWidget(customtrip_2);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(690, 250, 291, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(50, 0, 291, 16));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(570, 500, 291, 51));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        listWidget_custom_4 = new QListWidget(layoutWidget);
        listWidget_custom_4->setObjectName(QString::fromUtf8("listWidget_custom_4"));

        horizontalLayout->addWidget(listWidget_custom_4);

        listWidget_custom_7 = new QListWidget(layoutWidget);
        listWidget_custom_7->setObjectName(QString::fromUtf8("listWidget_custom_7"));

        horizontalLayout->addWidget(listWidget_custom_7);

        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setGeometry(QRect(200, 500, 161, 28));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 260, 521, 221));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        listWidget_custom_3 = new QListWidget(layoutWidget_2);
        listWidget_custom_3->setObjectName(QString::fromUtf8("listWidget_custom_3"));

        horizontalLayout_2->addWidget(listWidget_custom_3);

        listWidget_custom_5 = new QListWidget(layoutWidget_2);
        listWidget_custom_5->setObjectName(QString::fromUtf8("listWidget_custom_5"));

        horizontalLayout_2->addWidget(listWidget_custom_5);

        listWidget_custom_2 = new QListWidget(centralwidget);
        listWidget_custom_2->setObjectName(QString::fromUtf8("listWidget_custom_2"));
        listWidget_custom_2->setGeometry(QRect(40, 40, 651, 181));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(220, 230, 42, 22));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(550, 480, 291, 16));
        listWidget_custom_6 = new QListWidget(centralwidget);
        listWidget_custom_6->setObjectName(QString::fromUtf8("listWidget_custom_6"));
        listWidget_custom_6->setGeometry(QRect(550, 270, 371, 201));
        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 240, 211, 16));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(10, 490, 115, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 240, 81, 16));
        comboBox_custom = new QComboBox(centralwidget);
        comboBox_custom->setObjectName(QString::fromUtf8("comboBox_custom"));
        comboBox_custom->setGeometry(QRect(40, 20, 651, 22));
        customtrip_2->setCentralWidget(centralwidget);
        menubar = new QMenuBar(customtrip_2);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 932, 26));
        customtrip_2->setMenuBar(menubar);
        statusbar = new QStatusBar(customtrip_2);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        customtrip_2->setStatusBar(statusbar);

        retranslateUi(customtrip_2);

        QMetaObject::connectSlotsByName(customtrip_2);
    } // setupUi

    void retranslateUi(QMainWindow *customtrip_2)
    {
        customtrip_2->setWindowTitle(QCoreApplication::translate("customtrip_2", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("customtrip_2", "Final receipt:", nullptr));
        label_3->setText(QCoreApplication::translate("customtrip_2", "Choose team to travel to:", nullptr));
        pushButton_4->setText(QCoreApplication::translate("customtrip_2", "Finish", nullptr));
        label_5->setText(QCoreApplication::translate("customtrip_2", "Total miles:", nullptr));
        label_6->setText(QCoreApplication::translate("customtrip_2", "Selected items:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("customtrip_2", "Start / Next city", nullptr));
        label_2->setText(QCoreApplication::translate("customtrip_2", "Souvenirs:                         ", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customtrip_2: public Ui_customtrip_2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMTRIP_2_H
