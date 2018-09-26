#include <stdio.h>

int main(void)
{
char *s1 = "Hellp!\n";
char s2[100];
int fds[2];
pipe(fds);

int status = fork();

if (status>0) {
  write(fds[1], s1, 8);
} else if (status==0) {
  read(fds[0], s2, 8);
  printf("%s", s2);
} else {
  printf("ERROR\n");
}

return 0;
}
