#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h> // we need this for the 'wait'
#include <string.h> // we need this for the 'strdup'

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
        char *myargs[3];
        // Instead if taking args from stdin
        myargs[0] = strdup("wc");   // programe: "wc" (WordCount)
        myargs[1] = strdup("p3.c"); // argument: file to count
        myargs[2] = NULL;           // marks end of array
        execvp (myargs[0], myargs); // this runs wordcount
        printf("This shoudn't print out");
    } else {
        int rc_wait = wait(NULL);
        // parent goes down this path (main)
        printf("Hello, I am parrent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int) getpid());
    }
    return 0;
}