
#ifndef AGRICULTURE_VIRTUAL_SHOP_CART_H
#define AGRICULTURE_VIRTUAL_SHOP_CART_H



typedef struct{

    char itemName[40];
    int itemPrice;

}CartItem;

// Track item count


int addItemToCart(char itemName[], int itemPrice);
void showAllCartItems();
void go_back();



#endif //AGRICULTURE_VIRTUAL_SHOP_CART_H
