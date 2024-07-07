
#include "Nut.h"
#include"string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_Seeds/all seeds.h"
#include"../../../Cart/Add to cart/cart.h"

static nuts allNuts[6];
void showAllNut(){



    strcpy(allNuts[0].name, "Almond");
    allNuts[0].price = 1200;

    strcpy(allNuts[1].name, "Cashew");
    allNuts[1].price = 1499;

    strcpy(allNuts[2].name, "Pistachio");
    allNuts[2].price = 999;

    strcpy(allNuts[3].name, "Peanut");
    allNuts[3].price = 600;

    strcpy(allNuts[4].name, "Cacao_bob");
    allNuts[4].price = 4000;

    strcpy(allNuts[5].name, "Macadamia");
    allNuts[5].price = 1199;


    // show all nuts

    printf("************ Nut ***********\n");

    for(int i =0; i< 6; i++){

        printf("        %c.%s(%dtk)  ",'A'+i,allNuts[i].name, allNuts[i].price);
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

    toLower(userAns);
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



        int startInd = (int)'a';
        int endInd  = (int)'f';
        int userChossenInd = (int)userAns[0];
        int productInd = userChossenInd-startInd;

        if (endInd>=userChossenInd && strlen(userAns) ==1) {
            strcpy(productname,allNuts[productInd].name);

            productPrice = allNuts[productInd].price;

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
