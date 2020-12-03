#include "newengland.h"
#include "ui_newengland.h"
#include <QMessageBox>

newengland::newengland(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::newengland)
{
    //hello
    ui->setupUi(this);

    ui->newEngland_pushButton_4->hide();

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

        team.push_back(tempInfo);
        query.next();
        souvenirQuery.next();
    }

    QSqlQuery matrixQuery;
    matrixQuery.prepare("SELECT * FROM Distances ");
    matrixQuery.exec();
    matrixQuery.next();

    populateMatrix(thisMatrix, matrixQuery);

    int total = 0;

    selected.push_back(21);

    for(int i = 0; i < thisMatrix.size(); i++)
    {
        if(i != 21)
        {
           selected.push_back(i);
        }
    }

    int start = -1;
    int closestTeam = -1;
    std::vector<QString> temp;

    start = *selected.begin();

    selected.erase(selected.begin());
    trip.push_back(team[start]);

    while(!selected.empty())
    {
        closestTeam = getClosestTeam(thisMatrix, start, selected);

        temp = dijkstra(thisMatrix, start, closestTeam, total);
        totalMiles += total;

        for(int i = 1; i < temp.size() - 1; i++)
        {
            trip.push_back(team[getStadium(temp[i])]);
        }

        trip.push_back(team[closestTeam]);
        start = closestTeam;

        for(int i = 0; i < selected.size(); i++)
        {
            if(selected[i] == closestTeam)
            {
                selected.erase(selected.begin() + i);
            }
        }
    }

    QString convert;
    int count = 1;
    for(int i = 0; i < team.size(); i++)
    {
        convert = QString::number(count);
        ui->newEngland_listWidget_custom->addItem(convert + "." + team[i].teamName);
        count++;
    }
}

newengland::~newengland()
{
    delete ui;
}

void newengland::on_newEngland_pushButton_3_clicked()
{
    struct stadiumReciept temp;
    float itemPrice = 0;

    temp.teamName = trip[0].teamName;
    temp.totalItems = itemsBought;
    temp.totalPrice = finalRecipet;

    ui->newEngland_listWidget_custom_5->clear();
    ui->newEngland_spinBox->show();


    if(stadiumReciept.size() == 0)
    {
        stadiumReciept.push_back(temp);
    }
    else
    {

        ui->newEngland_listWidget_custom_6->clear();

        stadiumReciept.push_back(temp);
        for(int i = 0; i < stadiumReciept.size(); i++)
        {
            if(stadiumReciept[i].totalItems != 0)
            {
                ui->newEngland_listWidget_custom_6->addItem("Receipt for stadium: " + stadiumReciept[i].teamName);
                QString convert = QString::number(stadiumReciept[i].totalItems);
                ui->newEngland_listWidget_custom_6->addItem("Total items purchased: " + convert);
                convert = QString::number(stadiumReciept[i].totalPrice);
                ui->newEngland_listWidget_custom_6->addItem("Total price: $" + convert);
            }
        }

    }

    if(clicked == false)
    {
        ui->newEngland_listWidget_custom_2->clear();
        ui->newEngland_listWidget_custom_3->clear();

        ui->newEngland_listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else if(!trip.empty())
    {
        trip.erase(trip.begin());
        ui->newEngland_listWidget_custom_2->clear();
        ui->newEngland_listWidget_custom_3->clear();

        ui->newEngland_listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->newEngland_listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->newEngland_listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else
    {
        ui->newEngland_listWidget_custom_2->clear();
        ui->newEngland_listWidget_custom_3->clear();
        ui->newEngland_listWidget_custom_2->addItem("Trip is complete");
        QString convert = QString::number(totalMiles);
        ui->newEngland_listWidget_custom_4->clear();
        ui->newEngland_listWidget_custom_4->addItem(convert);
        ui->newEngland_pushButton_3->hide();
        ui->newEngland_pushButton_4->show();
        ui->newEngland_listWidget_custom->clear();
    }
    itemsBought = 0;
    finalRecipet = 0;
    numItemBought = 0;
}



void newengland::on_newEngland_pushButton_4_clicked()
{
    QMessageBox::information(this,"Thank you","Your trip has ended");
    hide();
}

void newengland::on_newEngland_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item)
{
    if(item->text() == "Signed helmets")
    {
        ui->newEngland_listWidget_custom_5->addItem("Signed helmet");
        finalRecipet += trip[0].souvenirs.helmetPrice;
        finalTotal += trip[0].souvenirs.helmetPrice;
    }
    else if(item->text() == "Autographed Football")
    {
        ui->newEngland_listWidget_custom_5->addItem("Autographed football");
        finalRecipet += trip[0].souvenirs.footBallPrice;
        finalTotal += trip[0].souvenirs.footBallPrice;
    }
    else if(item->text() == "Team pennant")
    {
        ui->newEngland_listWidget_custom_5->addItem("Team pennant");
        finalRecipet += trip[0].souvenirs.pennantPrice;
        finalTotal += trip[0].souvenirs.pennantPrice;
    }
    else if(item->text() == "Team picture")
    {
        ui->newEngland_listWidget_custom_5->addItem("Team picture");
        finalRecipet += trip[0].souvenirs.picturePrice;
        finalTotal += trip[0].souvenirs.picturePrice;
    }
    else if(item->text() == "Team jersey")
    {
        ui->newEngland_listWidget_custom_5->addItem("Team jersey");
        finalRecipet += trip[0].souvenirs.jerseyPrice;
        finalTotal += trip[0].souvenirs.jerseyPrice;
    }

    itemsBought++;
    ui->newEngland_listWidget_custom_7->clear();
    QString convert = QString::number(finalTotal);
    ui->newEngland_listWidget_custom_7->addItem("Total: $" + convert);
}

void newengland::on_newEngland_spinBox_valueChanged(int arg1)
{
     numItemBought = arg1;
}

void newengland::on_newEngland_listWidget_custom_3_itemClicked(QListWidgetItem *item)
{
    if(numItemBought != 0)
    {
        if(item->text() == "Signed helmets")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->newEngland_listWidget_custom_5->addItem("Signed helmet");
                finalRecipet += trip[0].souvenirs.helmetPrice;
                finalTotal += trip[0].souvenirs.helmetPrice;
            }
        }
        else if(item->text() == "Autographed Football")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->newEngland_listWidget_custom_5->addItem("Autographed football");
                finalRecipet += trip[0].souvenirs.footBallPrice;
                finalTotal += trip[0].souvenirs.footBallPrice;
            }
        }
        else if(item->text() == "Team pennant")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->newEngland_listWidget_custom_5->addItem("Team pennant");
                finalRecipet += trip[0].souvenirs.pennantPrice;
                finalTotal += trip[0].souvenirs.pennantPrice;
            }
        }
        else if(item->text() == "Team picture")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->newEngland_listWidget_custom_5->addItem("Team picture");
                finalRecipet += trip[0].souvenirs.picturePrice;
                finalTotal += trip[0].souvenirs.picturePrice;
            }
        }
        else if(item->text() == "Team jersey")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->newEngland_listWidget_custom_5->addItem("Team jersey");
                finalRecipet += trip[0].souvenirs.jerseyPrice;
                finalTotal += trip[0].souvenirs.jerseyPrice;
            }
        }

        itemsBought += numItemBought;
//        QString    number(double n, char format = 'g', int precision = 6);
        ui->newEngland_listWidget_custom_7->clear();

        //change for all functions that have a trip total
        QString convert = QString::number(finalTotal);
        ui->newEngland_listWidget_custom_7->addItem("Total: $" + convert);
    }
}
