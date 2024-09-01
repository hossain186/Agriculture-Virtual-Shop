#include <stdio.h>
#include <ctype.h>
#include "home.h"
#include<string.h>
#include "../Category/All_category//category.h"
#include"../Cart/Add to cart/cart.h"
#include"../Login and Registration/Registration/registration.h"
#include"../Login and Registration/Login/login.h"
#include"../Login and Registration/LogOut/logOut.h"
#include "../Search /search.h"
#include "../Profile/profile.h"
#include "../Dash Board/dashBoard.h"

// show display
void displayHeader(){

    // login status
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");

    char loginStatus[10];
    char userGmail[50];
    char adminStatus[10];
    fscanf(loginStatusFile, "%s", loginStatus);
    fscanf(loginStatusFile, "%s", userGmail);
    fscanf(loginStatusFile, "%s", adminStatus);
    fclose(loginStatusFile);

    int alreadyLogin = !strcmp(loginStatus, "yes");
    int isAdmin = !strcmp(adminStatus, "yes");



    printf("********************* Home ********************\n");
    printf("Home ");
    printf("Category ");
    printf("Search ");
    if(isAdmin){
        printf("Dashboard ");
    }else{
        printf("Cart ");
    }
    if(alreadyLogin){

        printf("MyOrder ");
    }

    if(alreadyLogin){

        printf("SignOut ");
    }else {

        printf("SignUp/SignIn ");
    }
    if(alreadyLogin){

        printf("Profile ");
    }

    printf("About ");



    printf("\n");

    chooseService(isAdmin);// from->this

}

// convert upper case to lower case
void toLower(char *str){

    while(*str){

        *str = tolower(*str);
        str++;
    }

}


// all service
void chooseService(int isAdmin) {

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
    int compareWithSignIn = !strcmp(userAnswer, "signin");
    int compareWithSignUp = !strcmp(userAnswer, "signup");
    int compareWithSearch = !strcmp(userAnswer, "search");
    int signOut = !strcmp(userAnswer, "signout");
    int dashboard = !strcmp(userAnswer, "dashboard");


    // login status
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    char loginStatus[10];
    fscanf(loginStatusFile, "%s", loginStatus);
    fclose(loginStatusFile);

    int alreadyLogin = !strcmp(loginStatus, "yes");


    if(compareWithHome){

        displayHeader();// from->this
    }else if(compareWithCategory){

        displayAllCategory();// from->Category/All_category/category.c


    }else if(compareWithAbout){

        printf("This online shop provide sealing service of all agricultural product\n\n");
    } else if (dashboard && isAdmin){
        showDashBoard();
    }else if(compareWithCart && !isAdmin){


        showAllCartItems();// from-> Cart/Add to cart/ cart.h


    }else if (compareWithSignUp && !alreadyLogin){
        typeOfUserForRegister();
    }else if(compareWithSignIn && !alreadyLogin){

        typeOfUser();

    }else if(compareWithSearch){

        searchingPage();// from-> search/search.h


    }else if (compareWithProfile && alreadyLogin){
        showProfileData();
    }else if (signOut && alreadyLogin){

        logOut();
    }
    else{
        printf("Enter Valid Service!\n");
        chooseService(isAdmin);// from-> this;

    }


}


void lineBreak(){

    printf("\n");
}

