#include <stdlib.h>
#include <stdio.h>

int* my_realloc(int* a, int old_size, int size) {
  if (size == 0) { free(a); return NULL; }
  if (a == NULL) return (int*)malloc(size);
  int i;
  int *b = (int*)malloc(size);
  int n = old_size;
  if (size < n) n = size;
  for (i = 0; i < n; i++) b[i] = a[i];
  return b;
}

int main(void) {
  printf("Enter original array size: ");
  int n1 = 0;
  scanf("%d", &n1);
  int *a1 = (int*)malloc(n1 * sizeof(int));
  int i;
  for (i = 0; i < n1; i++) {
    a1[i] = 100;
    printf("%d ", a1[i]);
  }
  printf("\nEnter new array size: ");
  int n2 = 0;
  scanf("%d",&n2);
  a1 = (int*)my_realloc(a1, n1 * sizeof(int), n2 * sizeof(int));
  //for (i = n1; i < n2; i++) a1[i] = 0;
  for (i = 0; i < n2; i++) printf("%d ", a1[i]);
  printf("\n");
  return 0;
}
