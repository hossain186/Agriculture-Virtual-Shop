
#include "cow.h"
#include <string.h>
#include <stdio.h>
#include "../../../Cart/Add to cart/cart.h"
#include "../../../Home/home.h"
#include "../All_Livestcok/all_Livestock.h"

Cow allCows[6];

void showAllCow() {
    // Initialize Cow Products
    strcpy(allCows[0].name, "Holstein");
    allCows[0].price = 1500;

    strcpy(allCows[1].name, "Jersey");
    allCows[1].price = 1800;

    strcpy(allCows[2].name, "Guernsey");
    allCows[2].price = 2000;

    strcpy(allCows[3].name, "Ayrshire");
    allCows[3].price = 2200;

    strcpy(allCows[4].name, "Brown Swiss");
    allCows[4].price = 2500;

    strcpy(allCows[5].name, "Angus");
    allCows[5].price = 3000;

    printf("********* Cow Products *********\n");

    for (int i = 0; i < 6; i++) {
        printf("        %c.%s(%dtk)  ", 'A' + i, allCows[i].name, allCows[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    chooseCow();
}

void chooseCow() {
    printf("Add to cart(back): ");
    char userAns[20];
    scanf("%s", userAns);
    toLower(userAns);

    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    if (back) {
        showAllTypesOfLivestock(); // from->this
    } else if (cart) {
        showAllCartItems(); // from-> Cart/add_to_cart
    } else {
        char productname[100];
        int productPrice;

        int startInd = (int) 'a';
        int endInd = (int) 'f';
        int userChosenInd = (int) userAns[0];
        int productInd = userChosenInd - startInd;

        if (userChosenInd <= endInd && strlen(userAns) == 1) {
            strcpy(productname, allCows[productInd].name);
            productPrice = allCows[productInd].price;

            int added = addItemToCart(productname, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseCow();
        } else {
            printf("Item not found!\n");
            chooseCow();
        }
    }
}


