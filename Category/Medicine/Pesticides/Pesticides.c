#include <stdio.h>
#include "Pesticides.h"
#include "string.h"
#include "../../../Home/home.h"
#include "../All_Medicine/All_medicine.h"
#include "../../../Cart/Add to cart/cart.h"

Pesticide allPesticides[6];

// Function to show all types of pesticides
void showAllPesticides() {
    // Initialize pesticides
    strcpy(allPesticides[0].name, "Ripcord_Insecticide(10 EC – Cypermethrin)");
    allPesticides[0].price = 500;  // Example price
    strcpy(allPesticides[1].name, "Nitro_Insecticide_505_EC_(Chlorpyrifos_+_Cypermethrin)");
    allPesticides[1].price = 1500;  // Example price
    strcpy(allPesticides[2].name, "Fighter_2.5_EC_Lambda_Cyhalothrin");
    allPesticides[2].price = 1000;  // Example price
    strcpy(allPesticides[3].name, "Neem_Oil_for_Plants");
    allPesticides[3].price = 700;  // Example price
    strcpy(allPesticides[4].name, "Imitaf_20_SL_(Imidacloprid)");
    allPesticides[4].price = 1200;  // Example price
    strcpy(allPesticides[5].name, "Neem_Cake_Powder");
    allPesticides[5].price = 800;  // Example price


    printf("********* Pesticides *********\n");
    for (int i = 0; i < 6; i++) {
        printf("      %c. %s(%dtk)\n", 'A' + i, allPesticides[i].name, allPesticides[i].price);
        if (i  % 2 == 0 ) {
            printf("\n");
        }
    }

    printf("\n");

    choosePesticide();
}

// Function to allow user to choose a pesticide or go back
void choosePesticide() {
    printf("Add to cart (back): ");
    char userAns[20];
    scanf("%s", userAns);
    toLower(userAns);
    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    if (back) {
        showAllMedicine();
    } else if (cart) {
        showAllCartItems();
    } else {
        char productName[100];
        int productPrice;

        int startInd = (int)'a';
        int endInd = (int)'f';
        int userInd = (int)userAns[0];


        if (userInd<=endInd && strlen(userAns) ==1) {

            strcpy(productName, allPesticides[userInd - startInd].name);
            productPrice = allPesticides[userInd - startInd].price;


            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            choosePesticide();
        } else {
            printf("Item not found!\n");
            choosePesticide();
        }
    }
}