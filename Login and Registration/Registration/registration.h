

#ifndef AGRICULTURE_VIRTUAL_SHOP_REGISTRATION_H
#define AGRICULTURE_VIRTUAL_SHOP_REGISTRATION_H

typedef struct {

    char firstName[30];
    char lastName[20];
    char gmail[50];
    char phone[20];
    char status[5];
    char password[50];
    char secreteKey[50];



}AdminRegister;

typedef struct {

    char productName[50];
    int quantity;
    int totalPrice;


}MyOrder;

typedef struct {

    char itemName[100];
    int itemPrice;

}Item;
typedef struct {

    char firstName[30];
    char lastName[20];
    char gmail[50];
    char phone[20];
    char status[5];
    char password[50];
    Item cartItems[21];
    MyOrder myOrder[20];
    int cartItemCount;
    int totalPrice;
    int totalItemToOrder;


}TypicalRegister;



void registrationPage();
void chooseNext();
void typeOfUserForRegister();
void adminRegistration();
int userAccountExistence();
int AdminAccountExistence();


#endif //AGRICULTURE_VIRTUAL_SHOP_REGISTRATION_H
