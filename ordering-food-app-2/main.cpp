#include "mainwindow.h"

#include "dbmanager.h"
#include <QtSql>

#include "produkt.h"
#include "ui_produkt.h"
#include "ui_mainwindow.h"


#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dbManager m_db("../database/foodDatabase.db");
    MainWindow w;
    w.setWindowTitle("Jedzenie na okągło");
    w.show();
    return a.exec();
}
