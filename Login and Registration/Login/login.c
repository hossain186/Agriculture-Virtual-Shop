
#include "login.h"
#include <string.h>
#include <stdio.h>
#include "../../Home/home.h"
#include "../Registration/registration.h"
#include "../../Home/home.h"


void loginPage(){

    printf("******** Login ********\n");

    char userEmail[50];
    char userPass[20];

    printf("    Enter your email : ");
    scanf("    %s", userEmail);

    printf("    Enter your password : ");
    scanf("    %s", userPass);

    FILE* registrationData = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt","r" );

    int cnt = 0;
    char word[50];
    while (fscanf(registrationData, "%s", word) != EOF) {
        if(cnt ==1){
            int passCompare = !strcmp(userPass,word );
            if(passCompare){

                printf("    Login Successful.\n");
                displayHeader();

            }else{

                printf("    Incorrect password!\n");
                loginPage();
            }

        }else {


            int emailCompare = !strcmp(userEmail, word);
            if(emailCompare){

                cnt++;
            }
        }


    }
    fclose(registrationData);
    accountNotFound();



}

void accountNotFound(){

    printf("    Your email not found. enter register/login(back)");
    char userAns[20];
    scanf("    %s", userAns);

    int login = !strcmp(userAns, "login");
    int registration = !strcmp(userAns, "register");
    int back = !strcmp(userAns, "back");
    if(back){
        displayHeader();
    }else if(login){
        loginPage();
    } else if (registration){
        registrationPage();
    }else{

        printf("   Enter valid input!\n");
        accountNotFound();

    }





}


