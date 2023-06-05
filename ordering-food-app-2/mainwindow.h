#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

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

private:
//    //zwykla
//    void on_pushButton_clicked();
//    //z podmenu
//    void on_pushButton_clicked_a();
//    void on_pushButton_clicked_2();
//    void on_pushButton_clicked_2a();

//    void on_pushButton_2_clicked();
//    void on_pushButton_3_clicked();
//    void on_pushButton_6_clicked();
//    void on_pushButton_7_clicked();
//    void on_pushButton_8_clicked();
//    void on_pushButton_9_clicked();
//    void on_pushButton_10_clicked();

//    //void on_progressBar_valueChanged(int value);

//    void on_pushButton_65_clicked();

//    void on_pushButton_11_clicked();

//    void nextPage();

    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
