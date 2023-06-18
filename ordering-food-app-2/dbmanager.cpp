
#include "dbmanager.h"
#include <QtSql>
#include <QDebug>
#include <vector>
#include <cmath>

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

std::vector<Food> writeFoodToVectorOfObjects()
{
    QSqlQuery query("SELECT * FROM food ORDER BY food_category");
    int idName = query.record().indexOf("food_name");
    int idCost = query.record().indexOf("food_cost");
    int idCategory = query.record().indexOf("food_category");
    std::vector<Food> Foods;
    int id = 0;
    while (query.next())
    {
        QString name = query.value(idName).toString();
        double cost = query.value(idCost).toDouble();
        int category = query.value(idCategory).toInt();
        Foods.push_back(Food(id, name, cost, category));
        id++;
        //qDebug() << name <<" "<<cost<<" "<< category;
    }
    for ( auto& obj : Foods) {
        obj.writeFoodName();
    }
    return Foods;
}
std::vector<Addons> writeAddonsToVectorOfObjects()
{
    QSqlQuery query("SELECT * FROM addons");
    int idName = query.record().indexOf("addon_name");
    int idCost = query.record().indexOf("addon_cost");
    int idCategory = query.record().indexOf("addon_category");
    std::vector<Addons> addons;
    int id = 0;
    while (query.next())
    {
        QString name = query.value(idName).toString();
        double cost = query.value(idCost).toDouble();
        int category = query.value(idCategory).toInt();
        addons.push_back(Addons(id, name, cost, category));
        id++;
        // qDebug() << name <<" "<<cost<<" "<< category;
    }
    for ( auto& obj : addons) {
        obj.writeAddonsToScreen();
    }
    return addons;
}


Food::Food(const int id,const QString name, const double cost, const int category):foodId(id),foodName(name),foodCost(cost),foodCategory(category){};
Addons::Addons(const int id, const QString name, const double cost, const int category):addonId(id), addonName(name),addonCost(cost),addonCategory(category){};


QString Food::writeFoodName(){
    qDebug()<<this->foodName<<" "<<this->foodCost<<" "<<this->foodCategory;
    return foodName;
}
QString Food::writeFoodCost()
{
    double bruttoCost=this->foodCost + this->foodCost*0.23;
    bruttoCost = std::ceil(bruttoCost*100.0)/100.0;
    return QString::number(bruttoCost);
}


void Addons::writeAddonsToScreen(){
    qDebug()<<this->addonName<<" "<<this->addonCost<<" "<<this->addonCategory;
}
