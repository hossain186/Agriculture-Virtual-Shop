

#include "fertilizer.h"
#include <string.h>
#include <stdio.h>
#include"../../../Cart/Add to cart/cart.h"
#include "../All_Medicine/All_medicine.h"



Fertilizer  allFertilizers[6];
void showALlFertilizer() {
    // Initialize fertilizers
    strcpy(allFertilizers[0].name, "Urea");
    allFertilizers[0].price = 1200;
    strcpy(allFertilizers[1].name, "Diammonium phosphate (DAP)");
    allFertilizers[1].price = 1499;
    strcpy(allFertilizers[2].name, "Potassium chloride");
    allFertilizers[2].price = 999;
    strcpy(allFertilizers[3].name, "Ammonium nitrate");
    allFertilizers[3].price = 600;
    strcpy(allFertilizers[4].name, "Superphosphate");
    allFertilizers[4].price = 4000;
    strcpy(allFertilizers[5].name, "Calcium ammonium nitrate (CAN)");
    allFertilizers[5].price = 1199;

    printf("********* Fertilizers *********\n");
    for (int i = 0; i < 6; i++) {
        printf("%d. %s(%dtk)\n", i + 1, allFertilizers[i].name, allFertilizers[i].price);
        if ((i + 1) % 3 == 0 && i != 5) {
            printf("\n");
        }
    }
    printf("\n");

    chooseFertilizer();
}


// Function to allow user to choose a fertilizer or go back
void chooseFertilizer() {
    printf("Add to cart (back): ");
    char userAns[20];
    scanf("%s", userAns);

    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    if (back) {
        showAllMedicine();
    } else if (cart) {
        showAllCartItems();
    } else {
        char productName[100];
        int productPrice;
        int foundItem = 0;

        for (int i = 0; i < 6; i++) {
            if (!strcmp(allFertilizers[i].name, userAns)) {
                productPrice = allFertilizers[i].price;
                strcpy(productName, allFertilizers[i].name);
                foundItem = 1;
                break;
            }
        }

        if (foundItem) {
            int added = addItemToCart(productName, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseFertilizer();
        } else {
            printf("Item not found!\n");
            chooseFertilizer();
        }
    }
}
