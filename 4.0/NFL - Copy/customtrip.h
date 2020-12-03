#ifndef CUSTOMTRIP_H
#define CUSTOMTRIP_H
#include <QMainWindow>
#include <QListWidget>
#include "database.h"

namespace Ui {
class customtrip;
}

class customtrip : public QMainWindow
{
    Q_OBJECT

public:
    explicit customtrip(QWidget *parent = nullptr);
    ~customtrip();

private slots:
    void on_comboBox_custom_activated(int index);

    void on_listWidget_custom_2_itemClicked(QListWidgetItem *item);

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item);

    void on_pushButton_5_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_listWidget_custom_3_itemClicked(QListWidgetItem *item);

private:
    Ui::customtrip *ui;
    std::vector<teamInformation> team;
    std::vector<teamInformation> trip;
    std::vector<souvenirs> souvenir;
    std::vector<int> allowed;
    std::vector<std::vector<int>> thisMatrix;
    std::vector<stadiumReciept> stadiumReciept;
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

#endif // CUSTOMTRIP_H
