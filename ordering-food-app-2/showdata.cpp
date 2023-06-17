#include "dbmanager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>

void MainWindow::showData(std::vector<Food> foods)
{
    //Burgery
    ui->BurgerName_1 -> setText(foods[0].writeFoodName());
    ui->BurgerCost_1 -> setText(foods[0].writeFoodCost());

    ui->BurgerName_2 -> setText(foods[1].writeFoodName());
    ui->BurgerCost_2 -> setText(foods[1].writeFoodCost());

    ui->BurgerName_3 -> setText(foods[2].writeFoodName());
    ui->BurgerCost_3 -> setText(foods[2].writeFoodCost());

    //Pizza
    ui->PizzaName_1 -> setText(foods[3].writeFoodName());
    ui->PizzaCost_1 -> setText(foods[3].writeFoodCost());

    ui->PizzaName_2 -> setText(foods[4].writeFoodName());
    ui->PizzaCost_2 -> setText(foods[4].writeFoodCost());

    ui->PizzaName_3 -> setText(foods[5].writeFoodName());
    ui->PizzaCost_3 -> setText(foods[5].writeFoodCost());

    //Desserts

    ui->DessertName_1 -> setText(foods[6].writeFoodName());
    ui->DessertCost_1 -> setText(foods[6].writeFoodCost());

    ui->DessertName_2 -> setText(foods[7].writeFoodName());
    ui->DessertCost_2 -> setText(foods[7].writeFoodCost());

    ui->DessertName_3 -> setText(foods[8].writeFoodName());
    ui->DessertCost_3 -> setText(foods[8].writeFoodCost());

    //Salads

    ui->SaladName_1 -> setText(foods[9].writeFoodName());
    ui->SaladCost_1 -> setText(foods[9].writeFoodCost());

    ui->SaladName_2 -> setText(foods[10].writeFoodName());
    ui->SaladCost_2 -> setText(foods[10].writeFoodCost());

    ui->SaladName_3 -> setText(foods[11].writeFoodName());
    ui->SaladCost_3 -> setText(foods[11].writeFoodCost());

    //Snacks

    ui->SnackName_1 -> setText(foods[12].writeFoodName());
    ui->SnackCost_1 -> setText(foods[12].writeFoodCost());

    ui->SnackName_2 -> setText(foods[13].writeFoodName());
    ui->SnackCost_2 -> setText(foods[13].writeFoodCost());

    ui->SnackName_3 -> setText(foods[14].writeFoodName());
    ui->SnackCost_3 -> setText(foods[14].writeFoodCost());

    //Drinks

    ui->DrinkName_1 -> setText(foods[15].writeFoodName());
    ui->DrinkCost_1 -> setText(foods[15].writeFoodCost());

    ui->DrinkName_2 -> setText(foods[16].writeFoodName());
    ui->DrinkCost_2 -> setText(foods[16].writeFoodCost());

    ui->DrinkName_3 -> setText(foods[17].writeFoodName());
    ui->DrinkCost_3 -> setText(foods[17].writeFoodCost());
}
