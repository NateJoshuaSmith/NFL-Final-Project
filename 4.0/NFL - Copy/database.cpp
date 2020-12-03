#include "database.h"

Database* Database::instance = nullptr;

Database::Database() : QSqlDatabase(addDatabase("QSQLITE"))
{
    this->setDatabaseName(qApp->applicationDirPath()
                          //+ QDir::separator()
                          + "NFLDBwithexpansion.db");
    QFileInfo databaseInfo(qApp->applicationDirPath()
                          //+ QDir::separator()
                          + "NFLDBwithexpansion.db");
    qDebug() << qApp->applicationDirPath()
                              //+ QDir::separator()
                              + "NFLDBwithexpansion.db";
   if (databaseInfo.exists())
   {

        qDebug() << "Database file is open.\n";
        //qDebug()<<databaseInfo.fileName();
        this->open();
        QSqlQuery query;
        query.prepare("PRAGMA foreign_keys = ON");
        query.exec();
    }
    else
    {
        qDebug() << "Database file is not open.\n";
    }
}

Database* Database::getInstance()
{
    if(instance == nullptr)
        instance = new Database;
     return instance;
}
