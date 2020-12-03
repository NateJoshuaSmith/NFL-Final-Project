#include "graphtraversals.h"
#include "ui_graphtraversals.h"

graphTraversals::graphTraversals(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::graphTraversals)
{
    ui->setupUi(this);
}

graphTraversals::~graphTraversals()
{
    delete ui;
}
