#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler (int signo) {
  if (signo == 10) {
    printf("\nI got SIGUSR1\n");
  } else if (signo == 9) {
    printf("\nI got SIGKILL\n");
  } else if (signo == 19) {
    printf("\nI got SIGSTOP\n");
  }
  exit(0);
}

int main (void) {
  signal(SIGUSR1, sig_handler);
  signal(SIGSTOP, sig_handler);
  signal(SIGKILL, sig_handler);
  while (1)  sleep (10);
  return 0;
}
