#ifndef PRODUKT_H
#define PRODUKT_H

#include <QDialog>

namespace Ui {
class Produkt;
}

class Produkt : public QDialog
{
    Q_OBJECT

public:
    explicit Produkt(QWidget *parent = nullptr);
    ~Produkt();

public slots:
    void handleStackedWidgetIndexChange(int index);

private:
    Ui::Produkt *ui;
};

#endif // PRODUKT_H
