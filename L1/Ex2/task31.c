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
        int child = getpid();
        printf("I am the child %d in group %d\n", child, getpgid(child));
    } else  {
        int parent = getpid();
        printf("I am the parent %d with group %d\n", parent, getpgid(parent));
        wait(NULL);

    }

    //printf("That's the end (%d)\n", getpid());
    return 0;
}