#include <stdio.h>
#include "category.h"
#include "string.h"
#include "../../Home/home.h"
#include"../Seeds/Paddy Seeds/paddy.h"
#include "../Seeds/All_Seeds/all seeds.h"
#include "../Machinery/All_machine/all_mechine.h"
#include "../Medicine/All_Medicine/All_medicine.h"
#include"../Livestock/All_Livestcok/all_Livestock.h"

void displayAllCategory(){

    char categories[][100] = {"Seeds", "Livestock", "Fisheries", "Agrochemicals", "Machinery"};

    int getSize = sizeof(categories)/ sizeof(categories[0]);
    printf("************** Categories **************\n");
    for(int i = 0; i< getSize; i++){

        printf("         %C. %s\n",'A'+i, categories[i] );

    }

    chooseCategory();// from-> this;


}
void chooseCategory(){

    char userAns[100];
    printf("Select Category/back: ");
    scanf("%s", userAns);
    toLower(userAns);// keep lower

    int userInd = (int)userAns[0] - (int)'a';

    int seed = userInd ==0;
    int liverStock = userInd ==1;
    int fisheries = userInd ==2;
    int agrochemical = userInd ==3;
    int machine = userInd == 4;
    int back = userInd == 5;

    if(back){

        displayHeader();// from-> Home/home.c
    }else if(seed && strlen(userAns) ==1){

        showAllTypeOfSeeds();// from-> seeds/all_seeds/all seeds.c

    }else if(liverStock && strlen(userAns) ==1){
        showAllTypesOfLivestock();
    }else if(agrochemical && strlen(userAns) ==1){

        showAllMedicine();// from-> medicine/All_medicine/All_medicine.c
    }else if(fisheries && strlen(userAns) ==1){

        printf("fisheries\n");

    }else if(machine && strlen(userAns) ==1){

        showAllTypesOfMachine();//from->Machinery/All_machine


    }else{

        printf("enter valid category!\n\n");
        chooseCategory();// call itself

    }





}