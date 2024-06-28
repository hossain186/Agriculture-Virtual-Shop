#include <stdio.h>
#include <ctype.h>
#include "home.h"
#include<string.h>

#include "../Category/Home_Page/category.h"
// show display
void displayHeader(){

    char header[][100] = {"Home", "Category","Cart", "About", "Register/Login","Profile"};

    int headerSize = sizeof(header)/sizeof(header[0]);

    for(int i =0; i< headerSize; i++){

        printf("%s ",header[i]);

    }
    printf("\n\n");

    chooseService();

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



    char userAnswer[100];
    scanf("%s", userAnswer);
    lineBreak();

    //"Home", "Category","Cart", "About", "Register/Login","Profile"
    int compareWithCategory = !strcmp(userAnswer, "category");
    int compareWithHome = !strcmp(userAnswer, "home");

    int compareWithCart = !strcmp(userAnswer, "cart");
    int compareWithAbout = !strcmp(userAnswer, "about");
    int compareWithProfile = !strcmp(userAnswer, "profile");
    int compareWithLogin = !strcmp(userAnswer, "login");
    int compareWithRegister = !strcmp(userAnswer, "register");

    if(compareWithHome){

        displayHeader();
    }else if(compareWithCategory){

        displayAllCategory();
        chooseCategory();

    }else if(compareWithAbout){

        printf("This online shop provide sealing service of all agricultural product\n\n");
    }
    else{
        printf("Enter Valid Service!");

    }


}


void lineBreak(){

    printf("\n");
}

