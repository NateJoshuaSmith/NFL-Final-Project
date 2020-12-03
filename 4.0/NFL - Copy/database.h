#ifndef DATABASEH_H
#define DATABASEH_H
#include <QSqlQueryModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QFile>
#include <QDebug>
#include <QApplication>
#include <QDir>

struct souvenirs
{
    QString teamName;
    QString helmet;
    double helmetPrice;
    QString footBall;
    double footBallPrice;
    QString teamPennant;
    double pennantPrice;
    QString teamPicture;
    double picturePrice;
    QString teamJersey;
    double jerseyPrice;
    QString placeholder;
    double placeholderPrice;
    QString placeholder2;
    double placeholder2Price;
};

struct teamInformation
{
    QString teamName;
    QString stadiumName;
    QString seatingCapacity;
    QString location;
    QString conference;
    QString divsion;
    QString surfaceType;
    QString stadiumRoofType;
    QString dateOpen;
    souvenirs souvenirs;
};

struct stadiumReciept
{
    QString teamName;
    float totalPrice;
    int totalItems;
};

/**
 * @brief The Database class
 * is used to access the database to use in the program
 */
class Database: public QSqlDatabase
{
public:
    /**
     * @brief Function to return the database instance
     * @return the database pointer instance to the project sql database
     */
    static Database* getInstance();

private:
    /**
     * @brief Class constructor
     *
     * Set the path and open the database file for the program
     */
    Database();
    static Database* instance;

};

#endif // DATABASE_H
