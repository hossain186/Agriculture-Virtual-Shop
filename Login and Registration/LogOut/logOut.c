
#include "logOut.h"
#include <string.h>
#include <stdio.h>
#include "../../Home/home.h"


void logOut(){

    printf("************* Logout ***********\n");
    char userAns;
    printf("Enter A.yes or B.back: ");
    scanf(" %c", &userAns);


    if(userAns == 'A' || userAns == 'a'){

        FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "w");
        fprintf(loginStatusFile, "%s\n","no");
        fclose(loginStatusFile);

        printf("Logout successful.\n");
        displayHeader();


    }else if(userAns == 'B' || userAns == 'b'){

        displayHeader();

    }else{

        printf("enter valid type!\n");
        logOut();
    }


}

