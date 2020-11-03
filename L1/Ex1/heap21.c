/*
This is the code for task 3.1 "Free and reuse"
*/
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

char global[] = "This is a global sring";
const int read_only = 12345;

int main() {
	int pid = getpid();
    
	char *heap = malloc(20);
    *heap = 0x61;

    printf("heap pointing to: 0x%x\n", *heap);
    
    free(heap);
   
    char *foo = malloc(20);
    *foo = 0x62;
    printf("foo pointing to: 0x%x\n", *foo);
    /* danger ahead*/
    //free(heap);
    *heap = 0x63;
    printf("or is it pointing to: 0x%x\n", *foo);

	return 0;

    
}