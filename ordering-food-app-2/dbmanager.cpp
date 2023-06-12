#include "dbmanager.h"
#include <QtSql>
#include <QtDebug>
#include <vector>

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
    QSqlQuery query("SELECT * FROM food");
    int idName = query.record().indexOf("food_name");
    int idCost = query.record().indexOf("cost");
    int idCategory = query.record().indexOf("category_id");
    std::vector<Food> Foods;
    while (query.next())
    {
        QString name = query.value(idName).toString();
        double cost = query.value(idCost).toDouble();
        int category = query.value(idCategory).toInt();
        Foods.push_back(Food(name, cost, category));
       // qDebug() << name <<" "<<cost<<" "<< category;
    }
    for ( auto& obj : Foods) {
        obj.writeFoodToScreen();
    }
    return Foods;
}

Food::Food(const QString name, const double cost, const int category):foodName(name),foodCost(cost),foodCategory(category){};

void Food::writeFoodToScreen(){
    qDebug()<<this->foodName<<" "<<this->foodCost<<" "<<this->foodCategory;
}
