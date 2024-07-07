#include <stdio.h>
#include "category.h"
#include "string.h"
#include "../../Home/home.h"
#include"../Seeds/Paddy Seeds/paddy.h"
#include "../Seeds/All_Seeds/all seeds.h"
#include "../Machinery/All_machine/all_mechine.h"
#include "../Medicine/All_Medicine/All_medicine.h"

void displayAllCategory(){

    char categories[][100] = {"Seeds", "Livestock", "Fisheries", "Agrochemicals", "Machinery"};

    int getSize = sizeof(categories)/ sizeof(categories[0]);
    printf("************** Categories **************\n");
    for(int i = 0; i< getSize; i++){

        printf("         %d. %s\n",i+1, categories[i] );

    }

    chooseCategory();// from-> this;


}
void chooseCategory(){

    char userAns[100];
    printf("Select Category/back: ");
    scanf("%s", userAns);
    toLower(userAns);// keep lower


    int seed = !strcmp(userAns, "seeds");
    int liverStock = !strcmp(userAns, "livestock");
    int fisheries = !strcmp(userAns, "fisheries");
    int agrochemical = !strcmp(userAns, "agrochemicals");
    int machine = !strcmp(userAns, "machinery");
    int back = !strcmp(userAns, "back");

    if(back){

        displayHeader();// from-> Home/home.c
    }else if(seed){

        showAllTypeOfSeeds();// from-> seeds/all_seeds/all seeds.c

    }else if(liverStock){
        printf("all livestock\n");
    }else if(agrochemical){

        showAllMedicine();// from-> medicine/All_medicine/All_medicine.c
    }else if(fisheries){

        printf("fisheries\n");

    }else if(machine){

        showAllTypesOfMachine();//from->Machinery/All_machine


    }else{

        printf("enter valid category!\n\n");
        chooseCategory();// call itself

    }





}