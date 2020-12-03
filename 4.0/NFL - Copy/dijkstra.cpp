#include "dijkstra.h"
#include "ui_dijkstra.h"

dijkstraFunc::dijkstraFunc(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dijkstra)
{
    ui->setupUi(this);
}

dijkstraFunc::~dijkstraFunc()
{
    delete ui;
}
