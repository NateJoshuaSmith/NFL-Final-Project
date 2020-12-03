#include "dijkstratrip.h"
#include "ui_dijkstratrip.h"

dijkstratrip::dijkstratrip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::dijkstratrip)
{
    ui->setupUi(this);

    adjacencyMatrix = main->getMatrix();
    team = main->getTeam();

}

dijkstratrip::~dijkstratrip()
{
    delete ui;
}
