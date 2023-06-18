#ifndef PRODUKT_H
#define PRODUKT_H
#include <QMainWindow>
#include <QStackedWidget>
#include <QSpinBox>
#include <QLabel>

#include "qlabel.h"
#include <QDialog>

class MainWindow;

namespace Ui {
class Produkt;
}

class Produkt : public QDialog
{
    Q_OBJECT

public:
    explicit Produkt(QWidget *parent = nullptr);
    void actualSum(QSpinBox* amountSpinBox, QLabel* priceLabel);
    ~Produkt();

public slots:


private slots:

    void handleStackedWidgetIndexChange(int index);
    void on_pushButton_2_clicked();

    void on_pushButton_clicked();

private:
    Ui::Produkt *ui;
    void savingProducts(QSpinBox* amountSpinBox, QLabel* priceLabel, QLabel* nameLabel);
    friend class MainWindow;
};

#endif // PRODUKT_H
