#include <stdio.h>
#include "Pesticides.h"
#include "string.h"
#include "../../../Home/home.h"
#include "../All_Medicine/All_medicine.h"


void showAllPesticides(){

    char allPesticides[][100] = {"Ripcord Insecticide(10 EC – Cypermethrin)",

                                 "Nitro Insecticide 505 EC (Chlorpyrifos + Cypermethrin)",
                                 "Fighter 2.5 EC – Lambda Cyhalothrin ",

                                 "Neem Oil for Plants",

                                 "Imitaf 20 SL (Imidacloprid)",

                                 "Neem Cake Powder",

                                 "Imitaf 20 SL (Imidacloprid)"
                  };

    printf("******* All Pesticides *******\n");
    for(int i =0; i< 6;i++){

        printf("%d. % s\n", i+1, allPesticides[i]);
    }

    printf("\n");

    choosePesticides();// from-> this


}
void choosePesticides(){

    printf("Select type of Pesticides/back: ");
    char userAns[50];
    scanf("%s", userAns);
    toLower(userAns);// from-> Home/home.c

    int back = !strcmp(userAns, "back");

    if(back){

        showAllMedicine();// Category/All_category/category.c

    }else{
        printf("Enter valid type of medicine!\n");
        chooseMedicine();//
    }

}