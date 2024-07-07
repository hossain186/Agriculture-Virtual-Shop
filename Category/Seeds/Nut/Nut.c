
#include "Nut.h"
#include"string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_Seeds/all seeds.h"
#include"../../../Cart/Add to cart/cart.h"

static nuts allLegume[6];
void showAllNut(){



    strcpy(allLegume[0].name, "Almond");
    allLegume[0].price = 1200;

    strcpy(allLegume[1].name, "Cashew");
    allLegume[1].price = 1499;

    strcpy(allLegume[2].name, "Pistachio");
    allLegume[2].price = 999;

    strcpy(allLegume[3].name, "Peanut");
    allLegume[3].price = 600;

    strcpy(allLegume[4].name, "Cacao_bob");
    allLegume[4].price = 4000;

    strcpy(allLegume[5].name, "Macadamia");
    allLegume[5].price = 1199;


    // show all nuts

    printf("************ Nut ***********\n");

    for(int i =0; i< 6; i++){

        printf("        %s(%dtk)  ", allLegume[i].name, allLegume[i].price);
        if(i ==2){

            printf("\n");
        }


    }

    printf("\n");

    chooseNut();// form-> this




}


void chooseNut(){

    printf("Select product/back: ");
    char userAns[100];
    scanf("%s",userAns);

    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    // Added code from here

    if (back) {

        showAllTypeOfSeeds();// from->this


    } else if (cart) {
        showAllCartItems();//from-> Cast/add to cart
    } else {

        char productname[20];
        int productPrice;

        int findItem = 0;

        for(int i = 0; i< 6; i++){

            int cmp = !strcmp(allLegume[i].name, userAns);

            if(cmp){
                productPrice = allLegume[i].price;
                strcpy(productname, allLegume[i].name);

                findItem = 1;
                break;

            }

        }

        if (findItem) {

            int added = addItemToCart(productname, productPrice);
            if (added) {

                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full!.Delete checkout or delete few item.\n");
            }
            chooseNut();


        }
        else{

            printf("Item not found!");
            chooseNut();

        }
    }



}
