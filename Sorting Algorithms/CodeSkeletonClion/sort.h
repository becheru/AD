//
// Created by Alexandru Becheru on 12/03/2018.
//

#ifndef MERGESORT_SORT_H
#define MERGESORT_SORT_H

void merge_left_right(int *vector, int start, int middle, int stop);
int merge_sort(int *vector, int left, int right);
void selection_sort(int *vector, int vector_length);
void insertion_sort(int *vector, int vector_length);
void quick_sort(int *vector, int left, int right);

#endif //MERGESORT_SORT_H
