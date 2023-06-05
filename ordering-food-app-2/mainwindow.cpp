#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QTimer>

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
    progressBarLoading();
}

// gotowka przy kasie
void MainWindow::on_pushButton_5_clicked()
{
    //dodac progressbar, zrobic aby byl uniwersalny
    goToNextPage();

}

