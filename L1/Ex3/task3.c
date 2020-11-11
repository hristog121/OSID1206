
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>


void handler(int sig){
    printf("Signal %d was caught\n", sig);
    exit(1);
    return;
}

int not_so_good(){
    int x = 0;
    return 1 % x;
}

int main(){

    //Data structure
    struct sigaction sa;

    printf("OK, let's go - I'll catch my own error.\n");

    sa.sa_handler = handler;
    sa.sa_flags = 0;
    sigemptyset(&sa.sa_mask);

    /* Here we catch ...FPE signals */
    // If you get SIGFPE --> use sa to handle 
    sigaction(SIGFPE, &sa, NULL);


    // Call to not_so_good()
    not_so_good();

    printf("Will probably not write this.\n");
    return(0);
}

