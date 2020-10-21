#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // we need this for the wait

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
        int rc_wait = wait(NULL);
        // parent goes down this path (main)
        printf("Hello, I am parrent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}