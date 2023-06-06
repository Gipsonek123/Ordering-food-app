#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql>
#include <QtDebug>

class dbManager
{
public:
    dbManager(const QString& path);
    void writeFood();
private:
    QSqlDatabase m_db;
};

#endif // DBMANAGER_H
