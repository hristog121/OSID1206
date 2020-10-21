#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    printf("Hello world (pid:%d)\n", (int) getpid());
    int rc = fork();
    if (rc < 0) {
        // fork failed
        fprintf(stderr, "Fork FAILED\n");
        exit(1);
    } else if (rc == 0){
        // chuld (new process)
        printf("Hello, I am child (pid:%d)\n", (int) getpid());
    } else {
        // parent goes down this path (main)
        printf("Hello, I am parrent of %d (pid:%d)\n", rc, (int) getpid());
    }
    return 0;
}