
#include "paddy.h"
#include <stdlib.h>
#include<stdio.h>
#include "string.h"


seeds *allSeeds(){



    seeds paddy[5];

    strcpy(paddy[0].name,"BR1");
    paddy[0].price = 499;

    strcpy(paddy[1].name,"BR2");
    paddy[0].price = 399;

    strcpy(paddy[2].name,"BR3");
    paddy[0].price = 468;

    strcpy(paddy[3].name,"BR4");
    paddy[0].price = 599;

    strcpy(paddy[4].name,"BR5");
    paddy[0].price = 293;

    return paddy;


}



