#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QMainWindow>
#include "graphtraversals.h"
#include "customtrip.h"
#include "customtrip_2.h"
#include "customrecursiontrip.h"
#include "newengland.h"
#include "displayteam.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    void setMatrix(std::vector<std::vector<int>> matrix);
    std::vector<std::vector<int>> getMatrix(){return thisMatrix;};
    std::vector<teamInformation> getTeam() {return team;};

    ~MainWindow();

private slots:
    void on_pushButton_clicked();

//    void on_comboBoxTraversals_2_activated(int index);

//    void on_comboBoxTraversals_3_activated(int index);

    void on_pushButton_2_clicked();



    void on_Edit_button_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_comboBoxTraversals_2_activated(int index);

private:
    Ui::MainWindow *ui;
    MainWindow *main;
    graphTraversals *traversal;
    customtrip *cust;
    std::vector<std::vector<int>> thisMatrix;
    std::vector<teamInformation> team;
    QString size;
    int index = 0;
};

#endif // MAINWINDOW_H
