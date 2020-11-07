//#include <cstdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid = fork();
    //printf("This is the first pid = %d\n", pid);
    if (pid == 0) {
       printf("Check the status\n");
       sleep(10);
       printf("And again\n");
       return 42;
    } else  {
        sleep(20);
        int res;
        wait(&res);
        printf("The result was %d\n", WEXITSTATUS(res));
        printf("And again\n");
        sleep(10);
    }

    return 0;
}