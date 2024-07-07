#include <stdio.h>
#include <ctype.h>
#include "home.h"
#include<string.h>
#include "../Category/All_category//category.h"
#include"../Cart/Add to cart/cart.h"
// show display
void displayHeader(){

    char header[][100] = {"Home", "Category","Cart", "About", "Register/Login","Profile"};

    int headerSize = sizeof(header)/sizeof(header[0]);// number of element

    for(int i =0; i< headerSize; i++){

        printf("%s ",header[i]);

    }
    printf("\n\n");

    chooseService();// from->this

}

// convert upper case to lower case
void toLower(char *str){

    while(*str){

        *str = tolower(*str);
        str++;
    }

}


// all service
void chooseService() {

    printf("Select Service : ");

    char userAnswer[50];
    scanf("%s", userAnswer);
    toLower(userAnswer);
    lineBreak();// from->this;

    //"Home", "Category","Cart", "About", "Register/Login","Profile"
    int compareWithCategory = !strcmp(userAnswer, "category");//1
    int compareWithHome = !strcmp(userAnswer, "home");

    int compareWithCart = !strcmp(userAnswer, "cart");
    int compareWithAbout = !strcmp(userAnswer, "about");
    int compareWithProfile = !strcmp(userAnswer, "profile");
    int compareWithLogin = !strcmp(userAnswer, "login");
    int compareWithRegister = !strcmp(userAnswer, "register");

    if(compareWithHome){

        displayHeader();// from->this
    }else if(compareWithCategory){

        displayAllCategory();// from->Category/All_category/category.c


    }else if(compareWithAbout){

        printf("This online shop provide sealing service of all agricultural product\n\n");
    } else if(compareWithCart){
        showAllCartItems();// from-> Cart/Add to cart/ cart.h
    }
    else{
        printf("Enter Valid Service!\n");
        chooseService();// from-> this;

    }


}


void lineBreak(){

    printf("\n");
}

