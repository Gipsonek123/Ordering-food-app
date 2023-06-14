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
#include <QRegularExpression> // do wycinania ze string wartosci liczbowej


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::progressBarLoading()
{
    QTimer* timer = new QTimer(this);
    connect(timer, &QTimer::timeout, this, &MainWindow::updateProgressBar);
    timer->start(25);
}

void MainWindow::updateProgressBar()
{
    static int value = 0;
    ui->progressBar->setValue(value);

    if (value >= 100) {
        goToNextPage();
        // to ponizej robimy tylko po to, aby przeskoczylo nam o 1 strone, a nie do samego
        QTimer* timer = qobject_cast<QTimer*>(sender()); // Pobierz wskaźnik na QTimer
        if (timer) {
            timer->stop(); // Zatrzymaj QTimer
        }
    }

    value++;
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


void MainWindow::actual_sum(QSpinBox* amountSpinBox, QLabel* priceLabel) // funkcja do obliczania i wypisywania obecnej ceny, jako argumenty przyjmuje wskaźniki
{                                                                         // do obiektów pierwszy pokazuje ilość danego produktu a drugi jego cenę
    int number = amountSpinBox->value(); // Odczytaj wartość z pola QSpinBox (ilość produktów)
    QString Strprice = priceLabel->text(); // Odczytaj tekst z pola QLabel(cena produktu)
    Strprice.remove("zł"); // Usuń symbol waluty
    Strprice.replace(",", "."); // Zamień przecinek na kropkę
    double prize = Strprice.toDouble(); // Konwertuj oczyszczony string na liczbę zmiennoprzecinkową (cena za 1 produkt)

    QString Strcurrentprize = ui->label_sum->text(); // odczytanie obecnej sumy
    Strcurrentprize.remove("zł"); // Usuń symbol waluty
    Strcurrentprize.replace(",", "."); // Zamień przecinek na kropkę
    double currentprize = Strcurrentprize.toDouble(); // zamienia string z obecna cena na double

    double sum;
    sum = currentprize + (number * prize); // oblicza sume
    QString value = QString::number(sum, 'f', 2); // zamienia sume na stringa
    value.replace(".", ","); // Zamień kropke na przecinek
    QString zl = " zł";
    QString total = value + zl;
    ui->label_sum->setText(total); // wypisuje na ekranie obecna sume
}


void MainWindow::saving_products(QSpinBox* amountSpinBox, QLabel* priceLabel, QLabel* nameLabel)// funkcja zapisujaca produkty wraz z cenami do pliku tekstowego "zamowione_produkty"
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

void MainWindow::clean_file(const QString& file_patch) //funkcja czyszczaca plik
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

void MainWindow::read_file_contents(const QString& filePath)// funkcja odczytujaca zawartosc z pliku(zamowione produkty) i wypisujaca na ekran
{
        QFile file(filePath);

        if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        {
        // obsługa błędu odczytu pliku
        }

        QTextStream in(&file);
        QString fileContents = in.readAll();

        file.close();

        ui->label_summary->setText(fileContents); // wypisz w oknie

}


void MainWindow::total_price(const QString& filePath)
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
        ui->label_total_price->setText(sum_all); // wypisz w oknie
}


void MainWindow::on_pushButton_clicked()
{
    goToNextPage();
    progressBarLoading();
}

// na wynos
void MainWindow::on_pushButton_3_clicked()
{
    goToNextPage();

}

// na miejscu
void MainWindow::on_pushButton_2_clicked()
{
    goToNextPage();
}

// przejdz do koszyka/poodsumowania
void MainWindow::on_pushButton_6_clicked()
{
    goToNextPage();
    progressBarLoading();
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
    read_file_contents("zamowione_produkty.txt");
    total_price("ceny_produktow.txt");
    clean_file("ceny_produktow.txt");
    clean_file("zamowione_produkty.txt");
}


void MainWindow::on_Btn_item_1_clicked()
{
    actual_sum(ui->Amount_item_1, ui->Price_1);
    saving_products(ui->Amount_item_1, ui->Price_1, ui->Product_1);
    ui->Amount_item_1->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_2_clicked()
{
    actual_sum(ui->Amount_item_2, ui->Price_2);
    saving_products(ui->Amount_item_2, ui->Price_2, ui->Product_2);
    ui->Amount_item_2->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_3_clicked()
{
    actual_sum(ui->Amount_item_3, ui->Price_3);
    saving_products(ui->Amount_item_3, ui->Price_3, ui->Product_3);
    ui->Amount_item_3->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_4_clicked()
{
    actual_sum(ui->Amount_item_4, ui->Price_4);
    saving_products(ui->Amount_item_4, ui->Price_4, ui->Product_4);
    ui->Amount_item_4->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_5_clicked()
{
    actual_sum(ui->Amount_item_5, ui->Price_5);
    saving_products(ui->Amount_item_5, ui->Price_5, ui->Product_5);
    ui->Amount_item_5->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_6_clicked()
{
    actual_sum(ui->Amount_item_6, ui->Price_6);
    saving_products(ui->Amount_item_6, ui->Price_6, ui->Product_6);
    ui->Amount_item_6->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_7_clicked()
{
    actual_sum(ui->Amount_item_7, ui->Price_7);
    saving_products(ui->Amount_item_7, ui->Price_7, ui->Product_7);
    ui->Amount_item_7->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_8_clicked()
{
    actual_sum(ui->Amount_item_8, ui->Price_8);
    saving_products(ui->Amount_item_8, ui->Price_8, ui->Product_8);
    ui->Amount_item_8->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_9_clicked()
{
    actual_sum(ui->Amount_item_9, ui->Price_9);
    saving_products(ui->Amount_item_9, ui->Price_9, ui->Product_9);
    ui->Amount_item_9->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_10_clicked()
{
    actual_sum(ui->Amount_item_10, ui->Price_10);
    saving_products(ui->Amount_item_10, ui->Price_10, ui->Product_10);
    ui->Amount_item_10->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_11_clicked()
{
    actual_sum(ui->Amount_item_11, ui->Price_11);
    saving_products(ui->Amount_item_11, ui->Price_11, ui->Product_11);
    ui->Amount_item_11->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_12_clicked()
{
    actual_sum(ui->Amount_item_12, ui->Price_12);
    saving_products(ui->Amount_item_12, ui->Price_12, ui->Product_12);
    ui->Amount_item_12->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_13_clicked()
{
    actual_sum(ui->Amount_item_13, ui->Price_13);
    saving_products(ui->Amount_item_13, ui->Price_13, ui->Product_13);
    ui->Amount_item_13->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_14_clicked()
{
    actual_sum(ui->Amount_item_14, ui->Price_14);
    saving_products(ui->Amount_item_14, ui->Price_14, ui->Product_14);
    ui->Amount_item_14->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_15_clicked()
{
    actual_sum(ui->Amount_item_15, ui->Price_15);
    saving_products(ui->Amount_item_15, ui->Price_15, ui->Product_15);
    ui->Amount_item_15->setValue(0);// resetuje ilość
}


void MainWindow::on_Btn_item_16_clicked()
{
    actual_sum(ui->Amount_item_16, ui->Price_16);
    saving_products(ui->Amount_item_16, ui->Price_16, ui->Product_16);
    ui->Amount_item_16->setValue(0);// resetuje ilość
}


void MainWindow::on_toolButton_clicked()
{
    ui->stackedWidget2->setCurrentIndex(1);// przejscie do kolejnej strony
}


void MainWindow::on_pushButton_65_clicked()
{
    ui->stackedWidget2->setCurrentIndex(0); // przejscie do poprzedniej strony
}

