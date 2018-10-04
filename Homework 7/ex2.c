#include <stdio.h>
#include <stdlib.h>

int main(void) {
int n, i;
scanf("%d", &n);
int *a = (int*)malloc(n * sizeof(int));
for (i = 0; i < n; i++) a[i] = i;
for (i = 0; i < n; i++) printf("%d ", a[i]);
printf("\n");
//for (i = 0; i < n; i++) free(a[i]); - it makes segmentation fault
free(a);
return 0;
}
