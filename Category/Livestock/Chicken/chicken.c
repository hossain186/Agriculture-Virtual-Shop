
#include "chicken.h"
#include <string.h>
#include <stdio.h>
#include"../../../Cart/Add to cart/cart.h"
#include"../../../Home/home.h"
#include "../All_Livestcok/all_Livestock.h"


Chicken allChickens[6];

void showAllChicken() {
    // Initialize Chicken Products
    strcpy(allChickens[0].name, "Broiler");
    allChickens[0].price = 220;

    strcpy(allChickens[1].name, "Layer");
    allChickens[1].price = 200;

    strcpy(allChickens[2].name, "Free Range");
    allChickens[2].price = 250;

    strcpy(allChickens[3].name, "Cornish");
    allChickens[3].price = 300;

    strcpy(allChickens[4].name, "Leghorn");
    allChickens[4].price = 270;

    strcpy(allChickens[5].name, "Rhode_Island_Red");
    allChickens[5].price = 350;

    printf("********* Chicken Products *********\n");

    for (int i = 0; i < 6; i++) {
        printf("        %c.%s(%dtk)  ", 'A' + i, allChickens[i].name, allChickens[i].price);
        if (i == 2) {
            printf("\n");
        }
    }

    printf("\n");
    chooseChicken();
}

void chooseChicken() {
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

        if (userChosenInd <= endInd && strlen(userAns) ==1) {
            strcpy(productname, allChickens[productInd].name);
            productPrice = allChickens[productInd].price;

            int added = addItemToCart(productname, productPrice);
            if (added) {
                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full! Delete items or proceed to checkout.\n");
            }
            chooseChicken();
        } else {
            printf("Item not found!\n");
            chooseChicken();
        }
    }
}