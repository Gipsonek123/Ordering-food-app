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

    ui->name_1_1->setText(foods[0].writeFoodName());
    ui->price_1_1->setText(foods[0].writeFoodCost());
    ui->name_1_2->setText(addons[0].writeAddonsName());
    ui->price_1_2->setText(addons[0].writeAddonsCost());
    ui->name_1_3->setText(addons[1].writeAddonsName());
    ui->price_1_3->setText(addons[1].writeAddonsCost());
    ui->name_1_4->setText(addons[2].writeAddonsName());
    ui->price_1_4->setText(addons[2].writeAddonsCost());


    //produkt 2

    ui->name_2_1->setText(foods[1].writeFoodName());
    ui->price_2_1->setText(foods[1].writeFoodCost());
    ui->name_2_2->setText(addons[0].writeAddonsName());
    ui->price_2_2->setText(addons[0].writeAddonsCost());
    ui->name_2_3->setText(addons[1].writeAddonsName());
    ui->price_2_3->setText(addons[1].writeAddonsCost());
    ui->name_2_4->setText(addons[2].writeAddonsName());
    ui->price_2_4->setText(addons[2].writeAddonsCost());

    //produkt 3

    ui->name_3_1->setText(foods[2].writeFoodName());
    ui->price_3_1->setText(foods[2].writeFoodCost());
    ui->name_3_2->setText(addons[0].writeAddonsName());
    ui->price_3_2->setText(addons[0].writeAddonsCost());
    ui->name_3_3->setText(addons[1].writeAddonsName());
    ui->price_3_3->setText(addons[1].writeAddonsCost());
    ui->name_3_4->setText(addons[2].writeAddonsName());
    ui->price_3_4->setText(addons[2].writeAddonsCost());

    //produkt 4

    ui->name_4_1->setText(foods[3].writeFoodName());
    ui->price_4_1->setText(foods[3].writeFoodCost());
    ui->name_4_2->setText(addons[0].writeAddonsName());
    ui->price_4_2->setText(addons[0].writeAddonsCost());
    ui->name_4_3->setText(addons[1].writeAddonsName());
    ui->price_4_3->setText(addons[1].writeAddonsCost());
    ui->name_4_4->setText(addons[2].writeAddonsName());
    ui->price_4_4->setText(addons[2].writeAddonsCost());

    //produkt 5

    ui->name_5_1->setText(foods[4].writeFoodName());
    ui->price_5_1->setText(foods[4].writeFoodCost());
    ui->name_5_2->setText(addons[0].writeAddonsName());
    ui->price_5_2->setText(addons[0].writeAddonsCost());
    ui->name_5_3->setText(addons[1].writeAddonsName());
    ui->price_5_3->setText(addons[1].writeAddonsCost());
    ui->name_5_4->setText(addons[2].writeAddonsName());
    ui->price_5_4->setText(addons[2].writeAddonsCost());

    //produkt 6

    ui->name_6_1->setText(foods[5].writeFoodName());
    ui->price_6_1->setText(foods[5].writeFoodCost());
    ui->name_6_2->setText(addons[0].writeAddonsName());
    ui->price_6_2->setText(addons[0].writeAddonsCost());
    ui->name_6_3->setText(addons[1].writeAddonsName());
    ui->price_6_3->setText(addons[1].writeAddonsCost());
    ui->name_6_4->setText(addons[2].writeAddonsName());
    ui->price_6_4->setText(addons[2].writeAddonsCost());

    //produkt 7

    ui->name_7_1->setText(foods[6].writeFoodName());
    ui->price_7_1->setText(foods[6].writeFoodCost());

    //produkt 8

    ui->name_8_1->setText(foods[7].writeFoodName());
    ui->price_8_1->setText(foods[7].writeFoodCost());

    //produkt 9

    ui->name_9_1->setText(foods[8].writeFoodName());
    ui->price_9_1->setText(foods[8].writeFoodCost());

    //produkt 10

    ui->name_10_1->setText(foods[9].writeFoodName());
    ui->price_10_1->setText(foods[9].writeFoodCost());

    //produkt 11

    ui->name_11_1->setText(foods[10].writeFoodName());
    ui->price_11_1->setText(foods[10].writeFoodCost());

    //produkt 12

    ui->name_12_1->setText(foods[11].writeFoodName());
    ui->price_12_1->setText(foods[11].writeFoodCost());

    //produkt 13

    ui->name_13_1->setText(foods[12].writeFoodName());
    ui->price_13_1->setText(foods[12].writeFoodCost());

    //produkt 14

    ui->name_14_1->setText(foods[13].writeFoodName());
    ui->price_14_1->setText(foods[13].writeFoodCost());

    //produkt 15

    ui->name_15_1->setText(foods[14].writeFoodName());
    ui->price_15_1->setText(foods[14].writeFoodCost());

    //produkt 16

    ui->name_16_1->setText(foods[15].writeFoodName());
    ui->price_16_1->setText(foods[15].writeFoodCost());

    //produkt 17

    ui->name_17_1->setText(foods[16].writeFoodName());
    ui->price_17_1->setText(foods[16].writeFoodCost());

    //produkt 18

    ui->name_18_1->setText(foods[17].writeFoodName());
    ui->price_18_1->setText(foods[17].writeFoodCost());




}
