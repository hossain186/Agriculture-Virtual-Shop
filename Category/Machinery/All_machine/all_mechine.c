#include<stdio.h>
#include "all_mechine.h"
#include "../../../Home/home.h"
#include "string.h"
#include"../../All_category/category.h"
#include"../Tractor/tractor.h"


void showAllTypesOfMachine(){

    const char machineTypes[][50] = {
            "Tractors",
            "Power Tiller",
            "Water Pump"
    };

    printf("********* Machinery *********\n");

    int n = sizeof (machineTypes)/sizeof(machineTypes[0]);
    for(int i =0; i< n;i++){

        printf("%d. %s\n",i+1, machineTypes[i]);
    }

    chooseMachine();

}


void chooseMachine(){

    printf("Select machine/back: ");
    char userAns[100];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/ home.c

    int back = !strcmp(userAns,"back");
    int tracktor = !strcmp(userAns,"tractors");

    if(back){
        displayAllCategory();// from -> Category/All_category/category.c

    }else if(tracktor){

        showAllTractor();// from-> Machinery/tractor/tractor.c

    }
    else{

        printf("Enter valid machine type!\n");
        chooseMachine();
    }


}

