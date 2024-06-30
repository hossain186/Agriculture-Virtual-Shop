
#include "paddy.h"
#include <stdlib.h>
#include<stdio.h>
#include "string.h"
#include "../All_Seeds/all seeds.h"


void showAllPaddy(){

    // list of all types paddy
    seeds paddy[6];

    strcpy(paddy[0].name,"BR1");
    paddy[0].price = 499;

    strcpy(paddy[1].name,"BR2");
    paddy[1].price = 399;

    strcpy(paddy[2].name,"BR3");
    paddy[2].price = 468;

    strcpy(paddy[3].name,"BR4");
    paddy[3].price = 599;

    strcpy(paddy[4].name,"BR5");
    paddy[4].price = 293;

    strcpy(paddy[5].name,"BR6");
    paddy[5].price = 999;


    printf("********* Products *********\n");

    for(int i =0; i< 6; i++){

        printf("        %s(%dtk)  ",paddy[i].name, paddy[i].price);
        if(i ==2){

            printf("\n");
        }


    }

    printf("\n");

    printf("Select product or type (back) to go previous page: ");
    char userAns[15];
    scanf("%s", userAns);

    int back = !strcmp(userAns,"back");

    if(back){

        goBack();// from->this


    }else{

        printf("noting will do yet\n");
    }

}

void choosePaddy(){

}

void goBack(){

    showAllTypeOfSeeds();// from-> All_Seeds

}



