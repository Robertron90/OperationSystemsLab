#include <unistd.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <memory.h>
#include <stdlib.h>


int main(int argc, char **argv) {

    FILE *folder = fopen("/dev/random", "r");

    FILE *output = fopen("ex1.txt", "w");

    char letsSeewhatComes[20];

    int alreadySeen = 0;

    while (alreadySeen < 20) {

        ssize_t finalOutput = fread(letsSeewhatComes + alreadySeen, sizeof(char), 1, folder);

        if (finalOutput < 0) {

            printf("Error");

        }

        alreadySeen++;

    }

    printf("%s", letsSeewhatComes);

    fprintf(output, "%s", letsSeewhatComes);

    return 0;

}