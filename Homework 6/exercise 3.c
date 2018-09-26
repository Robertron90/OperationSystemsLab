#include <stdio.h>
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>

void sig_handler (int signo) {
  if (signo == 2) {
    printf("\nI got SIGINT\n");
  }
  exit(0);
}

int main (void) {
  signal(SIGINT, sig_handler);
  while (1)  sleep (10);
  return 0;
}
