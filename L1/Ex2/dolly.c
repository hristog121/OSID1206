//#include <cstdlib.h>
//#include <cstddef>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(){
    int pid;
    int x = 123;
    pid = fork();

    //printf("This is the first pid = %d\n", pid);
    if (pid == 0) {
       printf("Child: x is %d\n",x);
        printf("Child: x is %d and the address is 0x%p\n", x, &x);

       x = 42;
       printf("Child: x is %d\n",x);
               printf("Child: x is %d and the address is 0x%p\n", x, &x);


    } else  {
        printf("Mother: x is %d\n",x);
        x = 13;
        sleep(1);
        printf("Mother: x is %d and the address is 0x%p\n", x, &x);
        printf("Mother: x is %d\n",x);
        wait(NULL);
    }

    //printf("That's the end (%d)\n", getpid());
    return 0;
}