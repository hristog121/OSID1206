#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int pid = fork();
    if(pid == 0){
        int child = getpid();
        printf("Child: session %d\n", getsid(child));
    } else {
    int parent = getpid();
    printf("Parent: session %d\n", getsid(parent));
    }
    return 0;
}