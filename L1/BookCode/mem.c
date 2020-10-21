#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "common.h"

int main(int argc, char *argv[]){
    int *p = malloc(sizeof(int));   //a1 - alocates memory
    assert(p != NULL);
    printf("(%d) address pointed to by p: %p\n", getpid(),p);   //a2 - prints out the address of the memory 
    *p = 0; //a3 - stores the value '0' in the newly alocated memory slot
    while(1){
        Spin(1);    //Delay for 1 second
        *p = *p + 1; //Increment the value stored at 'p' by 1
        printf("(%d) p: %d\n", getpid(), *p);   //a4 - prints the pid (proccess identifier)
    }
    return 0;
}