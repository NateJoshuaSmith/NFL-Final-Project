/********************************************************************************
** Form generated from reading UI file 'admin.ui'
**
** Created by: Qt User Interface Compiler version 5.15.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMIN_H
#define UI_ADMIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_admin
{
public:
    QTabWidget *widget;
    QWidget *tab;
    QTableView *TeamTable;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *Stadium_Name;
    QLineEdit *Seating_Cap_Box;
    QLineEdit *Location_Box;
    QLineEdit *Conference_Box;
    QLineEdit *Division_Box;
    QLineEdit *Surface_Type_Box;
    QLineEdit *Stadium_Roof_Box;
    QLineEdit *Date_Box;
    QLineEdit *Team_Name_Box;
    QComboBox *Team_Name_Combo_Box;
    QLabel *label_10;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *Add_Button;
    QPushButton *Delete_Button;
    QPushButton *Edit_Button;
    QPushButton *Add_expansion_button;
    QPushButton *Remove_expansion_button;
    QLabel *label_15;
    QWidget *tab_2;
    QTableView *souvenir_table;
    QLabel *label_11;
    QComboBox *souvenir_name_combo_box;
    QLineEdit *Namedit;
    QLineEdit *CostEdit;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QComboBox *Team_name_souvenir_box;

    void setupUi(QDialog *admin)
    {
        if (admin->objectName().isEmpty())
            admin->setObjectName(QString::fromUtf8("admin"));
        admin->resize(1124, 525);
        widget = new QTabWidget(admin);
        widget->setObjectName(QString::fromUtf8("widget"));
        widget->setGeometry(QRect(0, 10, 1121, 501));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        TeamTable = new QTableView(tab);
        TeamTable->setObjectName(QString::fromUtf8("TeamTable"));
        TeamTable->setGeometry(QRect(320, 20, 811, 441));
        label = new QLabel(tab);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(10, 40, 81, 16));
        label_2 = new QLabel(tab);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 70, 91, 16));
        label_3 = new QLabel(tab);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 100, 101, 16));
        label_4 = new QLabel(tab);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 130, 61, 16));
        label_5 = new QLabel(tab);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 160, 81, 16));
        label_6 = new QLabel(tab);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 190, 61, 16));
        label_7 = new QLabel(tab);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 220, 91, 16));
        label_8 = new QLabel(tab);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 250, 121, 16));
        label_9 = new QLabel(tab);
        label_9->setObjectName(QString::fromUtf8("label_9"));
        label_9->setGeometry(QRect(10, 280, 111, 16));
        Stadium_Name = new QLineEdit(tab);
        Stadium_Name->setObjectName(QString::fromUtf8("Stadium_Name"));
        Stadium_Name->setGeometry(QRect(160, 70, 151, 20));
        Seating_Cap_Box = new QLineEdit(tab);
        Seating_Cap_Box->setObjectName(QString::fromUtf8("Seating_Cap_Box"));
        Seating_Cap_Box->setGeometry(QRect(160, 100, 151, 20));
        Location_Box = new QLineEdit(tab);
        Location_Box->setObjectName(QString::fromUtf8("Location_Box"));
        Location_Box->setGeometry(QRect(160, 130, 151, 20));
        Conference_Box = new QLineEdit(tab);
        Conference_Box->setObjectName(QString::fromUtf8("Conference_Box"));
        Conference_Box->setGeometry(QRect(160, 160, 151, 20));
        Division_Box = new QLineEdit(tab);
        Division_Box->setObjectName(QString::fromUtf8("Division_Box"));
        Division_Box->setGeometry(QRect(160, 190, 151, 20));
        Surface_Type_Box = new QLineEdit(tab);
        Surface_Type_Box->setObjectName(QString::fromUtf8("Surface_Type_Box"));
        Surface_Type_Box->setGeometry(QRect(160, 220, 151, 20));
        Stadium_Roof_Box = new QLineEdit(tab);
        Stadium_Roof_Box->setObjectName(QString::fromUtf8("Stadium_Roof_Box"));
        Stadium_Roof_Box->setGeometry(QRect(160, 250, 151, 20));
        Date_Box = new QLineEdit(tab);
        Date_Box->setObjectName(QString::fromUtf8("Date_Box"));
        Date_Box->setGeometry(QRect(160, 280, 151, 20));
        Team_Name_Box = new QLineEdit(tab);
        Team_Name_Box->setObjectName(QString::fromUtf8("Team_Name_Box"));
        Team_Name_Box->setGeometry(QRect(160, 40, 151, 20));
        Team_Name_Combo_Box = new QComboBox(tab);
        Team_Name_Combo_Box->setObjectName(QString::fromUtf8("Team_Name_Combo_Box"));
        Team_Name_Combo_Box->setGeometry(QRect(10, 10, 301, 22));
        label_10 = new QLabel(tab);
        label_10->setObjectName(QString::fromUtf8("label_10"));
        label_10->setGeometry(QRect(390, 0, 171, 16));
        layoutWidget = new QWidget(tab);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 320, 295, 30));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        Add_Button = new QPushButton(layoutWidget);
        Add_Button->setObjectName(QString::fromUtf8("Add_Button"));

        horizontalLayout->addWidget(Add_Button);

        Delete_Button = new QPushButton(layoutWidget);
        Delete_Button->setObjectName(QString::fromUtf8("Delete_Button"));

        horizontalLayout->addWidget(Delete_Button);

        Edit_Button = new QPushButton(layoutWidget);
        Edit_Button->setObjectName(QString::fromUtf8("Edit_Button"));

        horizontalLayout->addWidget(Edit_Button);

        Add_expansion_button = new QPushButton(tab);
        Add_expansion_button->setObjectName(QString::fromUtf8("Add_expansion_button"));
        Add_expansion_button->setGeometry(QRect(20, 410, 91, 23));
        Remove_expansion_button = new QPushButton(tab);
        Remove_expansion_button->setObjectName(QString::fromUtf8("Remove_expansion_button"));
        Remove_expansion_button->setGeometry(QRect(130, 410, 131, 23));
        label_15 = new QLabel(tab);
        label_15->setObjectName(QString::fromUtf8("label_15"));
        label_15->setGeometry(QRect(30, 440, 101, 16));
        widget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        souvenir_table = new QTableView(tab_2);
        souvenir_table->setObjectName(QString::fromUtf8("souvenir_table"));
        souvenir_table->setGeometry(QRect(230, 10, 801, 441));
        label_11 = new QLabel(tab_2);
        label_11->setObjectName(QString::fromUtf8("label_11"));
        label_11->setGeometry(QRect(10, 10, 241, 41));
        souvenir_name_combo_box = new QComboBox(tab_2);
        souvenir_name_combo_box->setObjectName(QString::fromUtf8("souvenir_name_combo_box"));
        souvenir_name_combo_box->setGeometry(QRect(50, 120, 111, 22));
        Namedit = new QLineEdit(tab_2);
        Namedit->setObjectName(QString::fromUtf8("Namedit"));
        Namedit->setGeometry(QRect(50, 160, 113, 20));
        CostEdit = new QLineEdit(tab_2);
        CostEdit->setObjectName(QString::fromUtf8("CostEdit"));
        CostEdit->setGeometry(QRect(41, 191, 169, 22));
        label_12 = new QLabel(tab_2);
        label_12->setObjectName(QString::fromUtf8("label_12"));
        label_12->setGeometry(QRect(10, 160, 41, 16));
        label_13 = new QLabel(tab_2);
        label_13->setObjectName(QString::fromUtf8("label_13"));
        label_13->setGeometry(QRect(10, 190, 31, 22));
        label_14 = new QLabel(tab_2);
        label_14->setObjectName(QString::fromUtf8("label_14"));
        label_14->setGeometry(QRect(50, 90, 101, 20));
        pushButton_3 = new QPushButton(tab_2);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(130, 230, 75, 23));
        pushButton_2 = new QPushButton(tab_2);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setGeometry(QRect(40, 230, 75, 23));
        Team_name_souvenir_box = new QComboBox(tab_2);
        Team_name_souvenir_box->setObjectName(QString::fromUtf8("Team_name_souvenir_box"));
        Team_name_souvenir_box->setGeometry(QRect(20, 50, 171, 22));
        widget->addTab(tab_2, QString());

        retranslateUi(admin);

        widget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(admin);
    } // setupUi

    void retranslateUi(QDialog *admin)
    {
        admin->setWindowTitle(QCoreApplication::translate("admin", "Dialog", nullptr));
        label->setText(QCoreApplication::translate("admin", "Team Name:", nullptr));
        label_2->setText(QCoreApplication::translate("admin", "Stadium Name:", nullptr));
        label_3->setText(QCoreApplication::translate("admin", "Seating Capacity:", nullptr));
        label_4->setText(QCoreApplication::translate("admin", "Location:", nullptr));
        label_5->setText(QCoreApplication::translate("admin", "Conference:", nullptr));
        label_6->setText(QCoreApplication::translate("admin", "Division:", nullptr));
        label_7->setText(QCoreApplication::translate("admin", "Surface Type:", nullptr));
        label_8->setText(QCoreApplication::translate("admin", "Stadium Roof Type:", nullptr));
        label_9->setText(QCoreApplication::translate("admin", "Date Opened: ", nullptr));
        label_10->setText(QCoreApplication::translate("admin", "Administration of teams", nullptr));
        Add_Button->setText(QCoreApplication::translate("admin", "Add", nullptr));
        Delete_Button->setText(QCoreApplication::translate("admin", "Delete", nullptr));
        Edit_Button->setText(QCoreApplication::translate("admin", "Edit", nullptr));
        Add_expansion_button->setText(QCoreApplication::translate("admin", "Add expansion", nullptr));
        Remove_expansion_button->setText(QCoreApplication::translate("admin", "Remove Expansion", nullptr));
        label_15->setText(QCoreApplication::translate("admin", "San Diego Sailors", nullptr));
        widget->setTabText(widget->indexOf(tab), QCoreApplication::translate("admin", "Tab 1", nullptr));
        label_11->setText(QCoreApplication::translate("admin", "First select Team then select Souvenir", nullptr));
        label_12->setText(QCoreApplication::translate("admin", "Name:", nullptr));
        label_13->setText(QCoreApplication::translate("admin", "Cost:", nullptr));
        label_14->setText(QCoreApplication::translate("admin", "Souvenir Name:", nullptr));
        pushButton_3->setText(QCoreApplication::translate("admin", "Delete", nullptr));
        pushButton_2->setText(QCoreApplication::translate("admin", "Edit", nullptr));
        widget->setTabText(widget->indexOf(tab_2), QCoreApplication::translate("admin", "Tab 2", nullptr));
    } // retranslateUi

};

namespace Ui {
    class admin: public Ui_admin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMIN_H
