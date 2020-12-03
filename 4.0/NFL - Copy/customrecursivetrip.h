#ifndef CUSTOMRECURSIVETRIP_H
#define CUSTOMRECURSIVETRIP_H
#include "database.h"
#include "traversals.h"
#include <QListWidget>
#include <QMainWindow>

namespace Ui {
class customrecursivetrip;
}

class customrecursivetrip : public QMainWindow
{
    Q_OBJECT

public:
    explicit customrecursivetrip(QWidget *parent = nullptr);
    ~customrecursivetrip();

    void on_comboBox_custom_activated(int index);

    void on_listWidget_custom_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_5_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_listWidget_custom_3_itemClicked(QListWidgetItem *item);


private slots:
    void on_recursive_comboBox_custom_activated(int index);

private:
    Ui::customrecursivetrip *ui;
    std::vector<teamInformation> team;
    std::vector<teamInformation> trip;
    std::vector<souvenirs> souvenir;
    std::vector<int> allowed;
    std::vector<std::vector<int>> thisMatrix;
    std::vector<stadiumReciept> stadiumReciept;
    bool checkFirst;
    int totalMiles;
    int count;
    int start;
    int prevIndex;
    bool clicked;
    bool fin;
    float finalRecipet;
    int currStadiumForPrice;
    int itemsBought;
    float finalTotal;
    int numItemBought;
};

#endif // CUSTOMRECURSIVETRIP_H
