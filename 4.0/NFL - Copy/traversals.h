#ifndef TRAVERSALS_H
#define TRAVERSALS_H
#include <QVector>
#include "database.h"

struct mstValues
{
    QString start;
    QString end;
    int distance;
    int total;
};

bool greaterThen( const QStringList& v1, const QStringList& v2 );
int getStadium(QString stadiumName);
int getTeamName(QString teamName);
QString getCity(int cityIndex);
bool contains (std::vector<int> vector, int value);
std::vector<QString> BFS(std::vector<std::vector<int>> adjacencyMatrix, int start, int d, int f, std::vector<int> &tripOrder);
int DFS(int start, std::vector<bool>& visited, std::vector<std::vector<int>> adjacencyMatrix, std::vector<QString> &tripOrder, int &totalMiles);
void populateMatrix(std::vector<std::vector<int>> &adjacencyMatrix, QSqlQuery query);
void printAdjMatrix(std::vector<std::vector<int>>& adjacencyMatrix);
std::vector<QString> dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int start, int endingVertex, int &total);
int getClosestTeam(std::vector<std::vector<int>> adjacencyMatrix, int start, std::vector<int> &selected);
std::vector<QString> printSolution(int dist[], int start, int parent[], int endingVertex, int &total);
void printPath(int parent[], int j, std::vector<int> &path);
int shortestDistance(int dist[], bool adj[], std::vector<int> &order);
std::vector<mstValues> primMST(std::vector<std::vector<int>> adjacencyMatrix);
std::vector<mstValues> printMST(int parent[], std::vector<std::vector<int>> adjacencyMatrix);
int minKey(int key[], bool mstSet[]);
int getCustomClosestCityIndex(std::vector<std::vector<int>> adjMatrix, int start, std::vector<int> allowed);
void getShortestTrip(std::vector<std::vector<int>> adjMatrix, std::vector<int>& trip, std::vector<int>& allowed);


#endif // TRAVERSALS_H

//int getTeamIndex(QString cityIndex);
