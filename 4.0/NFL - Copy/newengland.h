#ifndef NEWENGLAND_H
#define NEWENGLAND_H
#include "database.h"
#include "traversals.h"
#include <QMainWindow>
#include <QListWidget>

namespace Ui {
class newengland;
}

class newengland : public QMainWindow
{
    Q_OBJECT

public:
    explicit newengland(QWidget *parent = nullptr);
    ~newengland();

private slots:
    void on_newEngland_pushButton_3_clicked();

    void on_newEngland_pushButton_4_clicked();

    void on_newEngland_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item);

    void on_newEngland_spinBox_valueChanged(int arg1);

    void on_newEngland_listWidget_custom_3_itemClicked(QListWidgetItem *item);

private:
    Ui::newengland *ui;
    std::vector<teamInformation> team;
    std::vector<teamInformation> trip;
    std::vector<souvenirs> souvenir;
    std::vector<int> allowed;
    std::vector<std::vector<int>> thisMatrix;
    std::vector<stadiumReciept> stadiumReciept;
    std::vector<int> selected;
    bool checkFirst;
    int totalMiles = 0;
    int count = 0;
    int start = 0;
    int prevIndex = 0;
    bool clicked;
    bool fin;
    float finalRecipet = 0;
    int currStadiumForPrice = 0;
    int itemsBought = 0;
    double finalTotal = 0;
    int numItemBought = 0;
};

#endif // NEWENGLAND_H
