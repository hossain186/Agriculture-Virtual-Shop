
#include "all_Livestock.h"
#include <stdio.h>
#include "../../../Home/home.h"
#include <string.h>
#include"../../All_category/category.h"
#include "../Chicken/chicken.h"
#include "../Cow/cow.h"
#include "../Goat/goat.h"
void showAllTypesOfLivestock() {
    char livestockTypes[][50] = {
            "Chicken",
            "Cow",
            "Goat"
    };

    printf("********* Livestock Products *********\n");

    int n = sizeof(livestockTypes) / sizeof(livestockTypes[0]);
    for (int i = 0; i < n; i++) {
        printf("         %c. %s\n", 'A' + i, livestockTypes[i]);
    }

    printf("\n");

    chooseLivestock();

}


void chooseLivestock(){

    printf("Select Livestock/back: ");
    char userAns[100];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/ home.c

    int back = !strcmp(userAns,"back");// if user wanna go back


    int Chicken = (int)userAns[0]-(int )'a';
    int Cow = (int)userAns[0]-(int )'a';
    int Goat = (int)userAns[0]-(int )'a';

    if(back){
        displayAllCategory();// from -> Category/All_category/category.c

    }else if(Chicken == 0 && strlen(userAns)== 1 ){

        showAllChicken();


    }else if(Cow == 1 && strlen(userAns) ==1){

        showAllCow();

    }else if (Goat ==2 && strlen(userAns) ==1){
        showAllGoat();

    }
    else{

        printf("Enter valid machine type!\n");
        chooseLivestock();
    }


}


