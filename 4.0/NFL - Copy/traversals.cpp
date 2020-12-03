#include "traversals.h"
#include <QDebug>
#include <QPair>
#include <QString>
#include <iostream>

bool greaterThen( const QStringList& v1, const QStringList& v2 )
{
    return v1.first() > v2.first();
}

bool contains (std::vector<int> vector, int value)
{
    for(int i = 0; i < vector.size(); i++)
    {
        if (vector[i] == value)
        {
            return true;
        }
    }
    return false;
}

void populateMatrix(std::vector<std::vector<int>> &adjacencyMatrix, QSqlQuery query)
{
    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    std::vector<std::vector<int>> tempMatrix(row_count, std::vector<int>(row_count, 999999));

    QSqlQuery totalTableSize;
    int total_row_count = 0;

     // Run some query
     totalTableSize.exec("SELECT * FROM Distances");

     while(totalTableSize.next())
     {
         total_row_count++;
     }

    for(int i = 0; i < total_row_count; i++)
    {
        tempMatrix[getTeamName(query.value(0).toString())][getStadium(query.value(2).toString())] = query.value(3).toInt();
        if(getStadium(query.value(2).toString()) == 17 || getStadium(query.value(2).toString()) == 23)
        {
             tempMatrix[getTeamName(query.value(0).toString())][(getStadium(query.value(2).toString())) + 1] = query.value(3).toInt();
        }

        query.next();

    }
    adjacencyMatrix = tempMatrix;
}

int shortestDistance(int dist[], bool adj[], std::vector<int> &order)
{
    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    int min = 999999;
    int min_index = -1;
    for (int v = 0; v < row_count; v++)
        if (adj[v] == false && dist[v] <= min)
       {
            min = dist[v];
            min_index = v;
       }
    order.push_back(min_index);
    return min_index;
}

void printPath(int parent[], int j, std::vector<int> &path)
{
 path.push_back(j);
    if (parent[j] == -1)
    {
        return;
    }

      printPath(parent, parent[j], path);

}

std::vector<QString> printSolution(int dist[], int start, int parent[], int endingVertex, int &total)
{
    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    std::vector<QString> trip;
    for (int i = 0; i < row_count; i++)
   {
        if(i == endingVertex)
        {
//           qDebug() << getCity(start) << " " << getCity(i) << " --> " << dist[i] << Qt::endl;
           total = dist[i];

           std::vector<int> path;

           printPath(parent, i, path);

           for (int i = path.size() - 1; i > -1; i--)
           {
               qDebug() << getCity(path[i]);
               trip.push_back(getCity(path[i]));
           }
        }
   }
    return trip;
}

std::vector<QString> dijkstra(std::vector<std::vector<int>> adjacencyMatrix, int start, int endingVertex, int &total)
{

    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    int dist[row_count];
    bool adj[row_count];
    std::vector<QString> trip;

    //
      int parent[row_count];

    for (int i = 0; i < row_count; i++)
   {
        dist[i] = 999999;
        adj[i] = false;
        //
        parent[i] = -1;
   }
    dist[start] = 0;
    std::vector<std::vector<int>> Order;
    std::vector<int> travelOrder;
    for (int count = 0; count < row_count - 1; count++)
   {
        if (count != 0)
       {
            Order.push_back(travelOrder);
       }
        travelOrder.clear();
        travelOrder.push_back(start);
        int shortest = shortestDistance(dist, adj, travelOrder);

        adj[shortest] = true;
        for (int j = 0; j < row_count; j++)
       {
            if (!adj[j] && adjacencyMatrix[shortest][j] && dist[shortest] !=999999 && dist[shortest] + adjacencyMatrix[shortest][j] < dist[j])
           {
                dist[j] = dist[shortest] + adjacencyMatrix[shortest][j];

                //
                parent[j] = shortest;
           }
       }
        if (count == 0)
       {
            Order.push_back(travelOrder);
       }
   }
    trip = printSolution(dist, start, parent, endingVertex, total);

    return trip;
}

int getClosestTeam(std::vector<std::vector<int>> adjacencyMatrix, int start, std::vector<int> &selected)
{
    int minimum = 9999999999999999;
    int closestTeamIndex = -1;
    int total = 0;

    for (int i = 0; i < selected.size(); i++)
    {
        dijkstra(adjacencyMatrix, start, selected[i], total);
        if (minimum > total)
        {
            minimum = total;
            closestTeamIndex = selected[i];
        }
    }

    return closestTeamIndex;
}

int minKey(int key[], bool mstSet[])
{
    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    int min = INT_MAX, min_index;
    for (int v = 0; v < row_count; v++)
        if (mstSet[v] == false && key[v] < min)
            min = key[v], min_index = v;
    return min_index;
}

std::vector<mstValues> printMST(int parent[], std::vector<std::vector<int>> adjacencyMatrix, std::vector<mstValues> cities)
{
    int total = 0;

    std::cout << "\n\n******************** MST ********************\n";
    for (int i = 1; i < adjacencyMatrix.size(); i++)
   {
        mstValues objMst;
        qDebug() << getCity(parent[i]) << " - " << getCity(i);
        qDebug() << " --> " << adjacencyMatrix[i][parent[i]] << " \n";
        total += adjacencyMatrix[i][parent[i]];
        objMst.start = getCity(parent[i]);
        objMst.end = getCity(i);
        objMst.distance = adjacencyMatrix[i][parent[i]];

        cities.push_back(objMst);
   }
    std::cout << "\nTotal Mileage: " << total << std::endl;
    cities[0].total = total;
    return cities;
}

std::vector<mstValues> primMST(std::vector<std::vector<int>> adjacencyMatrix)
{
    int parent[adjacencyMatrix.size()];
    int key[adjacencyMatrix.size()];
    bool mstSet[adjacencyMatrix.size()];
    std::vector<mstValues> cities;

    for (int i = 0; i < adjacencyMatrix.size(); i++)
        key[i] = INT_MAX, mstSet[i] = false;
        key[0] = 0;
        parent[0] = -1;
        for (int count = 0; count < adjacencyMatrix.size() - 1; count++)
       {
            int minimum = minKey(key, mstSet);
            mstSet[minimum] = true;
            for (int v = 0; v < adjacencyMatrix.size(); v++)
            {
                if (adjacencyMatrix[minimum][v] && mstSet[v] == false && adjacencyMatrix[minimum][v] < key[v])
                {
                    parent[v] = minimum, key[v] = adjacencyMatrix[minimum][v];
                }
            }

       }

    cities = printMST(parent, adjacencyMatrix, cities);
    return cities;
}

std::vector<QString> BFS(std::vector<std::vector<int>> adjacencyMatrix, int start, int d, int f, std::vector<int> &tripOrder)
{
    // Visited vector to so that
    // a vertex is not visited more than once
    // Initializing the vector to false as no
    // vertex is visited at the beginning
    std::vector<bool> visited(adjacencyMatrix.size(), false);
    std::vector<QString> cities;
    std::vector<int> q;
    q.push_back(start);

    // Set source as visited
    visited[start] = true;

    std::vector<int> visVec;

    int vis;
    int smallest;
    int totalMileage = 0;


    qDebug() << "Performing BFS" << Qt::endl;

    while (!q.empty()) {
        vis = q[0];
        visVec.push_back(vis);

        std::vector<int> currentCity = adjacencyMatrix[vis];

        cities.push_back(getCity(vis));
        tripOrder.push_back(vis);
        q.erase(q.begin());

        // For every adjacent vertex to the current vertex
        for (int i = 0; i < adjacencyMatrix.size(); i++) {

            //Find the smallest edge in the currentCity vector and set smallest to the index
            std::vector<int>::iterator it;

            it = std::find (currentCity.begin(), currentCity.end(), *min_element(currentCity.begin(), currentCity.end()));
            smallest = it - currentCity.begin();

            currentCity[smallest] = f;

            //If it's an unvisited neighbor
            if (adjacencyMatrix[vis][smallest] != d && adjacencyMatrix[vis][smallest] != f && (!visited[smallest])) {

                if(getCity(smallest) == "MetLife Stadium")
                {
                    visited[23] = true;
                    visited[24] = true;
                }

                // Push the adjacent node to the queue
                q.push_back(smallest);
                qDebug() << Qt::endl << "Discovery edge created from " << getCity(vis) << " to " << getCity(smallest) << Qt::endl;


                totalMileage += adjacencyMatrix[vis][smallest];
                qDebug() << "Total mileage travelled on the discovery edges: " << totalMileage;

                // Set
                visited[smallest] = true;
            }
        }
    }
    qDebug() << Qt::endl << "BFS Complete" << Qt::endl;

    QString convert = QString::number(totalMileage);

    cities.push_back(convert);

    return cities;
}

// Function to perform DFS on the graph
int DFS(int start, std::vector<bool> &visited, std::vector<std::vector<int>> adjacencyMatrix, std::vector<QString> &tripOrder, int &totalMiles)
{
    //We need to find a way to backtrack in the graph for the total mileage
    std::vector<int> adjacentStadiums;
    int smallest = 0;

    // Print the current node
    tripOrder.push_back(getCity(start));

    // Set current node as visited
    visited[start] = true;
    adjacentStadiums = adjacencyMatrix[start];

    for (int i = 0; i < adjacencyMatrix.size(); i++) {

        std::vector<int>::iterator it;

        it = std::find (adjacentStadiums.begin(), adjacentStadiums.end(), *min_element(adjacentStadiums.begin(), adjacentStadiums.end()));
        smallest = it - adjacentStadiums.begin();
        adjacentStadiums[smallest] = 999999;

        // If some node is adjacent to the current node
        // and it has not already been visited
        if (adjacencyMatrix[start][smallest] != 999999 && (!visited[smallest])) {
            totalMiles += adjacencyMatrix[start][smallest];
            DFS(smallest, visited, adjacencyMatrix, tripOrder, totalMiles);
        }
    }

    qDebug() << Qt::endl << "BFS Complete" << Qt::endl;
    qDebug() << "Total mileage travelled on the discovery edges: " << totalMiles;

    return totalMiles;
}

//Function to print the adjacency matrix for error checking
void printAdjMatrix(std::vector<std::vector<int>>& adjacencyMatrix)
{
    for(int i = 0; i < adjacencyMatrix.size(); i ++)
    {
        std::cout << i << " [";
        for(int j = 0; j < adjacencyMatrix.size(); j++)
        {
            std::cout << adjacencyMatrix[i][j];
            if(j != adjacencyMatrix.size()-1)
            {
                std::cout << ", ";
            }
        }
        std::cout << "]" << endl;
    }
}

int getCustomClosestCityIndex(std::vector<std::vector<int>> adjMatrix, int start, std::vector<int> allowed)
{
    int closestDistance = 999999;
    int returnIndex = -1;
    int currentCity = -1;
    for (int j = 0; j < int(allowed.size()); j++)
    {
        currentCity = allowed[j];
            if (adjMatrix[start][currentCity] < closestDistance && adjMatrix[start][currentCity] != 999999)
            {
                    closestDistance = adjMatrix[start][currentCity];
                    returnIndex = currentCity;
            }
    }
    if(returnIndex == -1)
    {
        qDebug() << "getCustomClosestCityIndex has encountered an ERROR";
    }
    return returnIndex;
}

void getShortestTrip(std::vector<std::vector<int>> adjMatrix, std::vector<int>& trip, std::vector<int>& allowed)
    {
        trip.push_back(allowed[0]);

        int nextClosestCity = 0;   //customClosestCityIndex (cities, , allowed);	//define the next closest city

        for(int i = 0; i < int(allowed.size()); i++){
            bool brk = false;
            for(int i = 0; i < adjMatrix.size(); i++){
                if(i == allowed[i]){
                    nextClosestCity = getCustomClosestCityIndex(adjMatrix, i, allowed);
                    allowed.erase(allowed.begin());
                    brk = true;
                    break;
                }
            }
            if(brk) break;
        }

        if(allowed.size() == 0)			//if all of the cities have been added to the trip
        {
            return;
        }

        for(int i = 0; i < int(allowed.size()); i++){
            if(nextClosestCity == allowed[i]){
                std::iter_swap(allowed.begin(), allowed.begin() + i);
                break;
            }
        }

    getShortestTrip(adjMatrix, trip, allowed); //Call getShortestTrip using the next closest city as the startingCity

}

int getTeamName(QString teamName)
{
   if(teamName == "Arizona Cardinals")
   {
       return 0;
   }
   else if(teamName == "Atlanta Falcons")
   {
       return 1;
   }
   else if(teamName == "Baltimore Ravens")
   {
       return 2;
   }
   else if(teamName == "Buffalo Bills")
   {
       return 3;
   }
   else if(teamName == "Carolina Panthers")
   {
       return 4;
   }
   else if(teamName == "Chicago Bears")
   {
       return 5;
   }
   else if(teamName == "Cincinnati Bengals")
   {
       return 6;
   }
   else if(teamName == "Cleveland Browns")
   {
       return 7;
   }
   else if(teamName == "Dallas Cowboys")
   {
       return 8;
   }
   else if(teamName == "Denver Broncos")
   {
       return 9;
   }
   else if(teamName == "Detroit Lions")
   {
       return 10;
   }
   else if(teamName == "Green Bay Packers")
   {
       return 11;
   }
   else if(teamName == "Houston Texans")
   {
       return 12;
   }
   else if(teamName == "Indianapolis Colts")
   {
       return 13;
   }
   else if(teamName == "Jacksonville Jaguars")
   {
       return 14;
   }
   else if(teamName == "Kansas City Chiefs")
   {
       return 15;
   }
   else if(teamName == "Las Vegas Raiders")
   {
       return 16;
   }
   else if(teamName == "Los Angeles Chargers")
   {
       return 17;
   }
   else if(teamName == "Los Angeles Rams")
   {
       return 18;
   }
   else if(teamName == "Miami Dolphins")
   {
       return 19;
   }
   else if(teamName == "Minnesota Vikings")
   {
       return 20;
   }
   else if(teamName == "New England Patriots")
   {
       return 21;
   }
   else if(teamName == "New Orleans Saints")
   {
       return 22;
   }
   else if(teamName == "New York Giants")
   {
       return 23;
   }
   else if(teamName == "New York Jets")
   {
       return 24;
   }
   else if(teamName == "Philadelphia Eagles")
   {
       return 25;
   }
   else if(teamName == "Pittsburgh Steelers")
   {
       return 26;
   }
   else if(teamName == "San Francisco 49ers")
   {
       return 27;
   }
   else if(teamName == "Seattle Seahawks")
   {
       return 28;
   }
   else if(teamName == "Tampa Bay Buccaneers")
   {
       return 29;
   }
   else if(teamName == "Tennessee Titans")
   {
       return 30;
   }
   else if(teamName == "Washington Redskins")
   {
       return 31;
   }
   else if(teamName == "San Diego Sailors")
   {
       return 32;
   }
   qDebug() << "Team" << Qt::endl;

   return -1;
}

int getStadium(QString stadiumName)
{
    if (stadiumName == "State Farm Stadium")
    {
        return 0;
    }
    else if(stadiumName == "Mercedes-Benz Stadium")
    {
        return 1;
    }
    else if(stadiumName == "M&T Bank Stadium")
    {
        return 2;
    }
    else if(stadiumName == "Bills Stadium")
    {
        return 3;
    }
    else if(stadiumName == "Bank of America Stadium")
    {
        return 4;
    }
    else if(stadiumName == "Soldier Field")
    {
        return 5;
    }
    else if(stadiumName == "Paul Brown Stadium")
    {
        return 6;
    }
    else if(stadiumName == "FirstEnergy Stadium")
    {
        return 7;
    }
    else if(stadiumName == "AT&T Stadium")
    {
        return 8;
    }
    else if(stadiumName == "Broncos Stadium at Mile High")
    {
        return 9;
    }
    else if(stadiumName == "Ford Field")
    {
        return 10;
    }
    else if(stadiumName == "Lambeau Field")
    {
        return 11;
    }
    else if(stadiumName == "NRG Stadium")
    {
        return 12;
    }
    else if(stadiumName == "Lucas Oil Stadium")
    {
        return 13;
    }
    else if(stadiumName == "TIAA Bank Field")
    {
        return 14;
    }
    else if(stadiumName == "Arrowhead Stadium")
    {
        return 15;
    }
    else if(stadiumName == "Allegiant Stadium")
    {
        return 16;
    }
    else if(stadiumName == "Sofi Stadium")//Duplicate stadium - conversion of SoFi Stadium only returns 17
    {
        return 17;
    }
    else if(stadiumName == "Hard Rock Stadium")
    {
        return 19;
    }
    else if(stadiumName == "U.S. Bank Stadium")
    {
        return 20;
    }
    else if(stadiumName == "Gillette Stadium")
    {
        return 21;
    }
    else if(stadiumName == "Mercedes-Benz Superdome")
    {
        return 22;
    }
    else if(stadiumName == "MetLife Stadium")
    {
        return 23;
    }
    else if(stadiumName == "Lincoln Financial Field")
    {
        return 25;
    }
    else if(stadiumName == "Heinz Field")
    {
        return 26;
    }
    else if(stadiumName == "Levi's Stadium")
    {
        return 27;
    }
    else if(stadiumName == "CenturyLink Field")
    {
        return 28;
    }
    else if(stadiumName == "Raymond James Stadium")
    {
        return 29;
    }
    else if(stadiumName == "Nissan Stadium")
    {
        return 30;
    }
    else if(stadiumName == "FedExField")
    {
        return 31;
    }
    else if(stadiumName == "Qualcomm Stadium")
    {
        return 32;
    }

     qDebug() << "Stadium" << Qt::endl;
    return -1;
}

QString getCity(int cityIndex)
{
    //Converts the cityIndex to its corresponding city name
    switch (cityIndex)
    {
    case 0:
        return "State Farm Stadium";
        break;
    case 1:
        return "Mercedes-Benz Stadium";
        break;
    case 2:
        return "M&T Bank Stadium";
        break;
    case 3:
        return "Bills Stadium";
        break;
    case 4:
        return "Bank of America Stadium";
        break;
    case 5:
        return "Soldier Field";
        break;
    case 6:
        return "Paul Brown Stadium";
        break;
    case 7:
        return "FirstEnergy Stadium";
        break;
    case 8:
        return "AT&T Stadium";
        break;
    case 9:
        return "Broncos Stadium at Mile High";
        break;
    case 10:
        return "Ford Field";
        break;
    case 11:
        return "Lambeau Field";
        break;
    case 12:
        return "NRG Stadium";
        break;
    case 13:
        return "Lucas Oil Stadium";
        break;
    case 14:
        return "TIAA Bank Field";
        break;
    case 15:
        return "Arrowhead Stadium";
        break;
    case 16:
        return "Allegiant Stadium";
        break;
    case 17:
        return "Sofi Stadium";
        break;
    case 18:
        return "Sofi Stadium";
        break;
    case 19:
        return "Hard Rock Stadium";
        break;
    case 20:
        return "U.S. Bank Stadium";
        break;
    case 21:
        return "Gillette Stadium";
        break;
    case 22:
        return "Mercedes-Benz Superdome";
        break;
    case 23:
        return "MetLife Stadium";
        break;
    case 24:
        return "MetLife Stadium";
        break;
    case 25:
        return "Lincoln Financial Field";
        break;
    case 26:
        return "Heinz Field";
        break;
    case 27:
        return "Levi's Stadium";
        break;
    case 28:
        return "CenturyLink Field";
        break;
    case 29:
        return "Raymond James Stadium";
        break;
    case 30:
        return "Nissan Stadium";
        break;
    case 31:
        return "FedExField";
        break;
    case 32:
        return "Qualcomm Stadium";
        break;
    }
    qDebug() << "Get City" << Qt::endl;
    return "Error";
}
