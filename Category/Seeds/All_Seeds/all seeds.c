

#include "all seeds.h"
#include "stdio.h"
#include "string.h"
#include "../../../Home/home.h"
#include "../Paddy Seeds/paddy.h"
#include "../../All_category/category.h"

#include"../Nut/Nut.h"


void showAllTypeOfSeeds(){

    char typeOfseeds[][100] = {"Paddy", "Nut","Legume"};

    int n = sizeof(typeOfseeds)/ sizeof (typeOfseeds[0]);

    printf("************** Seeds **************\n");
    for(int i =0; i< n;i++){

        printf("        %d. %s\n", i+1, typeOfseeds[i]);

    }

    chooseTypeOfseed();// from->this


}


void chooseTypeOfseed(){

    char seedName[50];
    printf("Choose seed/back: ");
    scanf("%s", seedName);

    toLower(seedName);// from->Home/home.c

    int back = !strcmp(seedName, "back");
    int paddy = !strcmp(seedName, "paddy");
    int Nut = !strcmp(seedName, "nut");
    int legume = !strcmp(seedName, "legume");

    if(back){

        displayAllCategory();// from-> All_category/category

    }else if(paddy){

        showAllPaddy();// from->paddy seeds/ paddy.c



    }else if(Nut){

        showAllNut();// from -> Seeds/Nut/ nut.c

    }else{

        printf("enter Valid seed!\n");
        chooseTypeOfseed();// call itself



    }




}