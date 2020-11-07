//#include <cstdlib.h>
//#include <cstddef>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid;
    
    pid = fork();

    //printf("This is the first pid = %d\n", pid);
    if (pid == 0) {
        printf("I am the child %d with parent %d\n", getpid(), getppid());
    } else  {
        printf("I am the parent %d with parent %d\n", getpid(), getppid());
        wait(NULL);

    }

    //printf("That's the end (%d)\n", getpid());
    return 0;
}