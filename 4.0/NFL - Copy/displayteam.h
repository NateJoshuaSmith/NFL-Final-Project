#ifndef DISPLAYTEAM_H
#define DISPLAYTEAM_H
#include "database.h"
#include <QMainWindow>
#include "traversals.h"

namespace Ui {
class displayteam;
}

class displayteam : public QMainWindow
{
    Q_OBJECT

public:
    explicit displayteam(QWidget *parent = nullptr);
    ~displayteam();

private slots:
    void on_comboBoxTraversals_3_activated(int index);

    void on_comboBoxTraversals_activated(int index);

private:
    Ui::displayteam *ui;
    std::vector<teamInformation> team;
    std::vector<std::vector<int>> thisMatrix;


};

#endif // DISPLAYTEAM_H
