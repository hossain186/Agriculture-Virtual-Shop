

#include "powerTiller.h"
#include<string.h>
#include<stdio.h>
#include"../All_machine/all_mechine.h"
#include"../../../Cart/Add to cart/cart.h"
#include"../../../Home/home.h"




PowerTiller allPowerTillers[5];

void showAllPowerTiller() {
    // Initialize Power Tillers
    strcpy(allPowerTillers[0].name, "Power_Tiller_Model_A");
    allPowerTillers[0].price = 2200;

    strcpy(allPowerTillers[1].name, "Power_Tiller_Model_B");
    allPowerTillers[1].price = 2499;

    strcpy(allPowerTillers[2].name, "Power_Tiller_Model_C");
    allPowerTillers[2].price = 1999;

    strcpy(allPowerTillers[3].name, "Power_Tiller_Model_D");
    allPowerTillers[3].price = 1600;

    strcpy(allPowerTillers[4].name, "Power_Tiller_Model_E");
    allPowerTillers[4].price = 3000;
    strcpy(allPowerTillers[5].name, "Power_Tiller_Model_F");
    allPowerTillers[5].price = 400;

    // Show all Power Tillers
    printf("************ Power Tillers ***********\n");

    for (int i = 0; i < 5; i++) {
        printf("        %c. %s(%dtk)  ", 'A' + i, allPowerTillers[i].name, allPowerTillers[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    choosePowerTiller();
}


void choosePowerTiller() {
    printf("Select Power Tiller/back: ");
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

        if (userChosenInd <= endInd && strlen(userAns) ==1) {
            strcpy(productName, allPowerTillers[productInd].name);
            productPrice = allPowerTillers[productInd].price;

            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            choosePowerTiller();
        } else {
            printf("Item not found!\n");
            choosePowerTiller();
        }
    }
}
