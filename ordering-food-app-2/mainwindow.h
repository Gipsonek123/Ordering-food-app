#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>
#include <QSpinBox>
#include <QLabel>


#include <QWidget> // elementy uzytkownika, w tym progress bar
#include <QThread> //biblioteka m.in do animacji progressbaru


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();
    void goToNextPage();
    void progressBarLoading();
    void updateProgressBar();
    void on_pushButton_3_clicked();

    void on_pushButton_2_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_10_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_7_clicked();

    void on_Btn_item_1_clicked();

    void on_Btn_item_2_clicked();

    void on_Btn_item_3_clicked();

    void on_Btn_item_4_clicked();

    void on_Btn_item_5_clicked();

    void on_Btn_item_6_clicked();

    void on_Btn_item_7_clicked();

    void on_Btn_item_8_clicked();

    void on_Btn_item_9_clicked();

    void on_pushButton_11_clicked();

    void on_Btn_item_10_clicked();

    void on_Btn_item_11_clicked();

    void on_Btn_item_12_clicked();

    void on_Btn_item_13_clicked();

    void on_Btn_item_14_clicked();

    void on_Btn_item_15_clicked();

    void on_Btn_item_16_clicked();

    void on_toolButton_clicked();

    void on_pushButton_65_clicked();

private:

    Ui::MainWindow *ui;
    void receipt();
    void order_number();
    void actual_sum(QSpinBox* amountSpinBox, QLabel* priceLabel);
};
#endif // MAINWINDOW_H
