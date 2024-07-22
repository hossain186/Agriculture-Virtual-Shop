
#ifndef AGRICULTURE_VIRTUAL_SHOP_LEGUME_H
#define AGRICULTURE_VIRTUAL_SHOP_LEGUME_H

typedef struct{

    char name[100];
    int price;

}Legume;

void addlegume();
void showAllLegume();
void chooseLegume(int totalProduct);




#endif //AGRICULTURE_VIRTUAL_SHOP_LEGUME_H
