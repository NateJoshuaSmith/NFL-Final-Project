#include "login.h"
#include "ui_login.h"
#include "admin.h"

login::login(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
}

login::~login()
{
    delete ui;
}

void login::on_pushButton_clicked(bool checked)
{

}

void login::on_pushButton_clicked()
{
    if (ui->Useredit->text() == "admin" && ui->Pass_edit->text() == "admin" )
    {
        admin adminwindow;
        adminwindow.setModal(true);
        adminwindow.exec();
    }
}
