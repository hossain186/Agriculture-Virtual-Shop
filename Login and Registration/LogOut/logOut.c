
#include "logOut.h"
#include <string.h>
#include <stdio.h>
#include "../../Home/home.h"


void logOut(){

    printf("************* Logout ***********\n");
    char userAns[10];
    printf("Enter yes or back: ");
    scanf("%s", userAns);

    int yes = !strcmp(userAns, "yes");
    int back = !strcmp(userAns, "back");

    if(yes){

        FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "w");
        fprintf(loginStatusFile, "%s\n","no");
        fclose(loginStatusFile);

        printf("Logout successful.\n");
        displayHeader();


    }else if(back){

        displayHeader();

    }else{

        printf("enter valid type!\n");
        logOut();
    }



}

