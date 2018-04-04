#include <stdio.h>

int main(){
   int vector[7] = { 11, 22, 33, 44, 55, 66, 77 } ;
   int iterator = 0;

   /* for loop to print value and address of each element of array*/
   for ( int iterator = 0 ; iterator < 7 ; iterator++ )
   {
         printf("val[%d]: value is %d and address is %u", iterator, vector[iterator], &vector[iterator]);
   }
   
   return 0;
}
