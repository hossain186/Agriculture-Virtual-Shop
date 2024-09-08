#include <stdio.h>
#include <string.h>
#include "delete_item.h"
#include "../Add to cart/cart.h"
#include "../../Login and Registration/Registration/registration.h"
#define  br printf("\n")


// Hakuna Matata


void deleteItemFromCart(){

    printf("******************* Cart Items ******************\n");
    br;
    TypicalRegister user;
    FILE *loginStatusFile = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");

    char userLoginStatus[20];
    fscanf(loginStatusFile, "%s", userLoginStatus);
    char userGmail[50];
    fscanf(loginStatusFile, "%s", userGmail);
    fclose(loginStatusFile);

    int alreadyLogin = !strcmp(userLoginStatus, "yes");

    if(!alreadyLogin){

        printf("    Login Required!\n");

    }


    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r");


    while(fread(&user, sizeof(TypicalRegister), 1,registration )){

        int findAccount = !strcmp(userGmail, user.gmail);

        if(findAccount){

            int totalCartItem = user.cartItemCount;

            Item items[21];// struct

            for(int i = 0; i< totalCartItem;i++){

                printf("   %c. %s ",'A'+i, user.cartItems[i].itemName);
                strcpy(items[i].itemName, user.cartItems[i].itemName);
                items[i].itemPrice = user.cartItems[i].itemPrice;

                if(i%2 ==0){
                    br;
                }

            }


            int deleted = chooseItemToDelete(user.gmail, totalCartItem);

            if(deleted){

                printf("Item delete successful.\n");
                showAllCartItems();
            }else{

                printf("Failed to delete!!\n");
                showAllCartItems();
            }

            break;
        }

    }
    fclose(registration);



}

int chooseItemToDelete(char gmail[50], int totalProduct){

    printf("Choose product or Z.back  : ");

    char userAns;
    scanf(" %c", &userAns);
    printf("\n");

    int productIndex = userAns -'a';

    if(productIndex == 25){

        showAllCartItems();

    }else if(productIndex>=0 && productIndex<20) {
        TypicalRegister user;
        FILE *registration = fopen(
                "/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt",
                "r+");

        int flag = 0;
        while (fread(&user, sizeof(TypicalRegister), 1, registration)) {

            int findAccount = !strcmp(gmail, user.gmail);

            if (findAccount) {

                int totalCartItem = user.cartItemCount;
                int productPrice  = user.cartItems[productIndex].itemPrice;

                for(int i = productIndex; i<totalCartItem; i++){

                    strcpy(user.cartItems[i].itemName,user.cartItems[i+1].itemName);
                    user.cartItems[i].itemPrice = user.cartItems[i+1].itemPrice;

                }

                user.totalPrice-= productPrice;
                user.cartItemCount --;

                fseek(registration, -sizeof(TypicalRegister), SEEK_CUR);
                fwrite(&user, sizeof(TypicalRegister), 1, registration);
                fflush(registration); // Ensure data is written to file
                flag = 1;
                break;

            }
        }

        fclose(registration);
        if(flag) return 1;
        else return 0;




    }else{

        printf("Enter valid product!\n");
        chooseItemToDelete(gmail, totalProduct);
    }


    return 0;


}

