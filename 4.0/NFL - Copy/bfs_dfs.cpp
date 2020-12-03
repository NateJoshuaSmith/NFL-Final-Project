#include "bfs_dfs.h"
#include "ui_bfs_dfs.h"

BFS_DFS::BFS_DFS(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::BFS_DFS)
{
    ui->setupUi(this);
}

BFS_DFS::~BFS_DFS()
{
    delete ui;
}
