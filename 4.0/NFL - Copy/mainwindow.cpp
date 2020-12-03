#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "database.h"
#include "traversals.h"
#include "QDebug"
#include "admin.h"
#include "login.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QSqlQuery sizeOfQuery;
     int row_count = 0;

     // Run some query
     sizeOfQuery.exec("SELECT * FROM Information");

     while(sizeOfQuery.next())
     {
         row_count++;
     }

    ui->comboBoxTraversals_2->addItem("Sort by NFL team name");
    ui->comboBoxTraversals_2->addItem("Sort by NFL Stadium name");
    ui->comboBoxTraversals_2->addItem("Display National Football Conference teams");
    ui->comboBoxTraversals_2->addItem("Display American Football Conference teams");
    ui->comboBoxTraversals_2->addItem("Display NFC North teams");
    ui->comboBoxTraversals_2->addItem("Sort by date opened");
    ui->comboBoxTraversals_2->addItem("Display list of stadiums with *open* roof");
    ui->comboBoxTraversals_2->addItem("Sory by seating capacity");
    ui->comboBoxTraversals_2->addItem("Sort by conference name");
    ui->comboBoxTraversals_2->addItem("Display NFL teams with surface type Bermuda Grass");

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

        team.push_back(tempInfo);
        query.next();
        souvenirQuery.next();
    }

    index = 0;

    //it should be this number 2,115,752
    size = "0";
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setMatrix(std::vector<std::vector<int>> matrix)
{
    thisMatrix = matrix;
}

void MainWindow::on_pushButton_clicked()
{
    customtrip *custom;

    custom = new ::customtrip(this);
    custom->show();
}

void MainWindow::on_pushButton_2_clicked()
{
    customtrip_2 *custom;

    custom = new ::customtrip_2(this);
    custom->show();
}

void MainWindow::on_Edit_button_clicked()
{
    login loginwindow;
    loginwindow.setModal(true);
    loginwindow.exec();
  /*
    admin adminwindow;
    adminwindow.setModal(true);
    adminwindow.exec();
*/

}

void MainWindow::on_pushButton_6_clicked()
{
    customrecursiontrip *custom;

    custom = new ::customrecursiontrip(this);
    custom->show();
}

void MainWindow::on_pushButton_5_clicked()
{
    newengland *custom;

    custom = new ::newengland(this);
    custom->show();
}

void MainWindow::on_pushButton_3_clicked()
{
    team.clear();
//    ui->comboBoxTraversals_3->clear();

    qDebug() << team.size();

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

    size = "2,187,252";
}

void MainWindow::on_pushButton_4_clicked()
{
    displayteam *custom;

    custom = new ::displayteam(this);
    custom->show();
}

void MainWindow::on_comboBoxTraversals_2_activated(int index)
{
    ui->listWidget_3->clear();
    QStringList teamName;
    if(index == 0)
    {
        for(int i =0; i < team.size(); i++)
        {
            teamName.push_back(team[i].teamName + " <--> " + "Stadium Name: " + team[i].stadiumName);
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Team Name: " + teamName[i]);
        }
    }
    else if(index == 1)
    {
        for(int i =0; i < team.size(); i++)
        {
            teamName.push_back(team[i].stadiumName+ " <--> " + "Team Name: " + team[i].teamName);
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Stadium Name: " + teamName[i]);
        }
    }
    else if(index == 2)
    {
        for(int i =0; i < team.size(); i++)
        {
            if(team[i].conference == "National Football Conference")
            {
                teamName.push_back(team[i].teamName + " <--> " + "Stadium Name: " + team[i].stadiumName);
            }
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Team Name: " + teamName[i]);
        }
    }
    else if(index == 3)
    {
        for(int i =0; i < team.size(); i++)
        {
            if(team[i].conference == "American Football Conference")
            {
                teamName.push_back(team[i].teamName + " <--> " + "Stadium Name: " + team[i].stadiumName);
            }
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Team Name: " + teamName[i]);
        }
    }
    else if(index == 4)
    {
        for(int i =0; i < team.size(); i++)
        {
            if(team[i].divsion == "NFC  North")
            {
                teamName.push_back(team[i].teamName + " <--> " + "Stadium Name: " + team[i].stadiumName);
            }
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Team Name: " + teamName[i]);
        }
    }
    else if(index == 5)
    {
        for(int i =0; i < team.size(); i++)
        {
            teamName.push_back(team[i].dateOpen + " <--> " + "Team Name: " + team[i].teamName);
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Date Opened: " + teamName[i]);
        }
    }
    else if(index == 6)
    {
        int count = 0;
        for(int i =0; i < team.size(); i++)
        {
            if(team[i].stadiumRoofType == "Open" && team[i].teamName != "New York Jets")
            {
                teamName.push_back(team[i].stadiumName + " <--> " + "Team Name: " + team[i].teamName);
                count++;
            }
        }

        teamName.sort();
        QString convert = QString::number(count);
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Stadium Name: " + teamName[i]);
        }
        ui->listWidget_3->addItem("Total Stadiums with open roof: " + convert);
    }
    else if(index == 7)
    {
        std::vector<teamInformation> temp;
        int count = 0;

        for(int i =0; i < team.size(); i++)
        {
            if(team[i].teamName != "Los Angeles Rams" || team[i].teamName != "New York Jets")
            {
                teamName.push_back(team[i].seatingCapacity + " <--> " + "Team Name: " + team[i].teamName + " <--> Stadium Name : " + team[i].stadiumName);
            }
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Seating Capacity: " + teamName[i]);
        }
        QString convert = QString::number(count);
        ui->listWidget_3->addItem("Total Seating Capacity: " + size);
    }
    else if(index == 8)
    {
        for(int i =0; i < team.size(); i++)
        {
            teamName.push_back(team[i].conference + " <--> " + " Team Name: " + team[i].teamName + " <--> Stadium Name:  " + team[i].stadiumName + "  <--> Location: " + team[i].location);
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Conference: " + teamName[i]);
        }
    }
    else if(index == 9)
    {
        int count = 3;
        for(int i =0; i < team.size(); i++)
        {
            if(team[i].surfaceType == "Bermuda Grass")
            {
                teamName.push_back(team[i].teamName + " <--> " + " Surface Type: " + team[i].surfaceType);
                count++;
            }
        }

        teamName.sort();
        for(int i = 0; i < teamName.size(); i++)
        {
            ui->listWidget_3->addItem("Team Name: " + teamName[i]);
        }

        QString convert = QString::number(count);
        ui->listWidget_3->addItem("The total number of stadiums with Bermuda Grass: " + convert);
    }
}
