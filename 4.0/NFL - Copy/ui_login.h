/********************************************************************************
** Form generated from reading UI file 'login.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGIN_H
#define UI_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_login
{
public:
    QPushButton *pushButton;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_2;
    QHBoxLayout *horizontalLayout_3;
    QLineEdit *Pass_edit;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QHBoxLayout *horizontalLayout;
    QLineEdit *Useredit;

    void setupUi(QDialog *login)
    {
        if (login->objectName().isEmpty())
            login->setObjectName(QString::fromUtf8("login"));
        login->resize(400, 300);
        pushButton = new QPushButton(login);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(100, 180, 208, 28));
        widget = new QWidget(login);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(100, 80, 210, 96));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label_2 = new QLabel(widget);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_4->addWidget(label_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        Pass_edit = new QLineEdit(widget);
        Pass_edit->setObjectName(QString::fromUtf8("Pass_edit"));

        horizontalLayout_3->addWidget(Pass_edit);


        horizontalLayout_4->addLayout(horizontalLayout_3);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        label = new QLabel(widget);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_2->addWidget(label);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        Useredit = new QLineEdit(widget);
        Useredit->setObjectName(QString::fromUtf8("Useredit"));

        horizontalLayout->addWidget(Useredit);


        horizontalLayout_2->addLayout(horizontalLayout);


        verticalLayout->addLayout(horizontalLayout_2);


        retranslateUi(login);

        QMetaObject::connectSlotsByName(login);
    } // setupUi

    void retranslateUi(QDialog *login)
    {
        login->setWindowTitle(QCoreApplication::translate("login", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("login", "Login", nullptr));
        label_2->setText(QCoreApplication::translate("login", "Username:", nullptr));
        label->setText(QCoreApplication::translate("login", "Password:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class login: public Ui_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGIN_H
