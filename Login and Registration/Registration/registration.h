

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

    char firstName[30];
    char lastName[20];
    char gmail[50];
    char phone[20];
    char status[5];
    char password[50];
    char cartItems[20][100];
    int cartItemCount;
    int totalPrice;


}TypicalRegister;



void registrationPage();
void chooseNext();
void typeOfUserForRegister();
void adminRegistration();
int userAccountExistence();
int AdminAccountExistence();


#endif //AGRICULTURE_VIRTUAL_SHOP_REGISTRATION_H
