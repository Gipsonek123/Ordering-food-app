#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSpinBox>
#include <QLabel>
#include <QProgressBar>

#include <QWidget> // elementy uzytkownika, w tym progress bar
#include <QThread> //biblioteka m.in do animacji progressbaru
#include "dbmanager.h"
#include <vector>

//#include "product.h" // to dodalem

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void progressBarLoading(QProgressBar *progressBar);
    void updateProgressBar(QProgressBar *progressBar, QTimer* timer, int* value);
    void showData(std::vector<Food>);
signals:
    void changeProductStackedWidgetIndex(int index);
private slots:
    void on_pushButton_clicked();
    void goToNextPage();

    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_progressBar_3_valueChanged();

    void on_product1Btn_clicked();

    void goToPreviousPage();

    void changeMenuPage();
    void goToFirstPage();

    void on_pushButton_26_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_12_clicked();


private:

    Ui::MainWindow *ui;

    void receipt();
    void order_number();

    void actual_sum(QSpinBox* amountSpinBox, QLabel* priceLabel);
    int value = 0;
};
#endif // MAINWINDOW_H
