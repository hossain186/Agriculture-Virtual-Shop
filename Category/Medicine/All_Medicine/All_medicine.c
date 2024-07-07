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
#include"../Growth_Regulator/growth.h"

void showAllMedicine(){

    char allMedicine[3][100] ={"Pesticides","Fertilizers", "Growth Regulators"};

    printf("******* ALL Medicine *******\n");

    for(int i =0; i< 3; i++){

        printf(" %c. %s\n",'A'+i,allMedicine[i] );

    }
    printf("\n");

    chooseMedicine();// from->this;

}

void chooseMedicine(){

    printf("Select type of medicine/back: ");
    char userAns[50];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/home.c

    int userInd = (int)userAns[0] - (int )'a';



    int back = !strcmp(userAns, "back");
    int Pesticides = 0;
    int fertilizer = 0;
    int growthRegulators = 0;

    if(userInd == 0){
        Pesticides = 1;
    }else if (userInd == 1){
        fertilizer = 1;
    }else if (userInd == 2){
        growthRegulators = 1;
    }

    if(back){

        displayAllCategory();// Category/All_category/category.c

    }else if(Pesticides && strlen(userAns) ==1){

        showAllPesticides();// from medicine/Pesticides/pesticides.c

    }else if(fertilizer && strlen(userAns) ==1) {
        showALlFertilizer();

    }else if(growthRegulators && strlen(userAns) ==1) {
        showAllGrowthRegulators();

    }
    else{
            printf("Enter valid type of medicine!\n");
            chooseMedicine();
    }
}



