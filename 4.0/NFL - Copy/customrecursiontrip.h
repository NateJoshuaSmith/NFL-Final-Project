#ifndef CUSTOMRECURSIONTRIP_H
#define CUSTOMRECURSIONTRIP_H
#include "traversals.h"
#include "database.h"
#include <QMainWindow>
#include <QListWidget>

namespace Ui {
class customrecursiontrip;
}

class customrecursiontrip : public QMainWindow
{
    Q_OBJECT

public:
    explicit customrecursiontrip(QWidget *parent = nullptr);
    ~customrecursiontrip();

private slots:
    void on_recursive_comboBox_custom_activated(int index);

    void on_recursive_pushButton_5_clicked();

    void recursiveShortestPath(int closestTeam, std::vector<QString> temp, std::vector<std::vector<int>> thisMatrix, int start, std::vector<int> &selected, int &total);

    void on_recursive_pushButton_3_clicked();

    void on_recursive_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_recursive_listWidget_custom_3_itemClicked(QListWidgetItem *item);

    void on_recursive_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::customrecursiontrip *ui;
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
    float finalTotal = 0;
    int numItemBought = 0;
};

#endif // CUSTOMRECURSIONTRIP_H
