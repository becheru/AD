//
// Created by Alexandru Becheru on 14/03/2018.
//
#include "basic.h"


void insertion_sort(int *vector, int vector_length){
    int iterator_1 = 0;
    int iterator_2 = 0;
    int aux = 0;

    for (iterator_1 = 0; iterator_1 < vector_length; iterator_1++){
        iterator_2 = iterator_1;
        while ((iterator_2 > 0) && (vector[iterator_2] < vector[iterator_2 - 1])) {
            interchange_values( (vector + iterator_2), (vector + iterator_2 -1) );
            iterator_2--;
        }
    }
}

