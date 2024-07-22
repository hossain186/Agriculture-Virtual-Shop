
#include "profile.h"
#include <stdio.h>
#include "../Login and Registration/Registration/registration.h"
#include <string.h>
#include "../Home/home.h"


void showProfileData(){
    printf("********************* Profile ************************\n");
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    char userGmail[50];
    char userStatus[20];
    char loginStatus[10];

    fscanf(loginStatusFile, "%s", loginStatus);
    fscanf(loginStatusFile, "%s", userGmail);
    fscanf(loginStatusFile, "%s", userStatus);

    fclose(loginStatusFile);



    int adminProfile = !strcmp(userStatus, "yes");

    if(adminProfile) {



        AdminRegister admin;
        FILE *registration = fopen(
                "/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/Admin_registration_data.txt",
                "r");


        while(fread(&admin, sizeof(AdminRegister), 1, registration)){

            int profileFound = !strcmp(userGmail, admin.gmail);

            if(profileFound){

                printf("Name    : %s %s \n", admin.firstName, admin.lastName);
                printf("Gmail   : %s \n", admin.gmail);
                printf("Phone   : %s  \n", admin.phone);

            }



        }



        fclose(registration);


    }else{


        TypicalRegister user;
        FILE *registration = fopen(
                "/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt",
                "r");


        while(fread(&user, sizeof(TypicalRegister), 1, registration)){

            int profileFound = !strcmp(userGmail, user.gmail);

            if(profileFound){

                printf("Name    : %s %s \n", user.firstName, user.lastName);
                printf("Gmail   : %s \n", user.gmail);
                printf("Phone   : %s  \n", user.phone);

            }



        }


        fclose(registration);


    }


    backToHome();


}

void backToHome(){

    printf("Enter back: ");
    char userAns[10];
    scanf("%s", userAns);
    int back = !strcmp(userAns, "back");

    if(back){

        displayHeader();

    }else{
        printf("Enter valid service!\n");
        backToHome();
    }


}

