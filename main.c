/* Laboratory II
*/
/* Exercise 1 
*/
#include <stdio.h>
#include<limits.h>
#include<float.h>
int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("%d\n%f\n%f", a, b, c);
    return 0;
}

#include <stdio.h>
#include<limits.h>
#include<float.h>

int main() {
    int a = INT_MAX;
    float b = FLT_MAX;
    double c = DBL_MAX;

    printf("%d\n%f\n%f", a, b, c);
    printf("\n%zu\n%zu\n%zu", sizeof(a), sizeof(b), sizeof(c));

    return 0;
}

/* Exercise 2
*/

#include <stdio.h>
 int main()
{
   char s[1000], r[1000];
   int begin, end, count = 0;
    printf("Input a string\n");
   gets(s);
 
   // Calculating string length
    while (s[count] != '\0')
      count++;
    end = count - 1;
    for (begin = 0; begin < count; begin++) {
      r[begin] = s[end];
      end--;
   }
 
   r[begin] = '\0';
 
   printf("%s\n", r);
   return 0;
}

/* Exercise 3
*/

#include <stdio.h>

int main() {
        int rows, star, spaces;
        int number_of_stars = 6;
        int number_of_rows = number_of_stars;

        for (rows=1; rows <= number_of_rows; rows++) {
                for (spaces=1; spaces <= number_of_stars; spaces++) {
                        printf(" ");
                }
                for (star=1; star <= rows; star++) {
                        printf("*");
                        printf(" ");
                }
                printf("\n");
                number_of_stars = number_of_stars - 1;
        }
        return 0;
}

/* Exercise 4
*/

#include <stdio.h>
 
int main()
{
   int x, y, temp;
 
   printf("Enter the value of x and y\n");
   scanf("%d%d", &x, &y);
 
   printf("Before Swapping\nx = %d\ny = %d\n",x,y);
 
   temp = x;
   x    = y;
   y    = temp;
 
   printf("After Swapping\nx = %d\ny = %d\n",x,y);
 
   return 0;
}


