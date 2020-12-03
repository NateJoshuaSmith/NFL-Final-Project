#include "displayteam.h"
#include "ui_displayteam.h"

displayteam::displayteam(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::displayteam)
{
    ui->setupUi(this);

    ui->comboBoxTraversals->addItem("BFS starting at Los Angeles Rams");
    ui->comboBoxTraversals->addItem("DFS starting at Minnesota Vikings");
    ui->comboBoxTraversals->addItem("MST Minimum Spaning Tree");

    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    QSqlQuery query;
    query.prepare("SELECT * FROM Information ");
    query.exec();
    query.next();

    QSqlQuery souvenirQuery;
    souvenirQuery.prepare("SELECT * FROM souvenirs ");
    souvenirQuery.exec();
    souvenirQuery.next();

    qDebug() << souvenirQuery.value(0);
    qDebug() << souvenirQuery.value(1);
    qDebug() << souvenirQuery.value(2).toDouble();

    for(int i = 0; i < row_count; i++)
    {
        souvenirs items;
        items.teamName = souvenirQuery.value(0).toString();
        items.helmet = souvenirQuery.value(1).toString();
        items.helmetPrice = souvenirQuery.value(2).toDouble();
        items.footBall = souvenirQuery.value(3).toString();
        items.footBallPrice = souvenirQuery.value(4).toDouble();
        items.teamPennant = souvenirQuery.value(5).toString();
        items.pennantPrice = souvenirQuery.value(6).toDouble();
        items.teamPicture = souvenirQuery.value(7).toString();
        items.picturePrice = souvenirQuery.value(8).toDouble();
        items.teamJersey = souvenirQuery.value(9).toString();
        items.jerseyPrice = souvenirQuery.value(10).toDouble();
        items.placeholder = souvenirQuery.value(11).toString();
        items.placeholderPrice = souvenirQuery.value(12).toDouble();
        items.placeholder2 = souvenirQuery.value(13).toString();
        items.placeholder2Price = souvenirQuery.value(14).toDouble();

        qDebug() << items.teamName;

        teamInformation tempInfo;
        tempInfo.teamName = query.value(0).toString();
        tempInfo.stadiumName = query.value(1).toString();
        tempInfo.seatingCapacity = query.value(2).toString();
        tempInfo.location = query.value(3).toString();
        tempInfo.conference = query.value(4).toString();
        tempInfo.divsion = query.value(5).toString();
        tempInfo.surfaceType = query.value(6).toString();
        tempInfo.stadiumRoofType = query.value(7).toString();
        tempInfo.dateOpen = query.value(8).toString();
        tempInfo.souvenirs = items;

        ui->comboBoxTraversals_3->addItem(tempInfo.teamName);

        team.push_back(tempInfo);
        query.next();
        souvenirQuery.next();
    }

    QSqlQuery matrixQuery;
    matrixQuery.prepare("SELECT * FROM Distances ");
    matrixQuery.exec();
    matrixQuery.next();

    populateMatrix(thisMatrix, matrixQuery);
}

displayteam::~displayteam()
{
    delete ui;
}

void displayteam::on_comboBoxTraversals_3_activated(int index)
{
//    this->index = index;

    ui->listWidget_4->clear();
    ui->listWidget_5->clear();

    ui->listWidget_4->addItem("Team Name: " + team[index].teamName);
    ui->listWidget_4->addItem("Stadium Name: " + team[index].stadiumName);
    ui->listWidget_4->addItem("Seating Capacity: " + team[index].seatingCapacity);
    ui->listWidget_4->addItem("Location: " + team[index].location);
    ui->listWidget_4->addItem("Conference: " + team[index].conference);
    ui->listWidget_4->addItem("Division: " + team[index].divsion);
    ui->listWidget_4->addItem("Surface Type: " + team[index].surfaceType);
    ui->listWidget_4->addItem("Stadium Roof Type: " + team[index].stadiumRoofType);
    ui->listWidget_4->addItem("Date Opened: " + team[index].dateOpen);

    QString convert = QString::number(team[index].souvenirs.helmetPrice);
    ui->listWidget_5->addItem("Item: " + team[index].souvenirs.helmet + " ---> Price: " + "$ " + convert);

    convert = QString::number(team[index].souvenirs.footBallPrice);
    ui->listWidget_5->addItem("Item: " + team[index].souvenirs.footBall + " ---> Price: " + "$ " + convert);

    convert = QString::number(team[index].souvenirs.pennantPrice);
    ui->listWidget_5->addItem("Item: " + team[index].souvenirs.teamPennant + " ---> Price: " + "$ " + convert);

    convert = QString::number(team[index].souvenirs.picturePrice);
    ui->listWidget_5->addItem("Item: " + team[index].souvenirs.teamPicture + " ---> Price: " +  "$ " + convert);

    convert = QString::number(team[index].souvenirs.jerseyPrice);
    ui->listWidget_5->addItem("Item: " + team[index].souvenirs.teamJersey + " ---> Price: " + "$ " + convert);
}

void displayteam::on_comboBoxTraversals_activated(int index)
{
    int f = 999999;
    int d = 999999;
    int totMiles = 0;
    std::vector<QString> totalMiles;
    std::vector<mstValues> mst;
    std::vector<int> tripOrder;

    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    std::vector<bool> visited(row_count, false);

     ui->listWidget_2->clear();
     ui->totalDistance->clear();

    if(index == 0)
    {
        totalMiles = BFS(thisMatrix, 18, d, f, tripOrder);

        for(int i = 0; i < totalMiles.size(); i++)
        {
            if(i == totalMiles.size() - 1)
            {
                ui->totalDistance->addItem("Total mileage: " + totalMiles[i]);
                ui->listWidget_2->addItem("BFS Complete");
                continue;
            }
             ui->listWidget_2->addItem("Visiting: " + totalMiles[i]);
        }
    }
    else if(index == 1 )
    {
        DFS(20, visited, thisMatrix, totalMiles, totMiles);

        for(int i = 0; i < totalMiles.size(); i++)
        {
            if(i == totalMiles.size() - 1)
            {
                QString convert = QString::number(totMiles);
                 ui->totalDistance->addItem("Total mileage: " + convert);
                ui->listWidget_2->addItem("DFS Complete");
                continue;
            }
             ui->listWidget_2->addItem("Visiting: " + totalMiles[i]);
        }

    }
    else if(index == 2)
    {
        mst = primMST(thisMatrix);

        for(int i = 0; i < mst.size(); i++)
        {
             QString convert = QString::number(mst[i].distance);
             ui->listWidget_2->addItem(mst[i].start + " --> " + mst[i].end + " " + convert);
             mst[i].distance;
        }

        QString totConvert = QString::number(mst[0].total);
        ui->totalDistance->addItem("Total mileage: " + totConvert);
        ui->listWidget_2->addItem("MST Complete");
    }
}
