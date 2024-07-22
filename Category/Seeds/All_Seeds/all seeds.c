
#include "all seeds.h"
#include "stdio.h"
#include "string.h"
#include "../../../Home/home.h"
#include "../Paddy Seeds/paddy.h"
#include "../../All_category/category.h"
#include"../Nut/Nut.h"
#include "../Legume/legume.h"


void showAllTypeOfSeeds(){

    char typeOfseeds[][100] = {"Paddy", "Nut","Legume"};

    int n = sizeof(typeOfseeds)/ sizeof (typeOfseeds[0]);

    printf("************** Seeds **************\n");
    for(int i =0; i< n;i++){

        printf("        %c. %s\n", 'A'+i, typeOfseeds[i]);

    }

    chooseTypeOfseed();// from->this


}


void chooseTypeOfseed(){

    char seedName[50];
    printf("Choose seed/back: ");
    scanf("%s", seedName);

    toLower(seedName);// from->Home/home.c

    int userInd = (int)seedName[0] - (int )'a';

    int back = !strcmp(seedName, "back");
    int paddy = userInd ==0;
    int Nut = userInd == 1;
    int legume = userInd ==2;

    if(back){

        displayAllCategory();// from-> All_category/category.c

    }else if(paddy && strlen(seedName) ==1){

        showAllPaddy();// from->Paddy seeds/ paddy.c



    }else if(Nut && strlen(seedName) ==1){

        showAllNut();// from -> Seeds/Nut/ nut.c

    }else if (legume && strlen(seedName) ==1){
        showAllLegume();

    }

    else{

        printf("enter Valid seed!\n");
        chooseTypeOfseed();// call itself



    }




}