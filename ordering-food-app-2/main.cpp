#include "mainwindow.h"

#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTimer>
#include "dbmanager.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    dbManager db_connected = dbManager("../database/foodDatabase.db");
    db_connected.writeFood();
    w.show();
    return a.exec();
}
