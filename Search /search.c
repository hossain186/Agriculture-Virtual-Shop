
#include "search.h"
#include<stdio.h>
#include <string.h>
#include "../Category/Seeds/Nut/Nut.h"
#include "../Category/Seeds/Legume/legume.h"
#include "../Category/Seeds/Paddy Seeds/paddy.h"
#include "../Home/home.h"


void searchingPage(){
    printf("**************** Search Product ****************\n");

    searchProductByCategory();
}


void searchProductByCategory(){

    char userAns[50];
    printf("Enter type of product: ");
    scanf("%s", userAns);

    int legume = !strcmp(userAns, "legume");
    int nut = !strcmp(userAns, "nut");
    int paddy = !strcmp(userAns, "paddy");

    if(legume){
        showAllLegume();

    }else if(nut){
        showAllNut();
    }else if(paddy){
        showAllPaddy();
    }else{

        printf("Product not found!\n");

    }
    prev();

}

void  prev(){

    printf("Go to a.Home :");
    char userAns;
    scanf(" %c", &userAns);

    if(userAns == 'a'){
        displayHeader();

    }else{
        printf("Enter valid command!\n");
        prev();
    }

}
