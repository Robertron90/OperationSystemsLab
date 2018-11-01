#include <stdio.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/types.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>


int main() {

  int source1 = open("ex1.txt", O_RDONLY);
  int end_of_the_line = open("ex1.memcpy.txt", O_RDWR | O_CREAT, S_IWRITE | S_IREAD);

  struct stat super_stat;
  fstat(source1, &super_stat);
  size_t tamfile = (size_t) super_stat.st_size;

  char *source_register = mmap((void*) NULL, tamfile, PROT_READ, MAP_PRIVATE, source1, 0);
  ftruncate(end_of_the_line, tamfile);

  char *end_register = mmap((void*) NULL, tamfile, PROT_READ | PROT_WRITE, MAP_SHARED, end_of_the_line, 0);
  memcpy(end_register, source_register, tamfile);
  
  close(source1);
  close(end_of_the_line);

  return 0;
}