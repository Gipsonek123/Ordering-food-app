#include "produkt.h"
#include "ui_produkt.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dbmanager.h"
#include <vector>
#include <QTimer>
#include <QFile>
#include <QLineEdit>
#include <QDateTime>
#include <QDebug>
#include <QTime>
#include <QFile>
#include <QTextStream>
#include <QRegularExpression> // do wycinania ze string wartosci liczbowej
#include <QPixmap>

std::vector<Food> resultFood;

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QPixmap pix(":/img/img/drink.jpg");
    QPixmap loading(":/img/img/truck1.jpg");
    QPixmap takeaway(":/img/img/coffee.jpg");
    QPixmap menu(":/img/img/emptyMenu.jpg");

    ui->label_5->setPixmap(pix);
    ui->label_9->setPixmap(loading);
    ui->label_10->setPixmap(takeaway);
    ui->label_2->setPixmap(menu);

    // przyciski "wyjscia"
    connect(ui->btnExit1, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit2, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit3, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit4, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit5, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit6, &QPushButton::clicked, this, &MainWindow::resetData);
    connect(ui->btnExit7, &QPushButton::clicked, this, &MainWindow::resetData);

//    Produkt *p = new Produkt();

//    connect(p->ui->pushButton_2,  &QPushButton::clicked, this &MainWindow::totalPrice("ceny_produktow.txt", ui->label_sum));
    // nie dziala
//    connect(pushbutton, &QPushButton::clicked, this, [=]() {
//        totalPrice("ceny_produktow.txt", ui->label_sum);
//    });

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
            produktBtn = ui->product10Btn;
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
        connect(produktBtn, &QPushButton::clicked, this, [produkt,i,this](){
            produkt->handleStackedWidgetIndexChange(i);
            totalPrice("ceny_produktow.txt", ui->label_sum);
        });

    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::progressBarLoading(QProgressBar* progressBar)
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, [=]() { MainWindow::updateProgressBar(progressBar, timer, &value);
    });
//    updateProgressBar(progressBar)});
    timer->start(20);

}

//void MainWindow::updateProgressBar()
void MainWindow::updateProgressBar(QProgressBar *progressBarName, QTimer* timer, int* value)
{
    if (progressBarName && value) {
        progressBarName->setValue(*value);
        if (*value > 100) {
            // to ponizej robimy tylko po to, aby przeskoczylo nam o 1 strone, a nie do samego
//            QTimer* timer = qobject_cast<QTimer*>(sender()); // Pobierz wskaźnik na QTimer
              timer->stop();
            goToNextPage();
           // Zatrzymaj QTimer
            *value = 0;
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

    ui->label_receipt_1->setText(paragon); // wypisanie w oknie
}

void MainWindow::orderNumber() //funkcja wypisujaca na ekran date, godzine i numer zamowienia
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


void MainWindow::cleanFile(const QString& file_patch) //funkcja czyszczaca plik
{
    QFile file(file_patch);

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

void MainWindow::readFileContents(const QString& filePath, QLabel* window)// funkcja odczytujaca zawartosc z pliku(zamowione produkty) i wypisujaca na ekran
{
    QFile file(filePath);

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // obsługa błędu odczytu pliku
    }

    QTextStream in(&file);
    QString fileContents = in.readAll();

    file.close();

    window->setText(fileContents); // wypisz w oknie

}


void MainWindow::totalPrice(const QString& filePath, QLabel* window)
{
    double total = 0;

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        // Obsługa błędu, jeśli nie udało się otworzyć pliku
    }

    // Utwórz obiekt klasy QTextStream i skojarz go z obiektem QFile
    QTextStream in(&file);

    // Odczytaj dane linia po linii, dopóki nie osiągniesz końca pliku
    while (!in.atEnd())
    {
        QString line = in.readLine();
        double prize = line.toDouble();
        total += prize;
    }

    // Zamknij plik po zakończeniu odczytu
    file.close();
    QString total_price = QString::number(total, 'f', 2);
    total_price.replace(".", ","); // Zamień kropke na przecinek
    QString sum_all = "Suma: " + total_price + "zł";
    window->setText(sum_all); // wypisz w oknie
}

void MainWindow::saveTextToFile(const QString& file_patch, const QString& text)
{
    QFile file(file_patch);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        QTextStream stream(&file);
        stream << text << '\n';
        file.close();
    }
}

void MainWindow::goToFirstPage()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::clearData()
{
    cleanFile("zamowione_produkty.txt");
    cleanFile("ceny_produktow.txt");
    ui->label_summary->clear();
    ui->label_receipt_2->clear();
    ui->label_receipt_3->clear();
}

void MainWindow::resetData()
{
    clearData();
    goToFirstPage();
}

void MainWindow::on_pushButton_1_clicked()
{
    goToNextPage();
    progressBarLoading(ui->progressBar);
}

// na miejscu
void MainWindow::on_pushButton_2_clicked()
{

//    goToNextPage();
    resultFood = writeFoodToVectorOfObjects();
    showData(resultFood);
    saveTextToFile("zamowione_produkty.txt", "1x Opakowanie 2,00zł");
    saveTextToFile("ceny_produktow.txt", "2");
    goToNextPage();
}

// na wynos
void MainWindow::on_pushButton_3_clicked()
{
    goToNextPage();
    resultFood = writeFoodToVectorOfObjects();
    showData(resultFood);
}


// karta online/tutaj
void MainWindow::on_pushButton_4_clicked()
{
    goToNextPage();
    orderNumber();
}

// gotowka przy kasie
void MainWindow::on_pushButton_5_clicked()
{
    goToNextPage();
    orderNumber();
}

//wyswietl paragon
void MainWindow::on_pushButton_7_clicked()
{
    goToNextPage();
    receipt();
    readFileContents("zamowione_produkty.txt", ui->label_receipt_2);
    totalPrice("ceny_produktow.txt", ui->label_receipt_3);
    cleanFile("zamowione_produkty.txt");
    cleanFile("ceny_produktow.txt");
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

// zaplac
void MainWindow::on_pushButton_10_clicked()
{
    goToNextPage();
}

void MainWindow::on_pushButton_18_clicked()
{
    goToPreviousPage();
}

void MainWindow::on_pushButton_19_clicked()
{
    changeMenuPage();
}

//przejdz dalej (Salatki)
void MainWindow::on_pushButton_20_clicked()
{
    goToNextPage();
    readFileContents("zamowione_produkty.txt", ui->label_summary);
    totalPrice("ceny_produktow.txt", ui->label_total_price);
}







