//
// Created by hossain on 7/23/24.
//

#ifndef AGRICULTURE_VIRTUAL_SHOP_MY_ORDER_H
#define AGRICULTURE_VIRTUAL_SHOP_MY_ORDER_H

void showAllOrders();
void showDeliveredProduct();

int addToOrderList(char itemName[50], int itemPrice, int itemQuantity);
void chooseItemToOrder(int totalProductInCart);
int removeItemFromCart(char productName[], char gmail[]);
void chooseBack();

#endif //AGRICULTURE_VIRTUAL_SHOP_MY_ORDER_H


