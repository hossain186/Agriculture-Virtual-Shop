//
// Created by hossain on 7/7/24.
//

#include "goat.h"
#include <string.h>
#include <stdio.h>
#include "../../../Cart/Add to cart/cart.h"
#include "../../../Home/home.h"
#include "../All_Livestcok/all_Livestock.h"

Goat allGoats[6];

void showAllGoat() {
    // Initialize Goat Products
    strcpy(allGoats[0].name, "Boer");
    allGoats[0].price = 1200;

    strcpy(allGoats[1].name, "Nubian");
    allGoats[1].price = 1400;

    strcpy(allGoats[2].name, "Saanen");
    allGoats[2].price = 1600;

    strcpy(allGoats[3].name, "Kiko");
    allGoats[3].price = 1800;

    strcpy(allGoats[4].name, "Alpine");
    allGoats[4].price = 2000;

    strcpy(allGoats[5].name, "LaMancha");
    allGoats[5].price = 2200;

    printf("********* Goat Products *********\n");

    for (int i = 0; i < 6; i++) {
        printf("        %c.%s(%dtk)  ", 'A' + i, allGoats[i].name, allGoats[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    chooseGoat();
}

void chooseGoat() {
    printf("Add to cart(back): ");
    char userAns[20];
    scanf("%s", userAns);
    toLower(userAns);

    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    // Added code from here
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
            strcpy(productname, allGoats[productInd].name);
            productPrice = allGoats[productInd].price;

            int added = addItemToCart(productname, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseGoat();
        } else {
            printf("Item not found!\n");
            chooseGoat();
        }
    }
}
