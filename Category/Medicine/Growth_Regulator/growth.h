

#ifndef AGRICULTURE_VIRTUAL_SHOP_GROWTH_H
#define AGRICULTURE_VIRTUAL_SHOP_GROWTH_H

typedef struct {
    char name[100];
    int price;
}GrowthRegulator;

void showAllGrowthRegulators();
void chooseGrowthRegulator();

#endif //AGRICULTURE_VIRTUAL_SHOP_GROWTH_H
