#include <stdio.h>
#include <stdlib.h>
#include "vectors.h"
#include "sort.h"
#include "basic.h"


int main(){
    int *vector_1;
    int vector_1_length;
    int min_position;

    int *vector_2;
    int vector_2_length;

    int *vector3;
    int vector_3_length;

    int vector_4[10] = {9,8,7,6,5,4};
    int vector_4_length = 6;

    int vector_5[10] = {9,8,7,6,5,4};
    int vector_5_length = 6;

    int a = 5;
    int b = 6;

    printf("\n=========== Interchange of values through pointers ===========");
    printf("\nInitial value of a= %d",a);
    printf("\nInitial value of b= %d",b);
    interchange_values(&a, &b);
    printf("\nNew value of a= %d",a);
    printf("\nNew value of b= %d",b);

    printf("\n=========== Read and write vectors ===========");
    vector_1_length = read_vector_length();
    vector_2_length = read_vector_length();
    vector_1 = calloc(vector_1_length, sizeof(int));
    vector_2 = calloc(vector_2_length, sizeof(int));
    read_vector(vector_1, vector_1_length);
    read_vector(vector_2, vector_2_length);
    write_vector(vector_1, 0, vector_1_length);
    write_vector(vector_2, 0, vector_2_length);

    printf("\n=========== Position of the minimum element in a vector ===========");
    min_position = find_min_position(&vector_1[0], 0, vector_1_length);
    printf("\n The position of the  minimum element from the first vector is: %d", min_position);

    printf("\n=========== Merge of vectors ===========");
    vector3 = merge_vectors(vector_1, vector_1_length, vector_2, vector_2_length);
    vector_3_length = vector_1_length + vector_2_length;
    printf("\nThe merging of vector_1 and vector_2 (interclasare) is:");
    write_vector(vector3, 0, vector_3_length);

    printf("\n=========== Selection Sort ===========");
    printf("\nThe unsorted values of vector 4 are:");
    write_vector(&vector_4[0], 0, vector_4_length);
    selection_sort(&vector_4[0],vector_4_length);
    printf("\nThe sorted values, selection sort method, of vector 4 is:");
    write_vector(&vector_4[0], 0, vector_4_length);

    printf("\n=========== Merge Sort ===========");
    printf("\nThe unsorted values of vector 5 are:");
    write_vector(&vector_5[0], 0, vector_5_length);
    merge_sort(&vector_5[0], 0, vector_5_length-1);
    printf("\nThe sorted values, merge sort method, of vector 5 is:");
    write_vector(&vector_5[0], 0, vector_5_length);

    printf("\n=========== Insertion Sort ===========");
    printf("\nThe unsorted values of vector 5 are:");
    write_vector(&vector_5[0], 0, vector_5_length);
    insertion_sort(&vector_5[0], vector_5_length);
    printf("\nThe sorted values, insertion sort method, of vector 5 is:");
    write_vector(&vector_5[0], 0, vector_5_length);

    printf("\n=========== Quick Sort ===========");
    printf("\nThe unsorted values of vector 5 are:");
    write_vector(&vector_5[0], 0, vector_5_length);
    quick_sort(&vector_5[0], 0, vector_5_length-1);
    printf("\nThe sorted values, quick sort method, of vector 5 is:");
    write_vector(&vector_5[0], 0, vector_5_length);


    return 0;
}