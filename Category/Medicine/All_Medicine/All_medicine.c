//
// Created by hossain on 6/30/24.
//

#include "All_medicine.h"
#include <stdio.h>
#include "string.h"
#include"../../../Home/home.h"
#include "../../All_category/category.h"
#include "../Pesticides/Pesticides.h"
#include "../Fertilizers/fertilizer.h"

void showAllMedicine(){

    char allMedicine[3][100] ={"Pesticides","Fertilizers", "Growth Regulators"};

    printf("******* ALL Medicine *******\n");

    for(int i =0; i< 3; i++){

        printf("  %s\n",allMedicine[i] );

    }
    printf("\n");

    chooseMedicine();// from->this;

}

void chooseMedicine(){

    printf("Select type of medicine/back: ");
    char userAns[50];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/home.c

    int back = !strcmp(userAns, "back");
    int Pesticides = !strcmp(userAns, "pesticides");
    int fertilizer = !strcmp(userAns, "fertilizers");

    if(back){

        displayAllCategory();// Category/All_category/category.c

    }else if(Pesticides){

        showAllPesticides();// from medicine/Pesticides/pesticides.c

    }else if(fertilizer) {
        showALlFertilizer();
    }else{
            printf("Enter valid type of medicine!\n");
            chooseMedicine();
    }
}



