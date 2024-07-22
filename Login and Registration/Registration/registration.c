
#include "registration.h"
#include <stdio.h>
#include <string.h>
#include "../Login/login.h"
#include "../../Home/home.h"

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
    char userGmail[50];
    char userPhone[20];
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
    scanf("    %s",userGmail );
    strcpy(admin.gmail, userGmail);



    printf("    Enter your phone number : ");
    scanf("    %s", userPhone);
    strcpy(admin.phone, userPhone);




    printf("    Enter your secrete key : ");
    scanf("    %s", secreteKey);
    strcpy(admin.secreteKey, secreteKey);



    printf("    Enter password : ");
    scanf("    %s", password);
    strcpy(admin.password, password);




    printf("    Confirm password : ");
    scanf("    %s", confirmPassword);



    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt", "a");

    // compare
    int cmpPassword = !strcmp(password, confirmPassword);

    if(cmpPassword){


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

    // compare
    int cmpPassword = !strcmp(password, confirmPassword);

    if(cmpPassword){


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


