

#include "growth.h"
#include <stdio.h>
#include <string.h>
#include "../../../Cart/Add to cart/cart.h"
#include "../All_Medicine/All_medicine.h"
#include"../../../Home/home.h"

GrowthRegulator allGrowthRegulators[6];

void showAllGrowthRegulators() {
    // Initialize growth regulators
    strcpy(allGrowthRegulators[0].name, "Gibberellic_Acid_(GA)");
    allGrowthRegulators[0].price = 1500;
    strcpy(allGrowthRegulators[1].name, "Cytokinin_(CK)");
    allGrowthRegulators[1].price = 2000;
    strcpy(allGrowthRegulators[2].name, "Auxin_(IAA)");
    allGrowthRegulators[2].price = 1800;
    strcpy(allGrowthRegulators[3].name, "Ethylene");
    allGrowthRegulators[3].price = 2200;
    strcpy(allGrowthRegulators[4].name, "Abscisic_Acid_(ABA)");
    allGrowthRegulators[4].price = 2500;
    strcpy(allGrowthRegulators[5].name, "Brassinosteroids");
    allGrowthRegulators[5].price = 3000;

    printf("********* Growth Regulators *********\n");
    for (int i = 0; i < 6; i++) {
        printf("      %c. %s(%dtk)\n", 'A' + i, allGrowthRegulators[i].name, allGrowthRegulators[i].price);
        if ((i + 1) % 3 == 0 && i != 5) {
            printf("\n");
        }
    }
    printf("\n");

    chooseGrowthRegulator();
}

// Function to allow user to choose a growth regulator or go back
void chooseGrowthRegulator() {
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



        if (endInd>=userInd && strlen(userAns) ==1) {

            strcpy(productName, allGrowthRegulators[userInd - startInd].name);
            productPrice = allGrowthRegulators[userInd - startInd].price;

            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseGrowthRegulator();
        } else {
            printf("Item not found!\n");
            chooseGrowthRegulator();
        }
    }
}