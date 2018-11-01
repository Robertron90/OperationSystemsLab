#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/mman.h>


int main() {
    char *given_text = "This is a nice day";
    int string_length = strlen(given_text);
    int sizer;
    void *point;
    sizer = open("ex1.txt", O_RDWR | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    lseek(sizer, string_length + 1, SEEK_SET);
    write(sizer, "", 1);
    point = mmap(NULL, string_length, PROT_WRITE | PROT_READ, MAP_SHARED, sizer, 0);
    memcpy(point, given_text, string_length);
    return 0;
}