#include "dbmanager.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "produkt.h"
#include "ui_produkt.h"
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

void Produkt::showAddons(std::vector<Addons> addons, std::vector<Food> foods)
{
    //produkt 1

    ui->name11->setText(foods[0].writeFoodName());
    ui->price11->setText(foods[0].writeFoodCost());
    ui->name12->setText(addons[0].writeAddonsName());
    ui->price12->setText(addons[0].writeAddonsCost());
    ui->name13->setText(addons[1].writeAddonsName());
    ui->price13->setText(addons[1].writeAddonsCost());
    ui->name14->setText(addons[2].writeAddonsName());
    ui->price14->setText(addons[2].writeAddonsCost());


    //produkt 2

    ui->name21->setText(foods[1].writeFoodName());
    ui->price21->setText(foods[1].writeFoodCost());
    ui->name22->setText(addons[0].writeAddonsName());
    ui->price22->setText(addons[0].writeAddonsCost());
    ui->name23->setText(addons[1].writeAddonsName());
    ui->price23->setText(addons[1].writeAddonsCost());
    ui->name24->setText(addons[2].writeAddonsName());
    ui->price24->setText(addons[2].writeAddonsCost());

    //produkt 3

    ui->name31->setText(foods[2].writeFoodName());
    ui->price31->setText(foods[2].writeFoodCost());
    ui->name32->setText(addons[0].writeAddonsName());
    ui->price32->setText(addons[0].writeAddonsCost());
    ui->name33->setText(addons[1].writeAddonsName());
    ui->price33->setText(addons[1].writeAddonsCost());
    ui->name34->setText(addons[2].writeAddonsName());
    ui->price34->setText(addons[2].writeAddonsCost());

    //produkt 4

    ui->name41->setText(foods[3].writeFoodName());
    ui->price41->setText(foods[3].writeFoodCost());
    ui->name42->setText(addons[0].writeAddonsName());
    ui->price42->setText(addons[0].writeAddonsCost());
    ui->name43->setText(addons[1].writeAddonsName());
    ui->price43->setText(addons[1].writeAddonsCost());
    ui->name44->setText(addons[2].writeAddonsName());
    ui->price44->setText(addons[2].writeAddonsCost());

    //produkt 5

    ui->name51->setText(foods[4].writeFoodName());
    ui->price51->setText(foods[4].writeFoodCost());
    ui->name52->setText(addons[0].writeAddonsName());
    ui->price52->setText(addons[0].writeAddonsCost());
    ui->name53->setText(addons[1].writeAddonsName());
    ui->price53->setText(addons[1].writeAddonsCost());
    ui->name54->setText(addons[2].writeAddonsName());
    ui->price54->setText(addons[2].writeAddonsCost());

    //produkt 6

    ui->name61->setText(foods[5].writeFoodName());
    ui->price61->setText(foods[5].writeFoodCost());
    ui->name62->setText(addons[0].writeAddonsName());
    ui->price62->setText(addons[0].writeAddonsCost());
    ui->name63->setText(addons[1].writeAddonsName());
    ui->price63->setText(addons[1].writeAddonsCost());
    ui->name64->setText(addons[2].writeAddonsName());
    ui->price64->setText(addons[2].writeAddonsCost());

    //produkt 7

    ui->name71->setText(foods[6].writeFoodName());
    ui->price71->setText(foods[6].writeFoodCost());

    //produkt 8

    ui->name81->setText(foods[7].writeFoodName());
    ui->price81->setText(foods[7].writeFoodCost());

    //produkt 9

    ui->name91->setText(foods[8].writeFoodName());
    ui->price91->setText(foods[8].writeFoodCost());

    //produkt 10

    ui->name101->setText(foods[9].writeFoodName());
    ui->price101->setText(foods[9].writeFoodCost());

    //produkt 11

    ui->name111->setText(foods[10].writeFoodName());
    ui->price111->setText(foods[10].writeFoodCost());

    //produkt 12

    ui->name121->setText(foods[11].writeFoodName());
    ui->price121->setText(foods[11].writeFoodCost());

    //produkt 13

    ui->name131->setText(foods[12].writeFoodName());
    ui->price131->setText(foods[12].writeFoodCost());

    //produkt 14

    ui->name141->setText(foods[13].writeFoodName());
    ui->price141->setText(foods[13].writeFoodCost());

    //produkt 15

    ui->name151->setText(foods[14].writeFoodName());
    ui->price151->setText(foods[14].writeFoodCost());

    //produkt 16

    ui->name161->setText(foods[15].writeFoodName());
    ui->price161->setText(foods[15].writeFoodCost());

    //produkt 17

    ui->name171->setText(foods[16].writeFoodName());
    ui->price171->setText(foods[16].writeFoodCost());

    //produkt 18

    ui->name181->setText(foods[17].writeFoodName());
    ui->price181->setText(foods[17].writeFoodCost());
}
