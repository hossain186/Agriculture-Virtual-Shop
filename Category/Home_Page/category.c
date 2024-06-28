#include <stdio.h>
#include "category.h"
#include "string.h"
#include "../../Home/home.h"
#include"../Seeds/Paddy Seeds/paddy.h"

void displayAllCategory(){

    char categories[][100] = {"Seeds", "Livestock", "Fisheries", "Agrochemicals", "Equipment"};

    int getSize = sizeof(categories)/ sizeof(categories[0]);

    for(int i = 0; i< getSize; i++){

        printf("%d. %s\n",i+1, categories[i] );


    }


}
void chooseCategory(){

    char userAns[100];
    printf("Select Category: ");
    scanf("%s", userAns);
    toLower(userAns);// keep lower

    int seed = !strcmp(userAns, "seeds");
    int liverStock = !strcmp(userAns, "livestock");
    int fisheries = !strcmp(userAns, "fisheries");
    int agrochemical = !strcmp(userAns, "agrochemicals");
    int equipment = !strcmp(userAns, "equipment");

    if(seed){

        printf("seeds");

    }else if(liverStock){
        printf("all livestock\n");
    }else if(agrochemical){

        printf("all agrochemical\n");
    }else if(fisheries){

        printf("fisheries\n");

    }else if(equipment){

        printf("all equipment \n");

    }else{

        printf("enter valid category!\n\n");
        chooseCategory();

    }





}