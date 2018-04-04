//
// Created by Alexandru Becheru on 14/03/2018.
//
#include "vectors.h"
#include "basic.h"

int find_pivot_position(int *vector, int left, int right){
    int iterator_1 = left;
    int iterator_2 = right;
    int pivot_value = *(vector + left);

    while (1 > 0){
        while (vector[iterator_2] > pivot_value ){
            iterator_2--;
        }
        while (vector[iterator_1] < pivot_value ){
            iterator_1++;
        }
        if (iterator_1 < iterator_2) {
            interchange_values( (vector + iterator_1), (vector + iterator_2) );
        }else{
            return iterator_2;
        }
    }
}

void quick_sort(int *vector, int left, int right){
    int pivot_position = 0;

    if (left < right){
        pivot_position = find_pivot_position(vector, left, right);
        quick_sort(vector, left, pivot_position);
        quick_sort(vector, pivot_position + 1, right);
    }
}