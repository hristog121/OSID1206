#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
    int pid = fork();

    if (pid == 0) {
    execlp("ls", "ls", NULL);
    printf("This will only happen if exec fails\n");
    } else {
    wait(NULL);
    printf("We are done\n");
    }
    return 0;
}