#ifndef DIJKSTRASTRIP_H
#define DIJKSTRASTRIP_H
#include "customtrip.h"
#include <QMainWindow>

namespace Ui {
class dijkstrasTrip;
}

class dijkstrasTrip : public QMainWindow
{
    Q_OBJECT

public:
    explicit dijkstrasTrip(QWidget *parent = nullptr);
    ~dijkstrasTrip();

};

#endif // DIJKSTRASTRIP_H
