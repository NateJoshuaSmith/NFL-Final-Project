#include "admin.h"
#include "ui_admin.h"
#include "database.h"
#include "QDebug"

admin::admin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::admin)
{
    ui->setupUi(this);
    reload();
    populate_souvenir_team_name_boxe();
    populate_team_table();
    populate_souvenir_table_box();

}
void admin::souvenirload ()
{
    QString teamname = ui->Team_name_souvenir_box->currentText();
    int index = ui->souvenir_name_combo_box->currentIndex();
    QSqlQuery query;
    switch (index)
    {
    case 0: query.prepare("SELECT souvenir1, souvenirprice1 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        qDebug()<<"souvenir load";
        break;
    case 1: query.prepare("SELECT souvenir2, souvenirprice2 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 2: query.prepare("SELECT souvenir3, souvenirprice3 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 3: query.prepare("SELECT souvenir4, souvenirprice4 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 4: query.prepare("SELECT souvenir5, souvenirprice5 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 5: query.prepare("SELECT souvenir6, souvenirprice6 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 6: query.prepare("SELECT souvenir7, souvenirprice7 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;

    }
    qDebug()<<query.exec();
query.exec();
query.first();

ui->Namedit->setText(query.value(0).toString());
ui->CostEdit->setText(query.value(1).toString());

}

void admin::populate_souvenir_table_box()
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;




    query.prepare("SELECT TeamName, Souvenir1, Souvenirprice1, Souvenir2, Souvenirprice2, Souvenir3, Souvenirprice3, Souvenir4, Souvenirprice4, Souvenir5, Souvenirprice5, Souvenir6, Souvenirprice6, Souvenir7, Souvenirprice7 FROM souvenirs");
    qDebug()<<query.exec();


    model->setQuery(query);


ui->souvenir_table->setModel(model);

}

void admin::populate_souvenir_team_name_boxe()
{
QSqlQuery query;

ui->Team_name_souvenir_box->clear();
//ui->Team_name_souvenir_box->addItem("Select Team Name");

query.prepare("SELECT TeamName FROM Information");
query.exec();

while(query.next())
{
    ui->Team_name_souvenir_box->addItem(query.value(0).toString());
}
ui->souvenir_name_combo_box->addItem("Souvenir1");
ui->souvenir_name_combo_box->addItem("Souvenir2");
ui->souvenir_name_combo_box->addItem("Souvenir3");
ui->souvenir_name_combo_box->addItem("Souvenir4");
ui->souvenir_name_combo_box->addItem("Souvenir5");
ui->souvenir_name_combo_box->addItem("Souvenir6");
ui->souvenir_name_combo_box->addItem("Souvenir7");





}
//populates the name box
void admin:: populate_team_name_box()
{
    QSqlQuery query;

ui->Team_Name_Combo_Box->clear();
ui->Team_Name_Combo_Box->addItem("Select Team Name");

query.prepare("SELECT TeamName FROM Information ");
query.exec();

while(query.next())
{
    ui->Team_Name_Combo_Box->addItem(query.value(0).toString());
}

}
//populates the team table
void admin:: populate_team_table()
{
    QSqlQueryModel* model = new QSqlQueryModel;
    QSqlQuery query;

    query.prepare("SELECT TeamName, StadiumName, SeatingCapacity, Location, Conference, Division, SurfaceType, StadiumRoofType, DateOpened FROM Information");
    query.exec();


    model->setQuery(query);


ui->TeamTable->setModel(model);

};

admin::~admin()
{
    delete ui;
}




void admin::reload()
{
    populate_team_table();
    populate_team_name_box();
}

void admin::on_Team_Name_Combo_Box_currentTextChanged(const QString &teamname)
{
    //qDebug()<<"part";
        //updates the boxes

        QSqlQuery query;
        // clears the boxes
        ui->Conference_Box->clear();
        ui->Date_Box->clear();
        ui->Team_Name_Box->clear();
        ui->Division_Box->clear();
        ui->Seating_Cap_Box->clear();
        ui->Stadium_Name->clear();
        ui->Location_Box->clear();
        ui->Surface_Type_Box->clear();
        ui->Stadium_Roof_Box->clear();





    //sets name of food


       //setting the cost of the food
         query.prepare("SELECT Conference, DateOpened, Division, SeatingCapacity, StadiumName, Location, SurfaceType, StadiumRoofType  FROM Information WHERE Teamname= '"+teamname+"' ");
         query.exec();
         query.first();



         ui->Conference_Box->setText(query.value(0).toString());
         ui->Date_Box->setText(query.value(1).toString());
         ui->Team_Name_Box->setText(teamname);
         ui->Division_Box->setText(query.value(2).toString());
         ui->Seating_Cap_Box->setText(query.value(3).toString());
         ui->Stadium_Name->setText(query.value(4).toString());
         ui->Location_Box->setText(query.value(5).toString());
         ui->Surface_Type_Box->setText(query.value(6).toString());
         ui->Stadium_Roof_Box->setText(query.value(7).toString());




}

void admin::on_Delete_Button_clicked()
{
    qDebug()<<"del clicked";
 QString nametbd =   ui->Team_Name_Box->text();

    QSqlQuery query;
    query.prepare("DELETE FROM Information WHERE TeamName = '"+nametbd+"'");
    query.exec();
    query.prepare("DELETE FROM souvenirs WHERE TeamName = '"+nametbd+"'");
    query.exec();
    reload();
    populate_souvenir_table_box();

}

void admin::on_Add_Button_clicked()
{

    // the variables for holding value;
    QString crack ="hellow";
    qDebug()<<crack;
    QString newconf = ui->Conference_Box->text();
    QString newdate= ui->Date_Box->text();
    QString newteamname =ui->Team_Name_Box->text();
    QString newdiv =ui->Division_Box->text();
    QString newcap = ui->Seating_Cap_Box->text();
    QString newstadiumname =ui->Stadium_Name->text();
    QString newlocation =ui->Location_Box->text();
    QString newsurface = ui->Surface_Type_Box->text();
    QString newroof =ui->Stadium_Roof_Box->text();
    QSqlQuery query;


    query.prepare("INSERT INTO Information (TeamName, StadiumName, SeatingCapacity, Location, Conference, Division, SurfaceType, StadiumRoofType, DateOpened)"

                    "VALUES ('"+newteamname+ "','"+newstadiumname+"','"+newcap+"','"+newlocation+"','"+newconf+"','"+newdiv+"','"+newsurface+"','"+newroof+"','"+newdate+"' )");

        query.exec();

        query.prepare("INSERT INTO souvenirs (TeamName, Souvenir1, Souvenirprice1, Souvenir2, Souvenirprice2, Souvenir3, Souvenirprice3, Souvenir4, Souvenirprice4, Souvenir5, Souvenirprice5)"
                      "VALUES ('"+newteamname+ "', 'Signed helmets', 77.99, 'Autographed Football', 99.89, 'Team pennant', 17.99, 'Team picture', 29.99, 'Team jersey', 199.99 )");
        qDebug()<<"t2";
        qDebug()<<query.exec();

        qDebug()<<newteamname;
        populate_souvenir_table_box();


        reload();
}

void admin::on_Edit_Button_clicked()
{
qDebug()<<"edit clicked";

    QString oldname = ui->Team_Name_Combo_Box->currentText();
    // the variables for holding value;
    QString crack ="hellow";
    qDebug()<<crack;
    QString newconf = ui->Conference_Box->text();
    QString newdate= ui->Date_Box->text();
    QString newteamname =ui->Team_Name_Box->text();
    QString newdiv =ui->Division_Box->text();
    QString newcap = ui->Seating_Cap_Box->text();
    QString newstadiumname =ui->Stadium_Name->text();
    QString newlocation =ui->Location_Box->text();
    QString newsurface = ui->Surface_Type_Box->text();
    QString newroof =ui->Stadium_Roof_Box->text();
    QSqlQuery query;

    query.prepare("UPDATE Information SET TeamName =  '"+newteamname+"', SeatingCapacity = '"+newcap+"', StadiumName = '"+newstadiumname+"', Location = '"+newlocation+"', Conference = '"+newconf+"', Division = '"+newdiv+"', SurfaceType = '"+newsurface+"', StadiumRoofType = '"+newroof+"',  DateOpened = '"+newdate+"'  WHERE TeamName = '"+oldname+"' ");

        qDebug()<<query.exec();

        qDebug()<<newteamname;

        reload();
}

void admin::on_souvenir_name_combo_box_currentTextChanged(const QString &souvenir)
{


}

void admin::on_souvenir_name_combo_box_currentIndexChanged(int index)
{

    QString teamname = ui->Team_name_souvenir_box->currentText();
    QSqlQuery query;
    switch (index)
    {
    case 0: query.prepare("SELECT souvenir1, souvenirprice1 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        qDebug()<<"case 0";
        break;
    case 1: query.prepare("SELECT souvenir2, souvenirprice2 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 2: query.prepare("SELECT souvenir3, souvenirprice3 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 3: query.prepare("SELECT souvenir4, souvenirprice4 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 4: query.prepare("SELECT souvenir5, souvenirprice5 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 5: query.prepare("SELECT souvenir6, souvenirprice6 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;
    case 6: query.prepare("SELECT souvenir7, souvenirprice7 FROM souvenirs WHERE TeamName = '"+teamname+"' ");
        break;

    }
    qDebug()<<query.exec();
query.exec();
query.first();
//qDebug()<<query.value(0).toString();
ui->Namedit->setText(query.value(0).toString());
ui->CostEdit->setText(query.value(1).toString());






}

void admin::on_pushButton_2_clicked()
{
    qDebug()<<"HELP ME";
    QSqlQuery query;
    QString newname = ui->Namedit->text();
    QString newprice = ui->CostEdit->text();
    int index = ui->souvenir_name_combo_box->currentIndex();
    QString teamname = ui->Team_name_souvenir_box->currentText();

    switch (index)
    {
    case 0: query.prepare("UPDATE souvenirs SET souvenir1 = '"+newname+"', souvenirprice1 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        qDebug()<<"update selected"<<newname<<newprice<<teamname;
        break;
    case 1: query.prepare("UPDATE souvenirs SET souvenir2 = '"+newname+"', souvenirprice2 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 2: query.prepare("UPDATE souvenirs SET souvenir3 = '"+newname+"', souvenirprice3 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 3: query.prepare("UPDATE souvenirs SET souvenir4 = '"+newname+"', souvenirprice4 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 4: query.prepare("UPDATE souvenirs SET souvenir5 = '"+newname+"', souvenirprice5 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 5: query.prepare("UPDATE souvenirs SET souvenir6 = '"+newname+"', souvenirprice6 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 6: query.prepare("UPDATE souvenirs SET souvenir7 = '"+newname+"', souvenirprice7 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;

    }
    query.exec();
    //qDebug()<<query.exec();
    populate_souvenir_table_box();
}

void admin::on_pushButton_3_clicked()
{
    QSqlQuery query;
    QString newname = "";
    QString newprice = "";
    int index = ui->souvenir_name_combo_box->currentIndex();
    QString teamname = ui->Team_name_souvenir_box->currentText();

    switch (index)
    {
    case 0: query.prepare("UPDATE souvenirs SET souvenir1 = '"+newname+"', souvenirprice1 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        //qDebug()<<"case 0";
        qDebug()<<newname;
        break;
    case 1: query.prepare("UPDATE souvenirs SET souvenir2 = '"+newname+"', souvenirprice2 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 2: query.prepare("UPDATE souvenirs SET souvenir3 = '"+newname+"', souvenirprice3 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 3: query.prepare("UPDATE souvenirs SET souvenir4 = '"+newname+"', souvenirprice4 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 4: query.prepare("UPDATE souvenirs SET souvenir5 = '"+newname+"', souvenirprice5 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 5: query.prepare("UPDATE souvenirs SET souvenir6 = '"+newname+"', souvenirprice6 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;
    case 6: query.prepare("UPDATE souvenirs SET souvenir7 = '"+newname+"', souvenirprice7 = '"+newprice+"' WHERE TeamName = '"+teamname+"' ");
        break;

    }
    query.exec();
    //qDebug()<<query.exec();
    populate_souvenir_table_box();
    souvenirload();

}

void admin::on_Team_name_souvenir_box_currentIndexChanged(const QString &arg1)
{

}

void admin::on_Remove_expansion_button_clicked()
{




    QString nametbd =   "San Diego Sailors";

       QSqlQuery query;
       query.prepare("DELETE FROM Information WHERE TeamName = '"+nametbd+"'");
       query.exec();
       query.prepare("DELETE FROM souvenirs WHERE TeamName = '"+nametbd+"'");

       qDebug()<<query.exec();
       reload();
       souvenirload();
       populate_souvenir_table_box();
       query.prepare("DELETE FROM Distances WHERE TeamName == '" +nametbd+"'");
       query.exec();
}

void admin::on_Add_expansion_button_clicked()
{
    QSqlQuery query;
    QString newteamname = "San Diego Sailors";
    query.prepare("INSERT INTO souvenirs (TeamName, Souvenir1, Souvenirprice1, Souvenir2, Souvenirprice2, Souvenir3, Souvenirprice3, Souvenir4, Souvenirprice4, Souvenir5, Souvenirprice5)"
                  "VALUES ('"+newteamname+ "', 'Signed helmets', 77.99, 'Autographed Football', 99.89, 'Team pennant', 17.99, 'Team picture', 29.99, 'Team jersey', 199.99 )");

    query.exec();






    QString newconf = "American Football Conference";
    QString newdate= "2022";

    QString newdiv = "AFC WEST";
    QString newcap ="71500";
    QString newstadiumname ="Qualcomm Stadium";
    QString newlocation ="San Diego, California";
    QString newsurface = "Bermuda Grass";
    QString newroof = "Open";


    query.prepare("INSERT INTO Information (TeamName, StadiumName, SeatingCapacity, Location, Conference, Division, SurfaceType, StadiumRoofType, DateOpened)"

                    "VALUES ('"+newteamname+ "','"+newstadiumname+"','"+newcap+"','"+newlocation+"','"+newconf+"','"+newdiv+"','"+newsurface+"','"+newroof+"','"+newdate+"' )");

        query.exec();
        reload();
        populate_souvenir_table_box();



        QString beggining;
        QString ending;
        QString distance;
        QString teamname = "San Diego Sailors";

        beggining = "Qualcomm Stadium";
        ending = "State Farm Stadium";
        distance = "300";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 1"<<query.exec();

        beggining = "Qualcomm Stadium";
        ending = "Sofi Stadium";
        distance = "121";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 2"<<query.exec();

        beggining = "Qualcomm Stadium";
        ending = "Broncos Stadium at Mile High";
        distance = "830";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 3"<<query.exec();

        beggining = "State farm Stadium";
        ending = "Qualcomm Stadium";
        distance = "300";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 4"<<query.exec();

        beggining = "Softi Stadium";
        ending = "Qualcomm Stadium";
        distance = "121";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 5"<<query.exec();

        beggining = "Broncos Stadium at Mile High";
        ending = "Qualcomm Stadium";
        distance = "830";
        query.prepare("INSERT INTO Distances (TeamName, BeginningStadium, EndingStadium, Distance )" "VALUES ('"+teamname+ "','"+beggining+ "','"+ending+"','"+distance+"' ) ");
        qDebug()<<"was insertion of distances successfull 6"<<query.exec();



  }







