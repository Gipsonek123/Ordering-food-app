#include "mainwindow.h"
<<<<<<< HEAD
=======

#include "dbmanager.h"
#include <QtSql>

>>>>>>> f3789c68535ac3c02a0b3b1a24f3bc6fc74340e5
#include "produkt.h"
#include "ui_produkt.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"

<<<<<<< HEAD
=======

>>>>>>> f3789c68535ac3c02a0b3b1a24f3bc6fc74340e5
#include <QApplication>
#include <QLocale>
#include <QTranslator>
#include <QTimer>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    dbManager m_db("../database/foodDatabase.db");
    MainWindow w;
    w.show();
    return a.exec();
}
