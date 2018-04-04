#include <stdio.h>

int main(){
       int vector[7] = { 11, 22, 33, 44, 55, 66, 77 } ;
       int iterator = 0;
       int *pointer = NULL;

       /* for loop to print value and address of each element of array*/
       for ( int iterator = 0 ; iterator < 7 ; iterator++ )
       {
               printf("val[%d]: value is %d and address is %x", iterator, vector[iterator], &vector[iterator]);
       }

       pointer = &vector[0];
       /* for loop to print value and address of each element of array*/
       for ( int iterator = 0 ; iterator < 7 ; iterator++ )
       {
               printf("vector[%d]: value is %d and address is %x", iterator, *pointer, pointer);
               pointer++;
       }

       /* for loop to print value and address of each element of array*/
       for ( int iterator = 0 ; iterator < 7 ; iterator++ ){
               printf("val[%d]: value is %d and address is %x", iterator, *(pointer+iterator), (pointer+iterator));
       }
       return 0;
}
