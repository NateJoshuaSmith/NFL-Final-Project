#ifndef DIJKSTRA_H
#define DIJKSTRA_H
#include "customtrip.h"
#include <QMainWindow>

namespace Ui {
class dijkstra;
}

class dijkstraFunc : public QMainWindow
{
    Q_OBJECT

public:
    explicit dijkstraFunc(QWidget *parent = nullptr);

};

#endif // DIJKSTRA_H
