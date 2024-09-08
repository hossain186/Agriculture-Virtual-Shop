
#include "login.h"
#include <string.h>
#include <stdio.h>
#include "../../Home/home.h"
#include "../Registration/registration.h"
#include "../../Home/home.h"


//    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt", "r");

void typeOfUser(){
    printf("******* Login Page *********\n");

    char userAns;

    printf("Select type of User(A.admin/B.typical) or C.back: ");
    scanf(" %c", &userAns);

    if(userAns == 'c' || userAns == 'C'){

        displayHeader();

    }else if(userAns == 'A' || userAns == 'a'){

        adminLogin();

    }else if(userAns == 'b' || userAns == 'B'){
        loginPage();

    }else{

        printf("Enter valid type!\n");
        typeOfUser();
    }




}


void adminLogin(){

    AdminRegister admin;
    printf("******** Admin Login ********\n");

    char userGmail[50];
    char userPass[50];
    char secreteKey[20];

    printf("    Enter your email : ");
    scanf("    %s", userGmail);

    printf("    Enter your password : ");
    scanf("    %s", userPass);

    printf("    Enter your secrete key : ");
    scanf("    %s", secreteKey);

    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt", "r");

    while(fread(&admin,  sizeof(AdminRegister), 1, registration)){

        int validGmail = !strcmp(admin.gmail, userGmail);

        if(validGmail){

            int validPass = !strcmp(admin.password, userPass);

            if(validPass){

                int validSecreteKey = !strcmp(admin.secreteKey, secreteKey);
                if(validSecreteKey){

                    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "w");

                    // maintain login status
                    fprintf(loginStatusFile, "%s\n","yes");
                    fprintf(loginStatusFile, "%s\n",admin.gmail );
                    fprintf(loginStatusFile, "%s\n",admin.status );
                    fclose(loginStatusFile);


                    printf("Welcome, %s!\n", admin.lastName);
                    fclose(registration);

                    displayHeader();


                }else{

                    printf("Secrete key doesn't match!\n");
                    fclose(registration);
                    displayHeader();


                }


            }else{

                printf("Password doesn't match!\n");
                fclose(registration);
                displayHeader();

            }

        }



    }

    printf("Admin account not found!\n");

    fclose(registration);
    typeOfUserForRegister();


}



void loginPage(){

    TypicalRegister user;
    printf("******** User Login ********\n");

    char userGmail[50];
    char userPass[50];


    printf("    Enter your email : ");
    scanf("    %s", userGmail);

    printf("    Enter your password : ");
    scanf("    %s", userPass);


    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r");

    while(fread(&user,  sizeof(TypicalRegister), 1, registration)){

        int validGmail = !strcmp(user.gmail, userGmail);

        if(validGmail){

            int validPass = !strcmp(user.password, userPass);

            if(validPass){


                FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "w");

                // maintain login status
                fprintf(loginStatusFile, "%s\n","yes");
                fprintf(loginStatusFile, "%s\n",user.gmail );
                fprintf(loginStatusFile, "%s\n",user.status );
                fclose(loginStatusFile);


                printf("Welcome, %s!\n", user.lastName);
                fclose(registration);
                displayHeader();


            }else{

                printf("Password doesn't match!\n");
                fclose(registration);
                loginPage();

            }

        }



    }

    printf("User account not found!\n");

    fclose(registration);
    typeOfUserForRegister();


}

void accountNotFound(){

    printf("    Your email not found. Enter (A.register/B.login/C.back)");
    char userAns;
    scanf("     %c", &userAns);




    if(userAns == 'C' || userAns == 'c'){
        displayHeader();// Home
    }else if(userAns == 'B' || userAns == 'b'){
        loginPage();// login
    } else if (userAns == 'A' || userAns == 'a'){
        registrationPage();// registration
    }else{

        printf("   Enter valid input!\n");
        accountNotFound();// itself

    }


}


