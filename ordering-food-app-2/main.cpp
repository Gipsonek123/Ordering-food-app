#include "mainwindow.h"
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
    MainWindow w;
    w.show();
    return a.exec();
}
