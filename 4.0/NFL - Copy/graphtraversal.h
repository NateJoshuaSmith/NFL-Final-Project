#ifndef GRAPHTRAVERSAL_H
#define GRAPHTRAVERSAL_H

#include <QMainWindow>

namespace Ui {
class graphtraversal;
}

class graphtraversal : public QMainWindow
{
    Q_OBJECT

public:
    explicit graphtraversal(QWidget *parent = nullptr);
    ~graphtraversal();

private:
    Ui::graphtraversal *ui;
};

#endif // GRAPHTRAVERSAL_H
