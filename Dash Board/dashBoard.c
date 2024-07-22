

#include "dashBoard.h"
#include <stdio.h>
#include <string.h>
#include "../Home/home.h"


void showDashBoard(){

    printf("***************** Dash Board *******************\n");

    char userAns[10];
    printf("Enter back: ");
    scanf("%s", userAns);

    int back = !strcmp(userAns, "back");

    if(back){
        Go_back();

    }


}

void Go_back(){
    displayHeader();


}