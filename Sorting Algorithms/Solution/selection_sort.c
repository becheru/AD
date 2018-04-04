//
// Created by Alexandru Becheru on 13/03/2018.
//
#include "sort.h"
#include "basic.h"
#include "vectors.h"

void selection_sort(int *vector, int vector_length){
    int iterator;
    int min_position;

    for(iterator = 0; iterator < vector_length-1; iterator++){
        min_position = find_min_position(vector, iterator + 1, vector_length);
        if ( *(vector + min_position) < *(vector + iterator) ) {
            interchange_values(vector + iterator, vector + min_position);
        }
    }
}

