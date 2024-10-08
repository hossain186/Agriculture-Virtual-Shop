
#include "tractor.h"
#include "string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_machine/all_mechine.h"
#include "../../../Cart/Add to cart/cart.h"





Tracktor allTractors[6];
void showAllTractor() {
    strcpy(allTractors[0].name, "Supreme_DI_60_RX");
    allTractors[0].price = 1200;

    strcpy(allTractors[1].name, "Sonalika_All_Rounder_55");
    allTractors[1].price = 1499;

    strcpy(allTractors[2].name, "Supreme_DI_50_RX");
    allTractors[2].price = 999;

    strcpy(allTractors[3].name, "Supreme_DI_48_RX");
    allTractors[3].price = 600;

    strcpy(allTractors[4].name, "Supreme_DI_47_RX");
    allTractors[4].price = 4000;

    strcpy(allTractors[5].name, "Supreme_DI_45_RX");
    allTractors[5].price = 1199;

    // Show all tractors
    printf("************ Tractors ***********\n");

    for (int i = 0; i < 6; i++) {
        printf("        %c. %s(%dtk)  ", 'A' + i, allTractors[i].name, allTractors[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    chooseTractor();
}

void chooseTractor() {
    printf("Select Tractor/back: ");
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
            strcpy(productName, allTractors[productInd].name);
            productPrice = allTractors[productInd].price;

            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseTractor();
        } else {
            printf("Item not found!\n");
            chooseTractor();
        }
    }
}
