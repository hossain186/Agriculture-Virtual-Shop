#include "waterPamp.h"
#include "string.h"
#include "stdio.h"
#include "../../../Home/home.h"
#include"../All_machine/all_mechine.h"
#include"../../../Cart/Add to cart/cart.h"
WaterPump allWaterPumps[6];

void showAllWaterPump() {
    strcpy(allWaterPumps[0].name, "PumpModel1");
    allWaterPumps[0].price = 800;

    strcpy(allWaterPumps[1].name, "PumpModel2");
    allWaterPumps[1].price = 1200;

    strcpy(allWaterPumps[2].name, "PumpModel3");
    allWaterPumps[2].price = 1000;

    strcpy(allWaterPumps[3].name, "PumpModel4");
    allWaterPumps[3].price = 1500;

    strcpy(allWaterPumps[4].name, "PumpModel5");
    allWaterPumps[4].price = 1300;

    strcpy(allWaterPumps[5].name, "PumpModel6");
    allWaterPumps[5].price = 1700;

    // Show all water pumps
    printf("************ Water Pumps ***********\n");

    for (int i = 0; i < 6; i++) {
        printf("        %c. %s(%dtk)  ", 'A' + i, allWaterPumps[i].name, allWaterPumps[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    chooseWaterPump();
}

void chooseWaterPump() {
    printf("Select Water Pump/back: ");
    char userAns[100];
    scanf("%s", userAns);

    toLower(userAns);
    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    // Added code from here
    if (back) {
        showAllTypesOfMachine(); // from-> All_Machinery/all_machines.c
    } else if (cart) {
        showAllCartItems(); // from-> Cart/Add_to_cart/cart.h
    } else {
        char productName[100];
        int productPrice;

        int startInd = (int) 'a';
        int endInd = (int) 'f';
        int userChosenInd = (int) userAns[0];
        int productInd = userChosenInd - startInd;

        if (endInd >= userChosenInd && strlen(userAns) ==1) {
            strcpy(productName, allWaterPumps[productInd].name);
            productPrice = allWaterPumps[productInd].price;

            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseWaterPump();
        } else {
            printf("Item not found!\n");
            chooseWaterPump();
        }
    }
}

