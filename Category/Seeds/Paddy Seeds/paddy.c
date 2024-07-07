
#include "paddy.h"
#include<stdio.h>
#include "string.h"
#include "../All_Seeds/all seeds.h"
#include"../../../Cart/Add to cart/cart.h"
#include"../../../Home/home.h"

seeds paddy[6];
void showAllPaddy(){

    // list of all types paddy

    strcpy(paddy[0].name,"BR1");
    paddy[0].price = 499;

    strcpy(paddy[1].name,"BR2");
    paddy[1].price = 399;

    strcpy(paddy[2].name,"BR3");
    paddy[2].price = 468;

    strcpy(paddy[3].name,"BR4");
    paddy[3].price = 599;

    strcpy(paddy[4].name,"BR5");
    paddy[4].price = 293;

    strcpy(paddy[5].name,"BR6");
    paddy[5].price = 999;


    printf("********* Products *********\n");

    for(int i =0; i< 6; i++){

        printf("        %c.%s(%dtk)  ",'A'+i,paddy[i].name, paddy[i].price);
        if(i == 2){

            printf("\n");
        }


    }

    printf("\n");

    choosePaddy();
}

void choosePaddy() {

    printf("Add to cart(back): ");
    char userAns[20];
    scanf("%s", userAns);
    toLower(userAns);

    int back = !strcmp(userAns, "back");
    int cart = !strcmp(userAns, "cart");

    // Added code from here

    if (back) {

        goBack();// from->this


    } else if (cart) {
        showAllCartItems();//from-> Cast/add to cart
    } else {

        char productname[20];
        int productPrice;



        int startInd = (int)'a';
        int endInd  = (int)'f';
        int userChossenInd = (int)userAns[0];
        int productInd = userChossenInd-startInd;

        if (userChossenInd<=endInd && strlen(userAns) ==1) {

            strcpy(productname, paddy[productInd].name);
            productPrice = paddy[productInd].price;

            int added = addItemToCart(productname, productPrice);
            if (added) {

                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full!.Delete checkout or delete few item.\n");
            }
            choosePaddy();


        }
        else{

            printf("Item not found!");
            choosePaddy();

        }
    }
}




void goBack(){

    showAllTypeOfSeeds();// from-> All_Seeds

}



