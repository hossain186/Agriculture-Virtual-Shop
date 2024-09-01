
#include "registration.h"
#include <stdio.h>
#include <string.h>
#include "../Login/login.h"
#include "../../Home/home.h"

#define cmp(s1,s2) !strcmp(s1,s2)


void typeOfUserForRegister(){
    printf("******* Registration *********\n");

    char userAns[10];

    printf("Select type of registration(admin/typical) or back: ");
    scanf("%s", userAns);

    toLower(userAns);

    int admin= !strcmp(userAns, "admin");
    int typical= !strcmp(userAns, "typical");
    int back = !strcmp(userAns, "back");

    if(back){

        displayHeader();

    }else if(admin){


        printf("Enter secrete code: ");

        scanf("%s", userAns);
        toLower(userAns);

        int valid = !strcmp(userAns, "123");

        if(valid){
            fflush(stdin);
            adminRegistration();

        }else{

            printf("Sorry your are not eligible for admin resister!.\n");
            typeOfUserForRegister();

        }




    }else if(typical){
        registrationPage();

    }else{

        printf("Enter valid type!\n");
        typeOfUserForRegister();
    }




}

void adminRegistration(){


    AdminRegister admin;

    printf("******* Admin Registration *********\n\n");



    char firstName[30];
    char lastName[20];
    char adminGmail[50];
    char adminPhone[20];
    char secreteKey[50];

    char password[50];
    char confirmPassword[20];

    // admin status
    strcpy(admin.status, "yes");


    printf("    Enter your first name : ");
    scanf("%s",firstName);
    fflush(stdin);
    strcpy(admin.firstName, firstName);



    printf("    Enter your last name : ");
    fflush(stdin);

    scanf("    %s", lastName);
    strcpy(admin.lastName, lastName);




    printf("    Enter your gmail : ");
    scanf("    %s",adminGmail );
    strcpy(admin.gmail, adminGmail);



    printf("    Enter your phone number : ");
    scanf("    %s", adminPhone);
    strcpy(admin.phone, adminPhone);




    printf("    Enter your secrete key : ");
    scanf("    %s", secreteKey);
    strcpy(admin.secreteKey, secreteKey);



    printf("    Enter password : ");
    scanf("    %s", password);
    strcpy(admin.password, password);




    printf("    Confirm password : ");
    scanf("    %s", confirmPassword);


    // check account existence
    FILE *file = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt", "r");
    int adminAccountAlreadyExist = AdminAccountExistence(file,adminGmail);
    fclose(file);




    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt", "a");

    // compare
    int cmpPassword = !strcmp(password, confirmPassword);



    if(adminAccountAlreadyExist){
        printf("Admin account already exist!. Please try again.\n\n");
        displayHeader();

    }else if(cmpPassword){


        fwrite(&admin, sizeof(AdminRegister), 1,registration);


        printf("    Account created successfully.\n");
        fclose(registration);
        chooseNext();;

    }else{
        printf("    Password Doesn't match. Please Try again!\n");
        // file close
        fclose(registration);

    }

    // file close
    fclose(registration);


}


void registrationPage(){

    TypicalRegister user;

    printf("******* Registration *********\n\n");
    char firstName[30];
    char lastName[20];
    char userGmail[50];
    char userPhone[20];


    char password[50];
    char confirmPassword[20];
    int accountAlreadyExist = 0;

    // admin status
    strcpy(user.status, "no");


    printf("    Enter your first name : ");
    scanf("%s",firstName);
    fflush(stdin);
    strcpy(user.firstName, firstName);



    printf("    Enter your last name : ");
    fflush(stdin);

    scanf("    %s", lastName);
    strcpy(user.lastName, lastName);




    printf("    Enter your gmail : ");
    scanf("    %s",userGmail );
    strcpy(user.gmail, userGmail);



    printf("    Enter your phone number : ");
    scanf("    %s", userPhone);
    strcpy(user.phone, userPhone);






    printf("    Enter password : ");
    scanf("    %s", password);
    strcpy(user.password, password);



    printf("    Confirm password : ");
    scanf("    %s", confirmPassword);

    // set default cart item number and price
    user.cartItemCount = 0;
    user.totalPrice = 0;


    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "a");


    FILE *registrationFileForCheckingExistence = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r");
    accountAlreadyExist = userAccountExistence(registrationFileForCheckingExistence, userGmail);
    fclose(registrationFileForCheckingExistence);

    // compare
    int cmpPassword = !strcmp(password, confirmPassword);

    if(accountAlreadyExist){
        printf("Account already exist!. Please try again.\n\n");
        displayHeader();
    }
    else if(cmpPassword){


        fwrite(&user, sizeof(TypicalRegister), 1,registration);


        printf("    Account created successfully.\n");
        fclose(registration);
        chooseNext();

    }else{
        printf("    Password Doesn't match. Please Try again!\n");
        // file close
        fclose(registration);
        registrationPage();// from-> itself

    }



}

void chooseNext(){
    char userAns[10];
    printf("    Enter Login or back : ");
    scanf("    %s", userAns);

    int login = !strcmp(userAns , "login");
    int back = !strcmp(userAns , "back");

    if(back){
        displayHeader();// Home
    }else if(login){
        typeOfUser();// login
    }else{

        printf("    Enter valid input!\n");
        chooseNext();// itself

    }


}


int userAccountExistence(FILE *file, char userGmail[] ){

    TypicalRegister user;

    while(fread(&user, sizeof(TypicalRegister), 1,  file)){

        int gmailExist  = !strcmp(user.gmail, userGmail);

        if(gmailExist){

            return 1;

        }

    }

    return 0;


}

int AdminAccountExistence(FILE *file, char adminGmail[] ){

    AdminRegister admin;

    while(fread(&admin, sizeof(AdminRegister), 1,  file)){

        int gmailExist  = !strcmp(admin.gmail, adminGmail);

        if(gmailExist){

            return 1;

        }

    }

    return 0;


}