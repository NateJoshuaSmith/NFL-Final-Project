#include "customrecursiontrip.h"
#include "ui_customrecursiontrip.h"
#include <QMessageBox>

customrecursiontrip::customrecursiontrip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customrecursiontrip)
{
    ui->setupUi(this);
    ui->recursive_pushButton_3->hide();
    ui->recursive_pushButton_5->hide();
    ui->recursive_pushButton_4->hide();

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

        ui->recursive_comboBox_custom->addItem(tempInfo.teamName);

        team.push_back(tempInfo);
        query.next();
        souvenirQuery.next();
    }

    QSqlQuery matrixQuery;
    matrixQuery.prepare("SELECT * FROM Distances ");
    matrixQuery.exec();
    matrixQuery.next();

    populateMatrix(thisMatrix, matrixQuery);

    count = 1;
}

customrecursiontrip::~customrecursiontrip()
{
    delete ui;
}

void customrecursiontrip::on_recursive_comboBox_custom_activated(int index)
{
    int total = 0;

    selected.push_back(index);

    QString convert = QString::number(count);
    ui->recursive_listWidget_custom->addItem(convert + ". " + team[index].teamName);

    ui->recursive_pushButton_5->show();

    count++;
}

void customrecursiontrip::on_recursive_pushButton_3_clicked()
{
    struct stadiumReciept temp;
    float itemPrice = 0;

    temp.teamName = trip[0].teamName;
    temp.totalItems = itemsBought;
    temp.totalPrice = finalRecipet;

    ui->recursive_listWidget_custom_5->clear();
    ui->spinBox->show();


    if(stadiumReciept.size() == 0)
    {
        stadiumReciept.push_back(temp);
    }
    else
    {

        ui->recursive_listWidget_custom_6->clear();

        stadiumReciept.push_back(temp);
        for(int i = 0; i < stadiumReciept.size(); i++)
        {
            if(stadiumReciept[i].totalItems != 0)
            {
                ui->recursive_listWidget_custom_6->addItem("Receipt for stadium: " + stadiumReciept[i].teamName);
                QString convert = QString::number(stadiumReciept[i].totalItems);
                ui->recursive_listWidget_custom_6->addItem("Total items purchased: " + convert);
                convert = QString::number(stadiumReciept[i].totalPrice);
                ui->recursive_listWidget_custom_6->addItem("Total price: $" + convert);
            }
        }

    }

    if(clicked == false)
    {
        ui->recursive_listWidget_custom_2->clear();
        ui->recursive_listWidget_custom_3->clear();

        ui->recursive_listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else if(!trip.empty())
    {
        trip.erase(trip.begin());
        ui->recursive_listWidget_custom_2->clear();
        ui->recursive_listWidget_custom_3->clear();

        ui->recursive_listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->recursive_listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->recursive_listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else
    {
        ui->recursive_listWidget_custom_2->clear();
        ui->recursive_listWidget_custom_3->clear();
        ui->recursive_listWidget_custom_4->clear();
        ui->recursive_listWidget_custom_2->addItem("Trip is complete");
        QString convert = QString::number(totalMiles);
//        ui->recursive_listWidget_custom_4->addItem(convert);
        ui->recursive_listWidget_custom_4->addItem(convert);
        ui->recursive_pushButton_3->hide();
        ui->recursive_pushButton_4->show();
        ui->recursive_listWidget_custom->clear();
        ui->recursive_comboBox_custom->clear();
    }
    itemsBought = 0;
    finalRecipet = 0;
    numItemBought = 0;
}


void customrecursiontrip::recursiveShortestPath(int closestTeam, std::vector<QString> temp, std::vector<std::vector<int>> thisMatrix, int start, std::vector<int> &selected, int &total)
{
    //base case
    if(selected.empty())
    {
        return;
    }else
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

            //recur
            recursiveShortestPath(closestTeam, temp, thisMatrix, start, selected, total);
    }
}

void customrecursiontrip::on_recursive_pushButton_5_clicked()
{
    int start = -1;
    int closestTeam = -1;
    int total = 0;
    std::vector<QString> temp;

    start = *selected.begin();

    selected.erase(selected.begin());
    trip.push_back(team[start]);

    recursiveShortestPath(closestTeam, temp, thisMatrix, start, selected, total);

    ui->recursive_pushButton_5->hide();
    ui->recursive_pushButton_3->show();
}

void customrecursiontrip::on_recursive_pushButton_4_clicked()
{
    QMessageBox::information(this,"Thank you","Your trip has ended");
    hide();
}

void customrecursiontrip::on_spinBox_valueChanged(int arg1)
{
    numItemBought = arg1;
}

void customrecursiontrip::on_recursive_listWidget_custom_3_itemClicked(QListWidgetItem *item)
{
    if(numItemBought != 0)
    {
        if(item->text() == "Signed helmets")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->recursive_listWidget_custom_5->addItem("Signed helmet");
                finalRecipet += trip[0].souvenirs.helmetPrice;
                finalTotal += trip[0].souvenirs.helmetPrice;
            }
        }
        else if(item->text() == "Autographed Football")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->recursive_listWidget_custom_5->addItem("Autographed football");
                finalRecipet += trip[0].souvenirs.footBallPrice;
                finalTotal += trip[0].souvenirs.footBallPrice;
            }
        }
        else if(item->text() == "Team pennant")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->recursive_listWidget_custom_5->addItem("Team pennant");
                finalRecipet += trip[0].souvenirs.pennantPrice;
                finalTotal += trip[0].souvenirs.pennantPrice;
            }
        }
        else if(item->text() == "Team picture")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->recursive_listWidget_custom_5->addItem("Team picture");
                finalRecipet += trip[0].souvenirs.picturePrice;
                finalTotal += trip[0].souvenirs.picturePrice;
            }
        }
        else if(item->text() == "Team jersey")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->recursive_listWidget_custom_5->addItem("Team jersey");
                finalRecipet += trip[0].souvenirs.jerseyPrice;
                finalTotal += trip[0].souvenirs.jerseyPrice;
            }
        }

        itemsBought += numItemBought;
        ui->recursive_listWidget_custom_7->clear();
        QString convert = QString::number(finalTotal);
        ui->recursive_listWidget_custom_7->addItem("Total: $" + convert);
    }
}

void customrecursiontrip::on_recursive_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item)
{
    if(item->text() == "Signed helmets")
    {
        ui->recursive_listWidget_custom_5->addItem("Signed helmet");
        finalRecipet += trip[0].souvenirs.helmetPrice;
        finalTotal += trip[0].souvenirs.helmetPrice;
    }
    else if(item->text() == "Autographed Football")
    {
        ui->recursive_listWidget_custom_5->addItem("Autographed football");
        finalRecipet += trip[0].souvenirs.footBallPrice;
        finalTotal += trip[0].souvenirs.footBallPrice;
    }
    else if(item->text() == "Team pennant")
    {
        ui->recursive_listWidget_custom_5->addItem("Team pennant");
        finalRecipet += trip[0].souvenirs.pennantPrice;
        finalTotal += trip[0].souvenirs.pennantPrice;
    }
    else if(item->text() == "Team picture")
    {
        ui->recursive_listWidget_custom_5->addItem("Team picture");
        finalRecipet += trip[0].souvenirs.picturePrice;
        finalTotal += trip[0].souvenirs.picturePrice;
    }
    else if(item->text() == "Team jersey")
    {
        ui->recursive_listWidget_custom_5->addItem("Team jersey");
        finalRecipet += trip[0].souvenirs.jerseyPrice;
        finalTotal += trip[0].souvenirs.jerseyPrice;
    }

    itemsBought++;
    ui->recursive_listWidget_custom_7->clear();
    QString convert = QString::number(finalTotal);
    ui->recursive_listWidget_custom_7->addItem("Total: $" + convert);
}
