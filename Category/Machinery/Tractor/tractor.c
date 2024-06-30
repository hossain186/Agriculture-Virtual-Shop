
#include "tractor.h"
#include "string.h"
#include<stdio.h>
#include "../../../Home/home.h"
#include "../All_machine/all_mechine.h"





void showAllTractor(){

    char tractorModel[6][100] = {"Supreme DI 60 RX","Sonalika All Rounder 55", "Supreme DI 50 RX",
        "Supreme DI 48 RX ", "Supreme DI 47 RX ","Supreme DI 45 RX "
    };

    printf("********* ALL Tractor *********\n");

    for(int i =0; i< 6; i++){
        printf("%d.%s  ", i+1, tractorModel[i]);
        if(i==2){
            printf("\n");
        }
    }
    printf("\n");

    chooseTractor();// from->this

}
void chooseTractor(){

    printf("Select Tractor/back: ");
    char userAns[100];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/ home.c

    int back = !strcmp(userAns,"back");

    if(back){
        showAllTypesOfMachine(); //from-> machinery/all_mechine/ all_machine.c

    }else{

        printf("Enter valid  tractor model!\n");
        chooseTractor();
    }



}

