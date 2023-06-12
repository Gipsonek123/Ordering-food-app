#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql>
#include <QtDebug>
#include <vector>

class Food
{
public:
    Food(const QString, const double, const int);
    void writeFoodToScreen();
private:
    const QString foodName;
    const double foodCost;
    const int foodCategory;
};

std::vector<Food> writeFoodToVectorOfObjects();

class dbManager
{
public:
    dbManager(const QString& path);
    friend std::vector<Food> writeFoodToVectorOfObjects();
private:
    QSqlDatabase m_db;
};



#endif // DBMANAGER_H
