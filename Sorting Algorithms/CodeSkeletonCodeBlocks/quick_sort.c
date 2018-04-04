//
// Created by Alexandru Becheru on 14/03/2018.
//
#include "vectors.h"
#include "basic.h"

int find_pivot_position(int *vector, int left, int right){

}

void quick_sort(int *vector, int left, int right){
    int pivot_position = 0;

    if (left < right){
        pivot_position = find_pivot_position(vector, left, right);
        quick_sort(vector, left, pivot_position);
        quick_sort(vector, pivot_position + 1, right);
    }
}
