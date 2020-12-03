#include "graphtraversal.h"
#include "ui_graphtraversal.h"

graphtraversal::graphtraversal(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::graphtraversal)
{
    ui->setupUi(this);
}

graphtraversal::~graphtraversal()
{
    delete ui;
}
