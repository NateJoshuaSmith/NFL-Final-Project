#ifndef CUSTOMTRIP_2_H
#define CUSTOMTRIP_2_H
#include "customtrip.h"
#include "database.h"
#include <QMainWindow>

namespace Ui {
class customtrip_2;
}

class customtrip_2 : public QMainWindow
{
    Q_OBJECT

public:
    explicit customtrip_2(QWidget *parent = nullptr);
    ~customtrip_2();

private slots:
    void on_comboBox_custom_activated(int index);

    void on_pushButton_2_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_spinBox_valueChanged(int arg1);

    void on_listWidget_custom_3_itemClicked(QListWidgetItem *item);

    void on_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item);

private:
    Ui::customtrip_2 *ui;
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

#endif // CUSTOMTRIP_2_H
