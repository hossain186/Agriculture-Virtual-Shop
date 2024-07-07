
#include "registration.h"
#include <stdio.h>
#include <string.h>
#include "../Login/login.h"
#include "../../Home/home.h"

void registrationPage(){

    printf("******* Registration *********\n\n");

    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "a");

    char userEmail[50];
    char userPassword[20];
    char confirmPassword[20];

    printf("    Enter your email : ");
    scanf("    %s", userEmail);

    printf("    Enter Password : ");
    scanf("    %s", userPassword);
    printf("    Confirm Password : ");
    scanf("    %s",confirmPassword);

    int cmpPassword = !strcmp(userPassword, confirmPassword);

    if(cmpPassword){

        fprintf(registration, "%s\n", userEmail);
        fprintf(registration, "%s\n\n", confirmPassword);
        printf("    Account created successfully.\n");

    }else{
        printf("    Password Doesn't match. Please Try again!\n");
        registrationPage();

    }

    fclose(registration);

    chooseNext();


}

void chooseNext(){
    char userAns[10];
    printf("    Enter Login or back : ");
    scanf("    %s", userAns);

    int login = !strcmp(userAns , "login");
    int back = !strcmp(userAns , "back");

    if(back){
        displayHeader();
    }else if(login){
        loginPage();
    }else{

        printf("    Enter valid input!\n");
        chooseNext();

    }


}


