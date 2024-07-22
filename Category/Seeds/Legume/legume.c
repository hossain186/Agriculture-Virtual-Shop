
#include "legume.h"
#include <string.h>
#include <stdio.h>
#include "../All_Seeds/all seeds.h"
#include "../../../Cart/Add to cart/cart.h"
#include"../../../Home/home.h"

static Legume allLegume[20];
void showAllLegume(){


    // show all nuts

    printf("************ Nut ***********\n");

    Legume legume;

    FILE *readAllLegume = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Category/Seeds/Legume/legume.txt", "r");
    int i =0, totalProduct = 0;

    while(fread(&legume, sizeof (Legume), 1,readAllLegume)){

        printf("        %c.%s(%dtk)  ",'A'+i,legume.name, legume.price);

        strcpy(allLegume[totalProduct].name, legume.name);
        allLegume[totalProduct].price = legume.price;
        totalProduct++;

        if(i ==2){

            printf("\n");
        }
        i++;

    }

    fclose(readAllLegume);

    printf("\n");

    chooseLegume(totalProduct);// form-> this




}


void chooseLegume(int totalProduct){

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
        int endInd  = totalProduct;
        int userChossenInd = (int)userAns[0];
        int productInd = userChossenInd-startInd;

        if (endInd>=(userChossenInd -'a') && strlen(userAns) ==1) {
            strcpy(productname, allLegume[productInd].name);
            productPrice = allLegume[productInd].price;
            int added = addItemToCart(productname, productPrice);
            if (added) {

                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full!.Delete checkout or delete few item.\n");
            }
            chooseLegume(totalProduct);

        }
        else{

            printf("Item not found!");
            chooseLegume(totalProduct);

        }
    }



}


void addlegume(){

    FILE *AppendLegume = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Category/Seeds/Legume/legume.txt", "a");

    Legume  legume;

    for(int i = 0; i< 6; i++){

        strcpy(legume.name, allLegume[i].name);
        legume.price = allLegume[i].price;

        fwrite(&legume, sizeof(Legume), 1, AppendLegume);

    }

    fclose(AppendLegume);



}











/*
    strcpy(allLegume[0].name, "Cannellini");
    allLegume[0].price = 120;

    strcpy(allLegume[1].name, "Chickpeas");
    allLegume[1].price = 210;

    strcpy(allLegume[2].name, "Red_Bean");
    allLegume[2].price = 300;

    strcpy(allLegume[3].name, "Pinto");
    allLegume[3].price = 499;

    strcpy(allLegume[4].name, "Soybean");
    allLegume[4].price = 125;

    strcpy(allLegume[5].name, "Borlotti");
    allLegume[5].price = 321;
    */



