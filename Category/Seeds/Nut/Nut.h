

#ifndef AGRICULTURE_VIRTUAL_SHOP_NUT_H
#define AGRICULTURE_VIRTUAL_SHOP_NUT_H

typedef struct{

    char name[100];
    int price;

}nuts;

void addNut();
void showAllNut();
void chooseNut(int totalProduct);
void goBack();
void nextCommand();

#endif //AGRICULTURE_VIRTUAL_SHOP_NUT_H
