

#include "dashBoard.h"
#include <stdio.h>
#include <string.h>
#include "../Home/home.h"
#include "../Login and Registration/Registration/registration.h"


void showDashBoard(){

    printf("***************** Dash Board *******************\n");

    // showing total number of account ;

    totalNumberOfCustomer();

    // show all ordered product
    totalAllOrder();

    Go_back();



}

void Go_back(){

    char userAns[10];
    printf("Enter A.back: ");
    scanf("%s", userAns);

    int back = !strcmp(userAns, "back");

    if(back) {
        displayHeader();

    }else{

        printf("Enter valid command !\n");
        Go_back();
    }



}

void totalNumberOfCustomer(){

    TypicalRegister account;
    FILE* registrationData = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r" );

    if(!registrationData){

        printf("Failed to open registration data file!\n");
        return ;
    }

    int cnt = 0;

    while(fread(&account, sizeof(TypicalRegister),1 , registrationData) ){

        cnt++;

    }
    fclose(registrationData);
    printf("Total Number Of Account : %d\n", cnt );


}

void totalAllOrder(){

    printf("************** Total Order **************\n");

    TypicalRegister account;
    FILE* registrationData = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r" );

    if(!registrationData){

        printf("Failed to open registration data file!\n");
        return ;
    }

    while(fread(&account, sizeof(TypicalRegister),1 , registrationData) ){

        int totalOrder = account.totalItemToOrder;

        for(int i =0; i< totalOrder; i++){

            printf("Product Name-> %s and Price-> %d\n",account.myOrder[i].productName, account.myOrder[i].totalPrice );

        }

    }
    fclose(registrationData);

}

