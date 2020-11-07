//#include <cstdlib.h>
//#include <cstddef>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  int pid;

  pid = fork();

  // printf("This is the first pid = %d\n", pid);
  if (pid == 0) {
    int child = getpid();
    printf("Child: parent %d, group %d\n", getppid(), getpgid(child));
    sleep(4);
    printf("Child: parent %d, group %d\n", getppid(), getpgid(child));
    sleep(4);
    printf("Child: parent %d, group %d\n", getppid(), getpgid(child));

  } else {
    int parent = getpid();
    printf("Parent: parent %d, group %d\n", getppid(), getpgid(parent));
    sleep(2);
    int zero = 0;
    int i = 3 / zero;
  }

  // printf("That's the end (%d)\n", getpid());
  return 0;
}