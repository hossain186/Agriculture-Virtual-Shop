#include<stdio.h>
#include "all_mechine.h"
#include "../../../Home/home.h"
#include "string.h"
#include"../../All_category/category.h"
#include"../Tractor/tractor.h"
#include"../Water_Pump/waterPamp.h"
#include"../Power_Tiller/powerTiller.h"

void showAllTypesOfMachine(){

     char machineTypes[][50] = {
            "Tractors",
            "Power Tiller",
            "Water Pump"
    };

    printf("********* Machinery *********\n");

    int n = sizeof (machineTypes)/sizeof(machineTypes[0]);
    for(int i =0; i< n;i++){

        printf("         %c. %s\n",'A'+i, machineTypes[i]);
    }

    chooseMachine();// from-> this

}


void chooseMachine(){

    printf("Select machine/back: ");
    char userAns[100];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/ home.c

    int back = !strcmp(userAns,"back");// if user wanna go back


    int tracktor = (int)userAns[0]-(int )'a';
    int PowerTiller = (int)userAns[0]-(int )'a';
    int WaterPamp = (int)userAns[0]-(int )'a';

    if(back){
        displayAllCategory();// from -> Category/All_category/category.c

    }else if(tracktor == 0 && strlen(userAns)== 1 ){

        showAllTractor();// from-> Machinery/tractor/tractor.c

    }else if(PowerTiller == 1 && strlen(userAns) ==1){

        showAllPowerTiller();

    }else if (WaterPamp ==2 && strlen(userAns) ==1){
        showAllWaterPump();

    }
    else{

        printf("Enter valid machine type!\n");
        chooseMachine();
    }


}

