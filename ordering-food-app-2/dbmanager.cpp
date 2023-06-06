#include "dbmanager.h"
#include <QtSql>
#include <QtDebug>

dbManager::dbManager(const QString& path)
{
    m_db = QSqlDatabase::addDatabase("QSQLITE");
    m_db.setDatabaseName(path);

    if (!m_db.open())
    {
        qDebug() << "Error: connection with database failed";
    }
    else
    {
        qDebug() << "Database: connection ok";
    }
}
void dbManager::writeFood()
{
    QSqlQuery query("SELECT * FROM food");
    int idName = query.record().indexOf("food_name");
    int i = 1;
    while (query.next())
    {
        QString name = query.value(idName).toString();
        qDebug() << name;
    }
}
