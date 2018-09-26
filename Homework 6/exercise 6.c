#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

int main (void) {
  int pid1, pid2;
  pid1 = fork();
  if (pid1 > 0) {
    printf("Parent on\n");
    waitpid(pid2, 0, 0);
    printf("Parent off\n");
    exit(0);
  } else if (pid1 == 0) {
    pid2 = fork();
    if (pid2 == 0) {
      printf("Child #1 on \n");
      printf("Parent of child #1 is %d\nChild #1 sleeping", getppid()$
      waitpid(pid2, 0, 0);
	  printf("Child #1 off\n");
     exit(0);
    } else if (pid2 > 0) {
      printf("Child #2 ... \n");
      sleep(3);
      printf("gonna kill child #1\n");
      kill (pid2, SIGSTOP);
      printf("Child #2 off\n");
      exit(0);
    }
  }
  return 0;
}

