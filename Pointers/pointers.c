#include <stdio.h>

int main(){
       int var = 10;
       int *pointer;
       pointer = &var; // pointer receives Address of var

       printf ( "\n Address of var is: %x", &var);
       printf ( "\n Address of var is: %x", pointer);

       /* Note I have used %u for p's value as it should be an address*/
       printf ( "\n Address of pointer p is: %x", &pointer);
       printf( "\n Value of pointer p is: %x", pointer);

       printf ( "\n Value of var is: %d", var);
       printf ( "\n Value of var is: %d", *pointer);
       printf ( "\n Value of var is: %d", *( &var));
}
