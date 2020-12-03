#include "customrecursivetrip.h"
#include "ui_customrecursivetrip.h"
#include <QMessageBox>

customrecursivetrip::customrecursivetrip(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::customrecursivetrip)
{
    ui->setupUi(this);
    show();

    QSqlQuery query;
    query.prepare("SELECT * FROM Information ");
    query.exec();
    query.next();

    QSqlQuery souvenirQuery;
    souvenirQuery.prepare("SELECT * FROM souvenirs ");
    souvenirQuery.exec();
    souvenirQuery.next();

    for(int i = 0; i < 32; i++)
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

        ui->comboBox_custom->addItem(tempInfo.teamName);

        team.push_back(tempInfo);
        query.next();
        souvenirQuery.next();
    }

    QSqlQuery matrixQuery;
    matrixQuery.prepare("SELECT * FROM Distances ");
    matrixQuery.exec();
    matrixQuery.next();

    populateMatrix(thisMatrix, matrixQuery);

     ui->pushButton_4->hide();
     ui->pushButton_3->hide();
     ui->spinBox->hide();

    clicked = false;
    fin = false;
    checkFirst = false;
    finalRecipet = 0;
    currStadiumForPrice = 0;
    count = 0;
    itemsBought = 0;
    finalTotal = 0;
    totalMiles = 0;
    numItemBought = 0;
}

customrecursivetrip::~customrecursivetrip()
{
    delete ui;
}

void customrecursivetrip::on_pushButton_3_clicked()
{
    struct stadiumReciept temp;
    float itemPrice = 0;

    temp.teamName = trip[0].teamName;
    temp.totalItems = itemsBought;
    temp.totalPrice = finalRecipet;

    ui->listWidget_custom_5->clear();
    ui->spinBox->show();


    if(stadiumReciept.size() == 0)
    {
        stadiumReciept.push_back(temp);
    }
    else
    {

        ui->listWidget_custom_6->clear();

        stadiumReciept.push_back(temp);
        for(int i = 0; i < stadiumReciept.size(); i++)
        {
            if(stadiumReciept[i].totalItems != 0)
            {
                ui->listWidget_custom_6->addItem("Receipt for stadium: " + stadiumReciept[i].teamName);
                QString convert = QString::number(stadiumReciept[i].totalItems);
                ui->listWidget_custom_6->addItem("Total items purchased: " + convert);
                convert = QString::number(stadiumReciept[i].totalPrice);
                ui->listWidget_custom_6->addItem("Total price: $" + convert);
            }
        }

}

    if(clicked == false)
    {
        ui->listWidget_custom_2->clear();
        ui->listWidget_custom_3->clear();

        ui->listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else if(!trip.empty())
    {
        trip.erase(trip.begin());
        ui->listWidget_custom_2->clear();
        ui->listWidget_custom_3->clear();

        ui->listWidget_custom_2->addItem("Team Name: " + trip[0].teamName + "  -----  " + "Stadium: " + trip[0].stadiumName);

        QString convert = QString::number(trip[0].souvenirs.helmetPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.helmet);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.footBallPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.footBall);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.pennantPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamPennant);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.picturePrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamPicture);
        ui->listWidget_custom_3->addItem("$ " + convert);

        convert = QString::number(trip[0].souvenirs.jerseyPrice);
        ui->listWidget_custom_3->addItem(trip[0].souvenirs.teamJersey);
        ui->listWidget_custom_3->addItem("$ " + convert);
        clicked = true;
    }
    else
    {
        ui->listWidget_custom_2->clear();
        ui->listWidget_custom_3->clear();
        ui->listWidget_custom_2->addItem("Trip is complete");
        QString convert = QString::number(totalMiles);
        ui->listWidget_custom_4->clear();
        ui->listWidget_custom_4->addItem(convert);
        ui->pushButton_3->hide();
        ui->pushButton_4->show();
        ui->listWidget_custom->clear();
        ui->comboBox_custom->clear();
    }
    itemsBought = 0;
    finalRecipet = 0;
    numItemBought = 0;
}

void customrecursivetrip::on_pushButton_4_clicked()
{
    QMessageBox::information(this,"Thank you","Your trip has ended");
    hide();
}

void customrecursivetrip::on_listWidget_custom_3_itemDoubleClicked(QListWidgetItem *item)
{
    //    ui->listWidget_custom_6->addItem(item->text());
    //    qDebug() << trip[0].souvenirs.pennantPrice;

    if(item->text() == "Signed helmets")
    {
        ui->listWidget_custom_5->addItem("Signed helmet");
        finalRecipet += trip[0].souvenirs.helmetPrice;
        finalTotal += trip[0].souvenirs.helmetPrice;
    }
    else if(item->text() == "Autographed Football")
    {
        ui->listWidget_custom_5->addItem("Autographed football");
        finalRecipet += trip[0].souvenirs.footBallPrice;
        finalTotal += trip[0].souvenirs.footBallPrice;
    }
    else if(item->text() == "Team pennant")
    {
        ui->listWidget_custom_5->addItem("Team pennant");
        finalRecipet += trip[0].souvenirs.pennantPrice;
        finalTotal += trip[0].souvenirs.pennantPrice;
    }
    else if(item->text() == "Team picture")
    {
        ui->listWidget_custom_5->addItem("Team picture");
        finalRecipet += trip[0].souvenirs.picturePrice;
        finalTotal += trip[0].souvenirs.picturePrice;
    }
    else if(item->text() == "Team jersey")
    {
        ui->listWidget_custom_5->addItem("Team jersey");
        finalRecipet += trip[0].souvenirs.jerseyPrice;
        finalTotal += trip[0].souvenirs.jerseyPrice;
    }

    itemsBought++;
    ui->listWidget_custom_7->clear();
    QString convert = QString::number(finalTotal);
    ui->listWidget_custom_7->addItem("Total: $" + convert);

    qDebug() << finalRecipet;
    }

    void customrecursivetrip::on_pushButton_5_clicked()
    {

    }

    void customrecursivetrip::on_spinBox_valueChanged(int arg1)
    {
    numItemBought = arg1;
    }

    void customrecursivetrip::on_listWidget_custom_3_itemClicked(QListWidgetItem *item)
    {
    if(numItemBought != 0)
    {
        if(item->text() == "Signed helmets")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->listWidget_custom_5->addItem("Signed helmet");
                finalRecipet += trip[0].souvenirs.helmetPrice;
                finalTotal += trip[0].souvenirs.helmetPrice;
            }
        }
        else if(item->text() == "Autographed Football")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->listWidget_custom_5->addItem("Autographed football");
                finalRecipet += trip[0].souvenirs.footBallPrice;
                finalTotal += trip[0].souvenirs.footBallPrice;
            }
        }
        else if(item->text() == "Team pennant")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->listWidget_custom_5->addItem("Team pennant");
                finalRecipet += trip[0].souvenirs.pennantPrice;
                finalTotal += trip[0].souvenirs.pennantPrice;
            }
        }
        else if(item->text() == "Team picture")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->listWidget_custom_5->addItem("Team picture");
                finalRecipet += trip[0].souvenirs.picturePrice;
                finalTotal += trip[0].souvenirs.picturePrice;
            }
        }
        else if(item->text() == "Team jersey")
        {
            for(int i = 0; i < numItemBought; i++)
            {
                ui->listWidget_custom_5->addItem("Team jersey");
                finalRecipet += trip[0].souvenirs.jerseyPrice;
                finalTotal += trip[0].souvenirs.jerseyPrice;
            }
        }

        itemsBought += numItemBought;
        ui->listWidget_custom_7->clear();
        QString convert = QString::number(finalTotal);
        ui->listWidget_custom_7->addItem("Total: $" + convert);
    }

}

void customrecursivetrip::on_recursive_comboBox_custom_activated(int index)
{
    int total = 0;
    std::vector<QString> temp;

    count++;
    QString convert = QString::number(count);
    ui->listWidget_custom->addItem(convert + ". " + team[index].teamName);

    if(trip.size() == 0 && checkFirst == false)
    {
        trip.push_back(team[index]);
        checkFirst = true;

    }
    else
    {
        temp = dijkstra(thisMatrix, prevIndex, index, total);
        totalMiles += total;

        for(int i = 1; i < temp.size() - 1; i++)
        {
            trip.push_back(team[getStadium(temp[i])]);
    //            ui->listWidget_custom_2->addItem(team[getStadium(temp[i])].teamName + " <---> " + team[getStadium(temp[i])].stadiumName);
        }

        trip.push_back(team[index]);
    //        ui->listWidget_custom_2->addItem(team[index].teamName + " <---> " + team[index].stadiumName);
        ui->pushButton_3->show();
    }

    prevIndex = index;
}
