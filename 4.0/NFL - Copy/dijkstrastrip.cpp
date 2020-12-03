#include "dijkstrastrip.h"
#include "ui_dijkstrastrip.h"

dijkstrasTrip::dijkstrasTrip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dijkstrasTrip)
{
    ui->setupUi(this);
}

dijkstrasTrip::~dijkstrasTrip()
{
    delete ui;
}
