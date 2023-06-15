#include "mainwindow.h"
#include "produkt.h"
#include "ui_mainwindow.h"
#include <QTimer>
#include <QFile>
#include <QLineEdit>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression> // do wycinania ze string wartosci liczbowej

#include "dbmanager.h"
#include <vector>
#include <iostream>

std::vector<Food> resultFood = writeFoodToVectorOfObjects();

#include <QPixmap>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/img/img/startPict2.jpg");
    QPixmap loading(":/img/img/loading.jpg");
    QPixmap takeaway(":/img/img/menu.jpg");
    ui->label_5->setPixmap(pix);
    ui->label_9->setPixmap(loading);
    ui->label_10->setPixmap(takeaway);

    // przyciski "wyjscia"
    connect(ui->btnExit1, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit2, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit3, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit4, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit5, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit6, &QPushButton::clicked, this, &MainWindow::goToFirstPage);
    connect(ui->btnExit7, &QPushButton::clicked, this, &MainWindow::goToFirstPage);


    // nowa wersja
    for(int i=0; i<18; ++i){
        Produkt* produkt = new Produkt;
        QPushButton* produktBtn = nullptr;

        switch(i){
        case 0:
            produktBtn = ui->product1Btn;
            break;
        case 1:
            produktBtn = ui->product2Btn;
            break;
        case 2:
            produktBtn = ui->product3Btn;
            break;
        case 3:
            produktBtn = ui->product4Btn;
            break;
        case 4:
            produktBtn = ui->product5Btn;
            break;
        case 5:
            produktBtn = ui->product6Btn;
            break;
        case 6:
            produktBtn = ui->product7Btn;
            break;
        case 7:
            produktBtn = ui->product8Btn;
            break;
        case 8:
            produktBtn = ui->product9Btn;
            break;
        case 9:
//            produktBtn = ui->product11Btn_2;
            break;
        case 10:
            produktBtn = ui->product11Btn;
            break;
        case 11:
            produktBtn = ui->product12Btn;
            break;
        case 12:
            produktBtn = ui->product13Btn;
            break;
        case 13:
            produktBtn = ui->product14Btn;
            break;
        case 14:
            produktBtn = ui->product15Btn;
            break;
        case 15:
            produktBtn = ui->product16Btn;
            break;
        case 16:
            produktBtn = ui->product17Btn;
            break;
        case 17:
            produktBtn = ui->product18Btn;
            break;
        }
        connect(produktBtn, &QPushButton::clicked, this, [produkt,i](){
            produkt->handleStackedWidgetIndexChange(i);
        });
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}





void MainWindow::progressBarLoading()

//void MainWindow::progressBarLoading()
void MainWindow::progressBarLoading(QProgressBar* progressBar)

{
    QTimer* timer = new QTimer(this);
//    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar(progressBar));
//    connect(timer, &QTimer::timeout, this, [=]() {
//        updateProgressBar(progressBar); // Wywołanie updateProgressBar z przekazanym progressBar
//    });
//    static int value = 0;
    connect(timer, &QTimer::timeout, this, [=]() { MainWindow::updateProgressBar(progressBar, timer, &value);
    });
//    updateProgressBar(progressBar)});
    timer->start(20);

}

//void MainWindow::updateProgressBar()
void MainWindow::updateProgressBar(QProgressBar *progressBarName, QTimer* timer, int* value)
{
//    static int value = 0;
//    ui->progressBar->setValue(value);
    qDebug() << "Current value: " << *value << "tak: " << progressBarName;
    if (progressBarName && value) {
//        QProgressBar* progressBarName = findChild<QProgressBar*>(progressBar);
//        QString progressBarName = progressBar->objectName();
//        MainWindow* mainWindow = qobject_cast<MainWindow*>(progressBar->parentWidget());
        progressBarName->setValue(*value);
//        updateProgressBar(progressBar,*value);
        if (*value > 100) {
            // to ponizej robimy tylko po to, aby przeskoczylo nam o 1 strone, a nie do samego
//            QTimer* timer = qobject_cast<QTimer*>(sender()); // Pobierz wskaźnik na QTimer
              timer->stop();
            goToNextPage();
//            if (timer) {
//            counter+=1;
           // Zatrzymaj QTimer
            *value = 0;
//            }
    }
        (*value)++;
    }

}

void MainWindow::goToNextPage()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int nextPageIndex = currentIndex + 1;

    // Sprawdź, czy nextPageIndex nie przekracza liczby stron w QStackedWidget.
    if (nextPageIndex < ui->stackedWidget->count())
    {
        ui->stackedWidget->setCurrentIndex(nextPageIndex);
    }
}

void MainWindow::goToPreviousPage()
{
    int currentIndex = ui->stackedWidget->currentIndex();
    int previousPageIndex = currentIndex - 1;

    // Sprawdź, czy nextPageIndex nie przekracza liczby stron w QStackedWidget.
    if (previousPageIndex < ui->stackedWidget->count())
    {
        ui->stackedWidget->setCurrentIndex(previousPageIndex);
    }
}

void MainWindow::goToFirstPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::changeMenuPage()
{
    int index = ui->stackedWidget_2->currentIndex();
    if(index==1){
         ui->stackedWidget_2->setCurrentIndex(0);

    }else{
         ui->stackedWidget_2->setCurrentIndex(1);
    }
}


void MainWindow::receipt() // funkcja wypisujaca na ekran numer paragonu
{
    int newNumber1;
    int previousNumber1;

    QFile file1("numer_paragonu.txt");
    if (!file1.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku.";
    }

    // Odczytaj poprzednią liczbę
    QString previousNumber1Str = file1.readAll();
    previousNumber1 = previousNumber1Str.toInt();

    // Zwiększ poprzednią liczbę o 1
    newNumber1 = previousNumber1 + 1;

    // Zapisz nową liczbę do pliku
    file1.resize(0);
    QTextStream stream1(&file1);
    stream1 << newNumber1;
    file1.close();

    QString numer_par = QString::number(newNumber1);
    QString numer_paragonu = "Numer paragonu: ";

    QString zera;
    if (newNumber1 >= 10)
    {
        zera = "00000";
    }
    else
    {
        zera = "000000";
    }

    QString paragon = numer_paragonu + zera + numer_par;

    ui->label_receipt->setText(paragon); // wypisanie w oknie
}

void MainWindow::order_number() //funkcja wypisujaca na ekran date, godzine i numer zamowienia
{
    int newNumber;
    int previousNumber;

    // Otwórz plik
    QFile file("numer_zamowienia.txt");
    if (!file.open(QIODevice::ReadWrite | QIODevice::Text)) {
        qDebug() << "Nie można otworzyć pliku.";
    }

    // Odczytaj poprzednią liczbę
    QString previousNumberStr = file.readAll();
    previousNumber = previousNumberStr.toInt();

    // Zwiększ poprzednią liczbę o 1
    newNumber = previousNumber + 1;

    // Zapisz nową liczbę do pliku
    file.resize(0);
    QTextStream stream(&file);
    stream << newNumber;
    file.close();


    if(newNumber == 99)
    {
        QFile file("numer_zamowienia.txt");
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
            qDebug() << "Nie można otworzyć pliku.";
        }

        // Zapisz pustą zawartość do pliku
        QTextStream stream(&file);
        stream << "";

        // Wymuś zapis do pliku
        stream.flush();

        // Zamknij plik
        file.close();
    }

    QString numer_zamowienia = QString::number(newNumber);
    QTime time = QTime::currentTime();
    QString czas = time.toString("hh : mm : ss");
    QDateTime data1 = QDateTime::currentDateTime();
    QString data = data1.toString("dd.MM.yyyy");
    QString napis = "Twój numer zamówienia to: ";
    QString data_time = data + "\n" + czas;
    ui->label_time1->setText(data_time);
    QString nr_zam = napis + numer_zamowienia;
    ui->label_numer_zamowienia->setText(nr_zam); // wypisz w oknie
}


//void MainWindow::actual_sum(QSpinBox* amountSpinBox, QLabel* priceLabel) // funkcja do obliczania i wypisywania obecnej ceny, jako argumenty przyjmuje wskaźniki
//{                                                                         // do obiektów pierwszy pokazuje ilość danego produktu a drugi jego cenę
//    int number = amountSpinBox->value(); // Odczytaj wartość z pola QSpinBox (ilość produktów)
//    QString Strprice = priceLabel->text(); // Odczytaj tekst z pola QLabel(cena produktu)
//    Strprice.remove("zł"); // Usuń symbol waluty
//    Strprice.replace(",", "."); // Zamień przecinek na kropkę
//    double prize = Strprice.toDouble(); // Konwertuj oczyszczony string na liczbę zmiennoprzecinkową (cena za 1 produkt)

//    QString Strcurrentprize = ui->label_sum->text(); // odczytanie obecnej sumy
//    Strcurrentprize.remove("zł"); // Usuń symbol waluty
//    double currentprize = Strcurrentprize.toDouble(); // zamienia string z obecna cena na double

//    double sum;
//    sum = currentprize + (number * prize); // oblicza sume
//    QString value = QString::number(sum); // zamienia sume na stringa
//    QString zl = " zł";
//    QString total = value + zl;
//    ui->label_sum->setText(total); // wypisuje na ekranie obecna sume
//}


void MainWindow::on_pushButton_clicked()
{
    goToNextPage();

    progressBarLoading();


    progressBarLoading(ui->progressBar);

}

// na wynos
void MainWindow::on_pushButton_3_clicked()
{
//    goToNextPage();
    goToNextPage();

//    progressBarLoading(ui->progressBar_3);
}

// na miejscu
void MainWindow::on_pushButton_2_clicked()
{
    goToNextPage();
//    goToNextPage();

//    progressBarLoading(ui->progressBar_3);
}

// przejdz do koszyka/poodsumowania
void MainWindow::on_pushButton_6_clicked()
{
    goToNextPage();
//    progressBarLoading();
}

// zaplac
void MainWindow::on_pushButton_10_clicked()
{
    goToNextPage();
}

// karta online/tutaj
void MainWindow::on_pushButton_4_clicked()
{
    goToNextPage();
 //   progressBarLoading();
    order_number();
}

// gotowka przy kasie
void MainWindow::on_pushButton_5_clicked()
{
    //dodac progressbar, zrobic aby byl uniwersalny
    goToNextPage();
}

//wyswietl paragon
void MainWindow::on_pushButton_7_clicked()
{
    goToNextPage();
    receipt();
}


//void MainWindow::on_Btn_item_1_clicked()
//{
//    actual_sum(ui->Amount_item_1, ui->Price_1);
//    ui->Amount_item_1->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_2_clicked()
//{
//    actual_sum(ui->Amount_item_2, ui->Price_2);
//    ui->Amount_item_2->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_3_clicked()
//{
//    actual_sum(ui->Amount_item_3, ui->Price_3);
//    ui->Amount_item_3->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_4_clicked()
//{
//    actual_sum(ui->Amount_item_4, ui->Price_4);
//    ui->Amount_item_4->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_5_clicked()
//{
//    actual_sum(ui->Amount_item_5, ui->Price_5);
//    ui->Amount_item_5->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_6_clicked()
//{
//    actual_sum(ui->Amount_item_6, ui->Price_6);
//    ui->Amount_item_6->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_7_clicked()
//{
//    actual_sum(ui->Amount_item_7, ui->Price_7);
//    ui->Amount_item_7->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_8_clicked()
//{
//    actual_sum(ui->Amount_item_8, ui->Price_8);
//    ui->Amount_item_8->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_9_clicked()
//{
//    actual_sum(ui->Amount_item_9, ui->Price_9);
//    ui->Amount_item_9->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_10_clicked()
//{
//    actual_sum(ui->Amount_item_10, ui->Price_10);
//    ui->Amount_item_10->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_11_clicked()
//{
//    actual_sum(ui->Amount_item_11, ui->Price_11);
//    ui->Amount_item_11->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_12_clicked()
//{
//    actual_sum(ui->Amount_item_12, ui->Price_12);
//    ui->Amount_item_12->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_13_clicked()
//{
//    actual_sum(ui->Amount_item_13, ui->Price_13);
//    ui->Amount_item_13->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_14_clicked()
//{
//    actual_sum(ui->Amount_item_14, ui->Price_14);
//    ui->Amount_item_14->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_15_clicked()
//{
//    actual_sum(ui->Amount_item_15, ui->Price_15);
//    ui->Amount_item_15->setValue(0);// resetuje ilość
//}


//void MainWindow::on_Btn_item_16_clicked()
//{
//    actual_sum(ui->Amount_item_16, ui->Price_16);
//    ui->Amount_item_16->setValue(0);// resetuje ilość
//}


//void MainWindow::on_toolButton_clicked()
//{
//    ui->stackedWidget2->setCurrentIndex(1);// przejscie do kolejnej strony
//}


//void MainWindow::on_pushButton_65_clicked()
//{
//    ui->stackedWidget2->setCurrentIndex(0); // przejscie do poprzedniej strony
//}


// po wyborze czy na miejscu, czy na wynos (progressbar)
void MainWindow::on_progressBar_3_valueChanged()
{
    goToNextPage();
}


void MainWindow::on_product1Btn_clicked()
{
}

//przejdz dalej (Zupy)
void MainWindow::on_pushButton_26_clicked()
{
    goToNextPage();
}

//przejdz dalej (Salatki)
void MainWindow::on_pushButton_20_clicked()
{
    goToNextPage();

}

//w podsumowaniu zamowienia poprzednia strona
void MainWindow::on_pushButton_8_clicked()
{
    goToPreviousPage();
}

//kup taniej
void MainWindow::on_pushButton_9_clicked()
{
    goToPreviousPage();
}


void MainWindow::on_pushButton_19_clicked()
{
    changeMenuPage();
}


void MainWindow::on_pushButton_18_clicked()
{
    goToPreviousPage();
}

//
void MainWindow::on_pushButton_12_clicked()
{
    goToFirstPage();
}

