#ifndef GRAPHTRAVERSALS_H
#define GRAPHTRAVERSALS_H

#include <QWidget>

namespace Ui {
class graphTraversals;
}

class graphTraversals : public QWidget
{
    Q_OBJECT

public:
    explicit graphTraversals(QWidget *parent = nullptr);
    ~graphTraversals();

private:
    Ui::graphTraversals *ui;
};

#endif // GRAPHTRAVERSALS_H
