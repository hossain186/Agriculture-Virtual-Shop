
#include "cart.h"
#include<stdio.h>
#include<string.h>
#include "../../Home/home.h"
#include "../../Login and Registration/Registration/registration.h"
#define br printf("\n")

int addItemToCart(char itemName[], int itemPrice) {


    TypicalRegister user;
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    char userGmail[50];
    char userLoginStatus[20];
    fscanf(loginStatusFile, "%s", userLoginStatus);
    fscanf(loginStatusFile, "%s", userGmail);
    fclose(loginStatusFile);


    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r+");

    while(fread(&user, sizeof(TypicalRegister), 1,registration )){

        int findAccount = !strcmp(userGmail, user.gmail);

        if(findAccount){

            int totalCartItem = user.cartItemCount;
            int totalPrice = user.totalPrice;

            totalPrice+= itemPrice;

            if(totalCartItem>=20){
                fclose(registration);
                return 0;

            }else{

                strcpy(user.cartItems[totalCartItem],itemName);
                user.totalPrice = totalPrice;
                totalCartItem++;
                user.cartItemCount = totalCartItem;

                fseek(registration, -sizeof(user), 1 );
                fwrite(&user, sizeof (TypicalRegister), 1, registration);

                fclose(registration);
                return 1;



            }



        }

    }

    fclose(registration);
    return 0;



}


void showAllCartItems(){



    printf("*********** Cart **********\n");


    TypicalRegister user;
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");

    char userLoginStatus[20];
    fscanf(loginStatusFile, "%s", userLoginStatus);
    char userGmail[50];
    fscanf(loginStatusFile, "%s", userGmail);
    fclose(loginStatusFile);

    int alreadyLogin = !strcmp(userLoginStatus, "yes");

    if(!alreadyLogin){

        printf("Login Required!\n");
        go_back();

    }



    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r");


    while(fread(&user, sizeof(TypicalRegister), 1,registration )){

        int findAccount = !strcmp(userGmail, user.gmail);

        if(findAccount){

            int totalCartItem = user.cartItemCount;
            int totalPrice = user.totalPrice;

            if(totalCartItem == 0){
                printf("Your Cart Is Empty!\n");
            }else{

                printf("Total Price      : %d\n", totalPrice);
                printf("Total cart item  : %d\n", totalCartItem);

                for(int i = 0; i< totalCartItem;i++){

                    printf("%s ", user.cartItems[i]);

                    if(i%2 ==0){
                        br;
                    }

                }
            }

            break;
        }

    }

    fclose(registration);
    go_back();






}

void go_back(){

    br;
    char userAns[10];
    printf("Enter back: ");
    scanf("%s", userAns);
    int back = !strcmp(userAns, "back");

    if(back){

        displayHeader();

    }else{

        printf("Command not found!. Enter again\n");
        go_back();

    }

}
