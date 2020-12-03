/********************************************************************************
** Form generated from reading UI file 'customrecursiontrip.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CUSTOMRECURSIONTRIP_H
#define UI_CUSTOMRECURSIONTRIP_H

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

class Ui_customrecursiontrip
{
public:
    QWidget *centralwidget;
    QLabel *label_4;
    QPushButton *recursive_pushButton_4;
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *recursive_comboBox_custom;
    QListWidget *recursive_listWidget_custom;
    QLabel *label;
    QSpinBox *spinBox;
    QListWidget *recursive_listWidget_custom_2;
    QPushButton *recursive_pushButton_3;
    QLabel *label_2;
    QListWidget *recursive_listWidget_custom_6;
    QLabel *label_3;
    QLabel *label_5;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_2;
    QListWidget *recursive_listWidget_custom_3;
    QListWidget *recursive_listWidget_custom_5;
    QLabel *label_6;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout;
    QListWidget *recursive_listWidget_custom_4;
    QListWidget *recursive_listWidget_custom_7;
    QPushButton *recursive_pushButton_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *customrecursiontrip)
    {
        if (customrecursiontrip->objectName().isEmpty())
            customrecursiontrip->setObjectName(QString::fromUtf8("customrecursiontrip"));
        customrecursiontrip->resize(949, 660);
        centralwidget = new QWidget(customrecursiontrip);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        label_4 = new QLabel(centralwidget);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(690, 300, 291, 16));
        recursive_pushButton_4 = new QPushButton(centralwidget);
        recursive_pushButton_4->setObjectName(QString::fromUtf8("recursive_pushButton_4"));
        recursive_pushButton_4->setGeometry(QRect(200, 550, 161, 28));
        layoutWidget = new QWidget(centralwidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(700, 90, 201, 201));
        verticalLayout = new QVBoxLayout(layoutWidget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        recursive_comboBox_custom = new QComboBox(layoutWidget);
        recursive_comboBox_custom->setObjectName(QString::fromUtf8("recursive_comboBox_custom"));

        verticalLayout->addWidget(recursive_comboBox_custom);

        recursive_listWidget_custom = new QListWidget(layoutWidget);
        recursive_listWidget_custom->setObjectName(QString::fromUtf8("recursive_listWidget_custom"));

        verticalLayout->addWidget(recursive_listWidget_custom);

        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 50, 291, 16));
        spinBox = new QSpinBox(centralwidget);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(220, 280, 42, 22));
        recursive_listWidget_custom_2 = new QListWidget(centralwidget);
        recursive_listWidget_custom_2->setObjectName(QString::fromUtf8("recursive_listWidget_custom_2"));
        recursive_listWidget_custom_2->setGeometry(QRect(30, 70, 651, 181));
        recursive_pushButton_3 = new QPushButton(centralwidget);
        recursive_pushButton_3->setObjectName(QString::fromUtf8("recursive_pushButton_3"));
        recursive_pushButton_3->setGeometry(QRect(10, 540, 115, 28));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 290, 61, 16));
        recursive_listWidget_custom_6 = new QListWidget(centralwidget);
        recursive_listWidget_custom_6->setObjectName(QString::fromUtf8("recursive_listWidget_custom_6"));
        recursive_listWidget_custom_6->setGeometry(QRect(550, 320, 371, 201));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(700, 70, 291, 16));
        label_5 = new QLabel(centralwidget);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(550, 530, 291, 16));
        layoutWidget_2 = new QWidget(centralwidget);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 310, 521, 221));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        recursive_listWidget_custom_3 = new QListWidget(layoutWidget_2);
        recursive_listWidget_custom_3->setObjectName(QString::fromUtf8("recursive_listWidget_custom_3"));

        horizontalLayout_2->addWidget(recursive_listWidget_custom_3);

        recursive_listWidget_custom_5 = new QListWidget(layoutWidget_2);
        recursive_listWidget_custom_5->setObjectName(QString::fromUtf8("recursive_listWidget_custom_5"));

        horizontalLayout_2->addWidget(recursive_listWidget_custom_5);

        label_6 = new QLabel(centralwidget);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(280, 290, 291, 16));
        layoutWidget_3 = new QWidget(centralwidget);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(570, 550, 291, 41));
        horizontalLayout = new QHBoxLayout(layoutWidget_3);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        recursive_listWidget_custom_4 = new QListWidget(layoutWidget_3);
        recursive_listWidget_custom_4->setObjectName(QString::fromUtf8("recursive_listWidget_custom_4"));

        horizontalLayout->addWidget(recursive_listWidget_custom_4);

        recursive_listWidget_custom_7 = new QListWidget(layoutWidget_3);
        recursive_listWidget_custom_7->setObjectName(QString::fromUtf8("recursive_listWidget_custom_7"));

        horizontalLayout->addWidget(recursive_listWidget_custom_7);

        recursive_pushButton_5 = new QPushButton(centralwidget);
        recursive_pushButton_5->setObjectName(QString::fromUtf8("recursive_pushButton_5"));
        recursive_pushButton_5->setGeometry(QRect(10, 580, 115, 28));
        customrecursiontrip->setCentralWidget(centralwidget);
        menubar = new QMenuBar(customrecursiontrip);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 949, 26));
        customrecursiontrip->setMenuBar(menubar);
        statusbar = new QStatusBar(customrecursiontrip);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        customrecursiontrip->setStatusBar(statusbar);

        retranslateUi(customrecursiontrip);

        QMetaObject::connectSlotsByName(customrecursiontrip);
    } // setupUi

    void retranslateUi(QMainWindow *customrecursiontrip)
    {
        customrecursiontrip->setWindowTitle(QCoreApplication::translate("customrecursiontrip", "MainWindow", nullptr));
        label_4->setText(QCoreApplication::translate("customrecursiontrip", "Final receipt:", nullptr));
        recursive_pushButton_4->setText(QCoreApplication::translate("customrecursiontrip", "Finish", nullptr));
        label->setText(QCoreApplication::translate("customrecursiontrip", "Current Stadium: ", nullptr));
        recursive_pushButton_3->setText(QCoreApplication::translate("customrecursiontrip", "Start / Next city", nullptr));
        label_2->setText(QCoreApplication::translate("customrecursiontrip", "Souvenirs:                         ", nullptr));
        label_3->setText(QCoreApplication::translate("customrecursiontrip", "Choose teams to travel to:", nullptr));
        label_5->setText(QCoreApplication::translate("customrecursiontrip", "Total miles:", nullptr));
        label_6->setText(QCoreApplication::translate("customrecursiontrip", "Selected items:", nullptr));
        recursive_pushButton_5->setText(QCoreApplication::translate("customrecursiontrip", "Calculate Trip", nullptr));
    } // retranslateUi

};

namespace Ui {
    class customrecursiontrip: public Ui_customrecursiontrip {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CUSTOMRECURSIONTRIP_H
