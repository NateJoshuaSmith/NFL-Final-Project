#ifndef DIJKSTRATRIP_H
#define DIJKSTRATRIP_H
#include <QMainWindow>
#include "customtrip.h"

namespace Ui {
class dijkstratrip;
}

class dijkstratrip : public QMainWindow
{
    Q_OBJECT

public:
    explicit dijkstratrip(QWidget *parent = nullptr);
    ~dijkstratrip();

private:
    Ui::dijkstratrip *ui;
    std::vector<std::vector<int>> adjacencyMatrix;
    std::vector<teamInformation> team;

};

#endif // DIJKSTRATRIP_H
