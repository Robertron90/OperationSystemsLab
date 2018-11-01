#include <unistd.h>
#include <memory.h>
#include <stdio.h>
#include <stdlib.h>


int main(int argc, char **argv) {
    setvbuf(stdout, NULL, _IOLBF, 0);
    for (int i = 0; i < 5; ++i) {
        printf("H");
        sleep(1);
        printf("e");
        sleep(1);
        printf("l");
        sleep(1);
        printf("l");
        sleep(1);
        printf("o");
        sleep(1);
	printf("\n");
    }

    return 0;
}