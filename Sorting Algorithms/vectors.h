//
// Created by Alexandru Becheru on 12/03/2018.
//

#ifndef MERGESORT_VECTORS_H
#define MERGESORT_VECTORS_H

void read_vector(int *vector, int vector_length);
void write_vector(int *vector, int start, int stop);
int find_min_position(int *vector, int vector_start, int vector_length);
int read_vector_length();
int *merge_vectors(int *vector_1, int vector_1_length, int *vector_2, int vector_2_length);
#endif //MERGESORT_VECTORS_H
