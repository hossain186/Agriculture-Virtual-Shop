#include <stdio.h>
#include <string.h>
#include "my_order.h"
#include "../Login and Registration/Registration/registration.h"
#include "../Cart/Delete_Item_From_Cart/delete_item.h"

#define br printf("\n")

// Helper function to get user information from loginStatus.txt
int getUserLoginStatus(char *userGmail) {
    FILE *UserInformation = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Login/loginStatus.txt", "r");
    if (UserInformation == NULL) {
        printf("Error: Unable to open login status file.\n");
        return 0;
    }

    char userLoginStatus[20];
    fscanf(UserInformation, "%s", userLoginStatus); // Read the login status
    fscanf(UserInformation, "%s", userGmail);       // Read the user's Gmail

    fclose(UserInformation);
    return strcmp(userLoginStatus, "yes") == 0;
}

// Show all orders for the logged-in user
void showAllOrders() {
    TypicalRegister user;
    char userGmail[50];

    if (!getUserLoginStatus(userGmail)) {
        printf("You need to log in to view your orders.\n");
        return;
    }


    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r+");
    if (registration == NULL) {
        printf("Error: Unable to open registration data file.\n");
        return;
    }

    while (fread(&user, sizeof(TypicalRegister), 1, registration)) {
        if (strcmp(userGmail, user.gmail) == 0) {
            if (user.totalItemToOrder > 0) {
                printf("Order List:\n");
                for (int i = 0; i < user.totalItemToOrder; i++) {
                    printf("%c. %s (Quantity: %d, Total Price: %d)\n",
                           'A' + i, user.myOrder[i].productName,
                           user.myOrder[i].quantity, user.myOrder[i].totalPrice);
                }

            }
            break;
        }
    }

    fclose(registration);
}

// Add item to order list
int addToOrderList(char itemName[], int itemPrice, int itemQuantity) {
    TypicalRegister user;
    char userGmail[50];

    if (!getUserLoginStatus(userGmail)) {
        printf("Login required to place an order.\n");
        return 0;
    }

    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r+");
    if (registration == NULL) {
        printf("Error: Unable to open registration data file.\n");
        return 0;
    }

    int success = 0;
    while (fread(&user, sizeof(TypicalRegister), 1, registration)) {
        if (strcmp(userGmail, user.gmail) == 0) {
            int totalProductInOrderList = user.totalItemToOrder;

            // Add product to the order list
            strcpy(user.myOrder[totalProductInOrderList].productName, itemName);
            user.myOrder[totalProductInOrderList].totalPrice = itemPrice * itemQuantity;
            user.myOrder[totalProductInOrderList].quantity = itemQuantity;
            user.totalItemToOrder++;

            // Remove the item from the cart
            if (removeItemFromCart(itemName, user.gmail)) {

                // Move file pointer back and update the user record
                fseek(registration, -sizeof(TypicalRegister), SEEK_CUR);
                fwrite(&user, sizeof(TypicalRegister), 1, registration);
                fflush(registration); // Ensure data is written to file

                success = 1;
            } else {
                printf("Failed to remove the item from the cart.\n");
            }
            break;
        }
    }

    fclose(registration);
    return success;
}

// Choose item from cart to order
void chooseItemToOrder(int totalProductInCart) {
    printf("Select product or Z.back: ");
    char userAns;
    scanf(" %c", &userAns);

    int productIndex = userAns - 'a';

    if (userAns == 'Z' || userAns == 'z') {
        return;
    } else if (productIndex >= 0 && productIndex < totalProductInCart) {
        TypicalRegister user;
        char userGmail[50];

        if (!getUserLoginStatus(userGmail)) {
            printf("Login required to proceed.\n");
            return;
        }

        FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r+");
        if (registration == NULL) {
            printf("Error: Unable to open registration data file.\n");
            return;
        }

        while (fread(&user, sizeof(TypicalRegister), 1, registration)) {
            if (strcmp(userGmail, user.gmail) == 0) {
                int quantity;
                printf("Enter quantity: ");
                scanf("%d", &quantity);

                // Add the item to the order list
                if (addToOrderList(user.cartItems[productIndex].itemName, user.cartItems[productIndex].itemPrice, quantity)) {
                    printf("Item added to the order successfully.\n");
                } else {
                    printf("Failed to add item to the order.\n");
                }
                break;
            }
        }

        fclose(registration);
    } else {
        printf("Enter a valid product.\n");
    }
}

// Remove item from cart
int removeItemFromCart(char productName[], char gmail[]) {
    TypicalRegister user;
    FILE *registration = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Login and Registration/Registraton Data/registration_data.txt", "r+");
    if (registration == NULL) {
        printf("Error: Unable to open registration data file.\n");
        return 0;
    }

    int success = 0;
    while (fread(&user, sizeof(TypicalRegister), 1, registration)) {
        if (strcmp(gmail, user.gmail) == 0) {

            int totalCartItem = user.cartItemCount;
            int productIndex = -1;

            for (int i = 0; i < totalCartItem; i++) {
                if (strcmp(productName, user.cartItems[i].itemName) == 0) {
                    productIndex = i;
                    break;
                }
            }

            printf("%d ,%d ", productIndex, totalCartItem);

            int productPrice = user.cartItems[productIndex].itemPrice;

            // Shift remaining items
            for (int i = productIndex; i < totalCartItem; i++) {
                strcpy(user.cartItems[i].itemName, user.cartItems[i + 1].itemName);
                user.cartItems[i].itemPrice = user.cartItems[i + 1].itemPrice;
            }

            user.cartItemCount--;
            user.totalPrice -= productPrice;

            // Move file pointer back and update the user record
            fseek(registration, -sizeof(TypicalRegister), SEEK_CUR);
            if (fwrite(&user, sizeof(TypicalRegister), 1, registration) != 1) {
                printf("Error writing to file.\n");
                fclose(registration);
                return 0;
            }

            fflush(registration); // Ensure data is written to file
            success = 1;
            break;
        }
    }

    fclose(registration);
    return success;
}

