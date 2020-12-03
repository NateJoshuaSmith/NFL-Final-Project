#ifndef BFS_DFS_H
#define BFS_DFS_H

#include <QWidget>

namespace Ui {
class BFS_DFS;
}

class BFS_DFS : public QWidget
{
    Q_OBJECT

public:
    explicit BFS_DFS(QWidget *parent = nullptr);
    ~BFS_DFS();

private:
    Ui::BFS_DFS *ui;
};

#endif // BFS_DFS_H
