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

class Addons
{
public:
    Addons(const QString, const double, const int);
    void writeAddonsToScreen();
private:
    const QString addonName;
    const double addonCost;
    const int addonCategory;
};


std::vector<Food> writeFoodToVectorOfObjects();
std::vector<Addons> writeAddonsToVectorOfObjects();

class dbManager
{
public:
    dbManager(const QString& path);
    friend std::vector<Food> writeFoodToVectorOfObjects();
private:
    QSqlDatabase m_db;
};



#endif // DBMANAGER_H
