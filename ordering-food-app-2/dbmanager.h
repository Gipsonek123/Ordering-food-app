#ifndef DBMANAGER_H
#define DBMANAGER_H
#include <QtSql>
#include <QDebug>
#include <vector>

class Food
{
public:
    Food(const int, const QString, const double, const int);
    QString writeFoodName();
    QString writeFoodCost();
private:
    const int foodId;
    const QString foodName;
    const double foodCost;
    const int foodCategory;
};

class Addons
{
public:
    Addons(const int,const QString, const double, const int);
    void writeAddonsToScreen();
private:
    const int addonId;
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
    friend std::vector<Addons> writeAddonsToVectorOfObjects();
private:
    QSqlDatabase m_db;
};



#endif // DBMANAGER_H
