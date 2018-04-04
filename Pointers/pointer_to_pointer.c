#include <stdio.h>

int main(){
       int num = 123;

       /*Pointer for num*/
       int *pr2;

       /*pointer for pointer pr2*/
       int **pr1;

       /* I’m reading the address of variable num and
       * storing it in pointer pr2*/
       pr2 = &num;

       /* storing the address of pointer pr2 into another pointer pr1*/
       pr1 = &pr2;

       /* Possible ways to find value of variable num*/
       printf("\n Value of num is: %d", num);
       printf("\n Value of num using pr2 is: %d", *pr2);
       printf("\n Value of num using pr1 is: %d", **pr1);

       /*Possible ways to find address of num*/
       printf("\n Address of num is: %x", &num);
       printf("\n Address of num using pr2 is: %x", pr2);
       printf("\n Address of num using pr1 is: %x", *pr1);

       /*Find value of pointer*/
       printf("\n Value of Pointer pr2 is: %x", pr2);
       printf("\n Value of Pointer pr2 using pr1 is: %x", *pr1);

       /*Ways to find address of pointer pr2*/
       printf("\n Address of Pointer pr2 is:%x", &pr2);
       printf("\n Address of Pointer pr2 using pr1 is:%x", *pr1);

       /*Pr1 pointer value and address*/
       printf("\n Value of Pointer pr1 is:%x",pr1);
       printf("\n Address of Pointer pr1 is:%x",&pr1);

       return 0;
}
