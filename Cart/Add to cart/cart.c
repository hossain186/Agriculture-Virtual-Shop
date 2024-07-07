
#include "cart.h"
#include<stdio.h>
#include<string.h>



int addItemToCart(char itemName[], int itemPrice) {
    int totalCartItem = 0;
    int totalPrice = 0;

    // Open the file for reading current totals
    FILE *totalPriceAndItemRead = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Cart/Add to cart/totalPrice.txt", "r");
    if (totalPriceAndItemRead != NULL) {
        // Read the current total items and total price
        fscanf(totalPriceAndItemRead, "%i", &totalCartItem);
        fscanf(totalPriceAndItemRead, "%i", &totalPrice);
        fclose(totalPriceAndItemRead);  // Close the file after reading
    } else {
        perror("Failed to open file for reading");
        return 0;
    }

    // Check if the cart is full
    if (totalCartItem == 50) {
        return 0; // Cart is full, return without adding item
    } else {
        // Update the total items and total price
        totalCartItem++;
        totalPrice += itemPrice;


        // Open the file for writing updated totals
        FILE *totalPriceAndItemWrite = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Cart/Add to cart/totalPrice.txt", "w");
        if (totalPriceAndItemWrite == NULL) {
            perror("Failed to open file for writing\n");
            return 0;
        }

        // Write the updated totals back to the file
        fprintf(totalPriceAndItemWrite, "%d\n", totalCartItem);
        fprintf(totalPriceAndItemWrite, "%d\n", totalPrice);
        fclose(totalPriceAndItemWrite);  // Close the file after writing

        // Open the file for appending new item
        FILE *allItem = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Cart/Add to cart/cartItem.txt", "a");
        if (allItem == NULL) {
            perror("Failed to open cartItem.txt for appending\n");
            return 0;
        }

        // Append the item name and price to the file
        fprintf(allItem, "%s\n", itemName);
        fclose(allItem);  // Close the file after appending

        return 1;
    }
}


void showAllCartItems(){

    printf("*********** Cart **********\n");

    int totalCartItem = 0;
    int totalPrice = 0;

    // Open the file for reading
    FILE *totalPriceAndItemRead = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Cart/Add to cart/totalPrice.txt", "r");

    if (totalPriceAndItemRead != NULL) {
        // Read the current total items and total price
        fscanf(totalPriceAndItemRead, "%i", &totalCartItem);
        fscanf(totalPriceAndItemRead, "%i", &totalPrice);

        fclose(totalPriceAndItemRead);

    } else {
        perror("Failed to open file for reading");
        return;
    }

    printf("Total Item : %d\nTotal Price : %d", totalCartItem, totalPrice);

    printf("\n");

    FILE *allItem = fopen("/home/hossain/Windo1/Agriculture_Virtual_Shop/Cart/Add to cart/cartItem.txt", "r");

    int cnt = 0;
    char word[50];
    while (fscanf(allItem, "%s", word) != EOF) {
       printf("%s ", word);
       cnt++;
       if(cnt%9 ==0){
           printf("\n");

       }
    }

    fclose(allItem);





}
