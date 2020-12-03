#include "login.h"
#include "admin.h"
#include "user.h"
#include "database.h"
#include "traversals.h"
#include "mainwindow.h"
#include "customtrip_2.h"
#include <iostream>

#include <QApplication>

int main(int argc, char *argv[])
{
    Database::getInstance();
    int f = 999999;
    int d = 999999;
    int totalMiles = 0;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<int> tripOrder;
    std::vector<QString> tripOrder2;

    std::vector<bool> visited(32, false);

    QSqlQuery query;
    query.prepare("SELECT * FROM Distances ");
    query.exec();
    query.next();

    populateMatrix(adjacencyMatrix, query);

    //do not change
    QApplication a(argc, argv);
    MainWindow s;
    customtrip_2 t;
    s.setMatrix(adjacencyMatrix);
    s.show();
    login w;
    return a.exec();
}
