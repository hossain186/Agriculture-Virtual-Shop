
#include "Nut.h"
#include"string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_Seeds/all seeds.h"


void showAllNut(){

    nuts allNuts[6];

    strcpy(allNuts[0].name, "Almond");
    allNuts[0].price = 1200;

    strcpy(allNuts[1].name, "Cashew");
    allNuts[1].price = 1499;

    strcpy(allNuts[2].name, "Pistachio");
    allNuts[2].price = 999;

    strcpy(allNuts[3].name, "Peanut");
    allNuts[3].price = 600;

    strcpy(allNuts[4].name, "Cacao bob");
    allNuts[4].price = 4000;

    strcpy(allNuts[5].name, "Macadamia");
    allNuts[5].price = 1199;


    // show all nuts

    printf("************ Nut ***********\n");

    for(int i =0; i< 6; i++){

        printf("        %s(%dtk)  ",allNuts[i].name, allNuts[i].price);
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
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/home.c

    int back = !strcmp(userAns, "back");

    if(back){
        showAllTypeOfSeeds();
    }else{
        printf("Enter valid nut name!\n");
        chooseNut();
    }







}
void goBack();
