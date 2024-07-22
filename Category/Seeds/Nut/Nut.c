
#include "Nut.h"
#include"string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_Seeds/all seeds.h"
#include"../../../Cart/Add to cart/cart.h"



static nuts allNuts[20];

void showAllNut(){

    nuts Nut;

    FILE *readAllNuts = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Category/Seeds/Nut/nut.txt", "r");
    int i =0, totalProduct = 0;

    while(fread(&Nut, sizeof (nuts), 1,readAllNuts)){

        printf("        %c.%s(%dtk)  ",'A'+i,Nut.name, Nut.price);

        strcpy(allNuts[totalProduct].name, Nut.name);
        allNuts[totalProduct].price = Nut.price;
        totalProduct++;

        if(i ==2){

            printf("\n");
        }
        i++;

    }




    printf("\n");
    // user status
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    char loginStatus[10];
    char userGmail[50];
    char adminStatus[10];
    fscanf(loginStatusFile, "%s", loginStatus);
    fscanf(loginStatusFile, "%s", userGmail);
    fscanf(loginStatusFile, "%s", adminStatus);
    fclose(loginStatusFile);

    int isAdmin = !strcmp(adminStatus, "yes");

    if(isAdmin){
        nextCommand();
    }else {
        chooseNut(totalProduct);// form-> this
    }


}


void chooseNut(int totalProduct ){

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

        if (endInd>= (userChossenInd-'a') && strlen(userAns) ==1 ) {
            strcpy(productname,allNuts[productInd].name);

            productPrice = allNuts[productInd].price;

            int added = addItemToCart(productname, productPrice);
            if (added) {

                printf("Added item successfully.\n");
            } else {
                printf("Your cart is full!.Delete checkout or delete few item.\n");
            }
            chooseNut(totalProduct);


        }
        else{

            printf("Item not found!\n");
            chooseNut(totalProduct);

        }
    }



}


void addNut(){

    FILE *NUT = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Category/Seeds/Nut/nut.txt", "a");
    nuts  Nut;

    char nutName[50];
    int nutPrice;

    printf("Enter Nut name : ");
    scanf("%s", nutName);

    printf("Enter Nut price : ");
    scanf("%d", &nutPrice);

    strcpy(Nut.name, nutName);
    Nut.price = nutPrice;

    fwrite(&Nut, sizeof(nuts), 1, NUT);

    fclose(NUT);



}

void nextCommand(){

    printf("Enter add or back: ");

    char userAns[10];
    scanf("%s", userAns);

    int add = !strcmp(userAns, "add");
    int back = !strcmp(userAns, "back");

    if(add){

        addNut();
        nextCommand();
    }else if(back){

        showAllTypeOfSeeds();

    }else{

        printf("enter valid command\n");
        nextCommand();
    }



}

