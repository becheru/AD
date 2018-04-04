//
// Created by Alexandru Becheru on 14/03/2018.
//

#include "basic.h"

void interchange_values(int *address_1, int *address_2){
    int aux;

    aux = *address_1;
    *address_1 = *address_2;
    *address_2 = aux;
}