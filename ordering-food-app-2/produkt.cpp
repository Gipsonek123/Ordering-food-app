#include "produkt.h"
#include "ui_produkt.h"

Produkt::Produkt(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Produkt)
{
    ui->setupUi(this);
}

Produkt::~Produkt()
{
    delete ui;
}


void Produkt::handleStackedWidgetIndexChange(int index)
{
    ui->stackedProductWidget->setCurrentIndex(index);
    show();
}
