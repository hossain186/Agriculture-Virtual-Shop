
#include "cart.h"
#include<stdio.h>
#include<string.h>
#include "../../Home/home.h"
#include "../../Login and Registration/Registration/registration.h"
#define br printf("\n")
#include "../Delete_Item_From_Cart/delete_item.h"
#include "../../My Order/my_order.h"


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

            if(totalCartItem>=20){
                fclose(registration);
                return 0;

            }else{

                totalPrice+= itemPrice;

                strcpy(user.cartItems[totalCartItem].itemName,itemName);
                user.totalPrice = totalPrice;
                totalCartItem++;
                user.cartItemCount = totalCartItem;

                user.cartItems[totalCartItem].itemPrice = itemPrice;

                fseek(registration, -sizeof(TypicalRegister), SEEK_CUR);
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

        printf("    Login Required!\n");
        go_back();

    }



    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r");

    int totalProductInCart =0;

    while(fread(&user, sizeof(TypicalRegister), 1,registration )){

        int findAccount = !strcmp(userGmail, user.gmail);

        if(findAccount){

            int totalCartItem = user.cartItemCount;
            int totalPrice = user.totalPrice;
            totalProductInCart = totalCartItem;

            if(totalCartItem == 0){
                printf("    Your Cart Is Empty!\n");
                go_back();
            }else{

                printf("    Total Price      : %d\n", totalPrice);
                printf("    Total cart item  : %d\n", totalCartItem);
                printf("----------------------------\n");
                for(int i = 0; i< totalCartItem;i++){

                    printf("   %c. %s ",'A'+i, user.cartItems[i].itemName);

                    if(i%2 ==0){
                        br;
                    }

                }
            }

            break;
        }

    }

    fclose(registration);
    addToOrderOrDelete(totalProductInCart);


}

void addToOrderOrDelete(int totalProductInCart){

    br;
    char userAns;
    printf("Choose service (A.Order/B.Delete/C.Back): ");
    scanf(" %c", &userAns);


    if(userAns == 'C' || userAns == 'c'){

        displayHeader();

    }else if(userAns == 'a' || userAns == 'A'){

        chooseItemToOrder(totalProductInCart);

    }else if(userAns == 'b' || userAns == 'B'){

        deleteItemFromCart();

    }

    else{

        printf("Command not found!. Enter again\n");
        go_back();

    }

}

void go_back(){

    printf("Go A.back : ");
    char userAns;
    scanf(" %c", &userAns);

    if(userAns == 'a' || userAns == 'A'){
        displayHeader();
    }else{

        printf("Enter valid service!\n");
        go_back();
    }

}
