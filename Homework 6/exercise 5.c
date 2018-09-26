#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler (int signo) {
  if (signo == SIGTERM) {
    printf("\nI got SIGTERM\n");
  }
  exit(0);
}

int main (void) {
  signal(SIGTERM, sig_handler);
  int pid;
  pid = fork();
  if (pid > 0) {
	  sleep(10);
	  kill(0, SIGTERM);
  } else if (pid == 0) {
	  while (1) {
		  sleep(1);
		  printf("I'm alive!\n");
	  }
  } else {
	  printf("\nERROR\n");  
  }
  return 0;
}
