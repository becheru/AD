#include <stdio.h>
#include <stdlib.h>
#define MAX 1000

int read_vector(int *vector){
       int iterator = 0;
       int vector_length = 0;

       printf("Give the length of the vector:");
       scanf("%d",&vector_length);
       for (iterator = 0; iterator < vector_length; iterator++){
               printf("vector[%d]=",iterator);
               scanf("%d",vector + iterator); // &vector[iterator]
       }
       return vector_length;
}

void list_vector(int *vector_start,int vector_length){
       int iterator = 0;

       printf("\nVector: \n");
       for (iterator = 0; iterator < vector_length; iterator++) {
               printf("%d ",*(vector_start + iterator)); // vector[iterator]
       }
}

int split_vector(int *vector,int left, int right){
       int iterator = left;
       int iterator2 = right;
       int pivot_value = vector[left];
       int aux = 0;

       while (1 > 0){
               while (vector[iterator2] > pivot_value ){
                       iterator2--;
               }
               while (vector[iterator] < pivot_value ){
                        iterator++;
               }
               if (iterator < iterator2) {
                       aux = vector[iterator];
                       vector[iterator] = vector[iterator2];
                       vector[iterator2] = aux;
               }else{
                       return iterator2;
               }
       }
}

void quick_sort(int *vector, int left, int right){
       int pivot_pos = 0;

       if (left < right){
               pivot_pos = split_vector(vector, left, right);
               quick_sort(vector, left, pivot_pos);
               quick_sort(vector, pivot_pos + 1, right);
      }
}

void insertion_sort(int *vector, int vector_length){
       int iterator = 0;
       int iterator2 = 0;
       int aux = 0;

       for (iterator = 0; iterator < vector_length; iterator++){
               iterator2 = iterator;
               while ((iterator2 > 0) && (vector[iterator2] < vector[iterator2 - 1])) {
                       aux = vector[iterator2];
                       vector[iterator2] = vector[iterator2 - 1];
                       vector[iterator2 - 1] = aux;
                       iterator2--;
               }
       }
}

int main()
{
       int vector[MAX];
       int vector_length = read_vector(vector);

       list_vector(vector, vector_length);
       //quick_sort(vector, 0,vector_length - 1);
       insertion_sort(vector, vector_length);
       list_vector(vector, vector_length);

       return 0;
}
