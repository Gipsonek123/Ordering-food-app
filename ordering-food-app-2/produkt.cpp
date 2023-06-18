#include "produkt.h"
#include "ui_produkt.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QLineEdit>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QTextStream>


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

void Produkt::savingProducts(QSpinBox* amountSpinBox, QLabel* priceLabel, QLabel* nameLabel)// funkcja zapisujaca produkty wraz z cenami do pliku tekstowego "zamowione_produkty"
{                                                                                               // do pliku tekstowego ceny produktow sa zapisywane tylko ceny
    int number = amountSpinBox->value(); // Odczytaj wartość z pola QSpinBox (ilość produktów)
    if(number > 0)
    {
        QString Strprice = priceLabel->text(); // Odczytaj tekst z pola QLabel(cena produktu)
        QString Name_of_product = nameLabel->text(); // odczytaj nazwe produktu
        Strprice.remove("zł"); // Usuń symbol waluty
        Strprice.replace(",", "."); // Zamień przecinek na kropkę
        double prize = Strprice.toDouble(); // Konwertuj oczyszczony string na liczbę zmiennoprzecinkową (cena za 1 produkt)
        double sum = number * prize;
        QString value = QString::number(sum, 'f', 2); // zamienia sume na stringa
        value.replace(".", ","); // Zamień kropke na przecinek
        QString quantity = QString::number(number);
        QString total = quantity +"x " + Name_of_product + " " + value + "zł";

        QFile file("ceny_produktow.txt"); // zapisanie tylko cen produktow
        if (!file.open(QIODevice::Append | QIODevice::Text))  // Otwieranie pliku w trybie dopisywania
        {
            qDebug() << "Nie można otworzyć pliku.";
        }

        // Tworzenie obiektu klasy QTextStream i powiązanie go z obiektem QFile
        QTextStream stream(&file);
        QString prizes = QString::number(sum);

        // Zapisywanie tekstu do strumienia
        stream << prizes << Qt::endl;

        // Zamykanie pliku
        file.close();

        QFile file1("zamowione_produkty.txt"); // zapisanie całego zamowienia
        if (!file1.open(QIODevice::Append | QIODevice::Text))  // Otwieranie pliku w trybie dopisywania
        {
            qDebug() << "Nie można otworzyć pliku.";
        }

        // Tworzenie obiektu klasy QTextStream i powiązanie go z obiektem QFile
        QTextStream stream1(&file1);

        // Zapisywanie tekstu do strumienia
        stream1 << total << Qt::endl;

        // Zamykanie pliku
        file.close();

    }
}

//void Produkt::actualSum(QSpinBox* amountSpinBox, QLabel* priceLabel) // funkcja do obliczania i wypisywania obecnej ceny, jako argumenty przyjmuje wskaźniki
//{                                                                         // do obiektów pierwszy pokazuje ilość danego produktu a drugi jego cenę
//    int number = amountSpinBox->value(); // Odczytaj wartość z pola QSpinBox (ilość produktów)
//    QString Strprice = priceLabel->text(); // Odczytaj tekst z pola QLabel(cena produktu)
//    Strprice.remove("zł"); // Usuń symbol waluty
//    Strprice.replace(",", "."); // Zamień przecinek na kropkę
//    double prize = Strprice.toDouble(); // Konwertuj oczyszczony string na liczbę zmiennoprzecinkową (cena za 1 produkt)

//    QString Strcurrentprize = ui->label_sum->text(); // odczytanie obecnej sumy
//    Strcurrentprize.remove("zł"); // Usuń symbol waluty
//    Strcurrentprize.replace(",", "."); // Zamień przecinek na kropkę
//    double currentprize = Strcurrentprize.toDouble(); // zamienia string z obecna cena na double

//    double sum;
//    sum = currentprize + (number * prize); // oblicza sume
//    QString value = QString::number(sum, 'f',2); // zamienia sume na stringa
//    value.replace(".", ","); // Zamień kropke na przecinek
//    QString zl = " zł";
//    QString total = value + zl;
//    ui->label_sum->setText(total); // wypisuje na ekranie obecna sume
//}


void Produkt::handleStackedWidgetIndexChange(int index)
{
    ui->stackedProductWidget->setCurrentIndex(index);
    show();
}

void Produkt::on_pushButton_2_clicked()
{
    //actual_sum(ui->Amount_item_1, ui->price_1);

    for (int i = 1; i <= 99; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
            QSpinBox* amountSpinBox = findChild<QSpinBox*>(QString("amountItem%1%2").arg(i).arg(j));// znajduje odpowiednie obiekty
            QLabel* priceLabel = findChild<QLabel*>(QString("price%1%2").arg(i).arg(j)); // znajduje odpowiednie obiekty
            QLabel* nameLabel = findChild<QLabel*>(QString("name%1%2").arg(i).arg(j)); // znajduje odpowiednie obiekty
            if (amountSpinBox && priceLabel && nameLabel) // jeśli znajdzie to wywołuje funkcje z odpowiednimi parametrami
            {
                savingProducts(amountSpinBox, priceLabel, nameLabel);
            }
        }
    }

    for (int i = 1; i <= 99; ++i)
    {
        for (int j = 0; j <= 9; ++j)
        {
                QSpinBox* amountSpinBox = findChild<QSpinBox*>(QString("amountItem%1%2").arg(i).arg(j)); // znajduje odpowiednie obiekty
                if (amountSpinBox) // jeśli  znajdzie to wywołuje funkcje
                {
                    amountSpinBox->setValue(0);
                }
            }
    }
}





void Produkt::on_pushButton_clicked()
{
    for (int i = 1; i <= 99; ++i)
    {
            for (int j = 0; j <= 9; ++j)
            {
                QSpinBox* amountSpinBox = findChild<QSpinBox*>(QString("amountItem%1%2").arg(i).arg(j)); // znajduje odpowiednie obiekty
                if (amountSpinBox) // jeśli  znajdzie to wywołuje funkcje
                {
                    amountSpinBox->setValue(0);
                }
            }
    }
}

