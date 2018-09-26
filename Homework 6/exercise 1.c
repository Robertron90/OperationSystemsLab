#include <stdio.h>

int main()
{
char *s1 = "Hello!\n";

char s2[100];

int fds[2];

pipe(fds);

write(fds[1], s1, 8);

read(fds[0], s2, 8);

printf("%s", s2);

}

