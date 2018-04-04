//
// Created by Alexandru Becheru on 12/03/2018.
//
#include <stdlib.h>
#include "vectors.h"

void merge_left_right(int *vector, int left, int middle, int right)
{

}

void merge_sort(int *vector, int left, int right){
    int middle;

    if (left == right);
    else {
        middle = (left + right) / 2;
        merge_sort(vector, left, middle);
        merge_sort(vector, middle + 1, right);
        merge_left_right(vector, left, middle, right);
    }
}
