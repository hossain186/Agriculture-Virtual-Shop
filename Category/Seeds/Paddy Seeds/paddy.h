//
// Created by hossain on 6/28/24.
//

#ifndef AGRICULTURE_VIRTUAL_SHOP_PADDY_H
#define AGRICULTURE_VIRTUAL_SHOP_PADDY_H

typedef  struct{

    char name[100];
    int price;

}seeds;


seeds *allSeeds();
void show_seeds();

#endif //AGRICULTURE_VIRTUAL_SHOP_PADDY_H
