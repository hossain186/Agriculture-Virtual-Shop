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

#include "../My Order/my_order.h"

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
    printf("A.Home  ");
    printf("B.Category  ");
    printf("C.Search  ");


    if(isAdmin){
        printf("D.Dashboard  ");
    }else{
        printf("D.Cart  ");
    }
    if(alreadyLogin){

        printf("E.MyOrder  ");
    }

    if(alreadyLogin){

        printf("F.SignOut  ");
    }else {

        printf("E.SignUp  ");
        printf("F.SignIn  ");
    }
    if(alreadyLogin){

        printf("G.Profile  ");
    }

    if(alreadyLogin){
        printf("H.About ");
    }else {
        printf("G.About ");
    }


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




    //"Home", "Category","Cart", "About", "Register/Login","Profile"
    /*int compareWithCategory = !strcmp(userAnswer, "B");//1
    int compareWithHome = !strcmp(userAnswer, "A");

    int compareWithCart = !strcmp(userAnswer, "D");
    int compareWithAbout = !strcmp(userAnswer, "about");
    int compareWithProfile = !strcmp(userAnswer, "profile");
    int compareWithSignIn = !strcmp(userAnswer, "signin");
    int compareWithSignUp = !strcmp(userAnswer, "signup");
    int compareWithSearch = !strcmp(userAnswer, "C");
    int signOut = !strcmp(userAnswer, "signout");
    int dashboard = !strcmp(userAnswer, "dashboard");
     */

    // login status
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    char loginStatus[10];
    fscanf(loginStatusFile, "%s", loginStatus);
    fclose(loginStatusFile);



    int alreadyLogin = !strcmp(loginStatus, "yes");
    printf("Select Service : ");

    char userAnswer;
    scanf(" %c", &userAnswer);
    lineBreak();

    if(userAnswer == 'A' || userAnswer == 'a'){
        displayHeader();// from-> this

    }else if(userAnswer == 'B' || userAnswer == 'b'){
        displayAllCategory();// from->Category/All_category/category.c

    }else if((userAnswer == 'D' || userAnswer == 'd') && isAdmin){
        showDashBoard();
    }else if(userAnswer == 'D' || userAnswer == 'd'){
        showAllCartItems();// from-> Cart/Add to cart/ cart.h

    }else if(userAnswer == 'c' || userAnswer == 'C'){
        searchProduct();// from-> Cart/Add to cart/ cart.h

    }else if(!alreadyLogin && (userAnswer =='E' || userAnswer == 'e')){
        typeOfUserForRegister();

    }else if(!alreadyLogin  && (userAnswer =='F' || userAnswer == 'f')){
        typeOfUser();
    }else if((!alreadyLogin ) && (userAnswer =='G' || userAnswer == 'g')){
        printf("This online shop provide sealing service of all agricultural product\n\n");

    }else if(alreadyLogin) {

        if(userAnswer == 'e' || userAnswer == 'E') {

            showAllOrders();

        }else if(userAnswer == 'f' || userAnswer == 'f') {

            logOut();
        }else if(userAnswer =='g' || userAnswer == 'G') {
            showProfileData();
        }else if(userAnswer == 'H' || userAnswer == 'h') {
            printf("This online shop provide sealing service of all agricultural product\n\n");

        }else {
            printf("Enter Valid Service!\n");
            chooseService(isAdmin);// from-> this;
        }


    }
    else{

            printf("Enter Valid Service!\n");
            chooseService(isAdmin);// from-> this;

    }
    /*
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

     */

}


void lineBreak(){

    printf("\n");
}

