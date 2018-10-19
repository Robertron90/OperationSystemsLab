/* Think about how you will emulate clock ticks.
 There are several possible ways:
 1. More realistic way: emulate ticks in a separate thread and call update_counters() periodically from this thread
 2. Less realistic way: calculate time between touch_page() calls and divide it by some small value (10 milliseconds). This way you will be able to get the number of ticks and adjust all the frames several times
 */

#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define DEFAULT_PAGES_NUM 100

typedef struct page {
    bool ref;
    int number;
    unsigned long long age;
} Page;

int pagenum = DEFAULT_PAGES_NUM;

/* mem_pages: pages in memory
   ref: referenced page number
   used_pages: number of existing pages
 
   Returns: hit or miss */
bool touch_page(Page *mem_pages, int ref, int *used_pages) {
    
    /* Return value */
    bool result = false;
    
    /* If page is present, update its R bit */
    
    /* Otherwise, put page into a free page frame or evict one page and put a new page instead */
    
    return result;
}

/* mem_pages: pages in memory
   used_pages: number of existing pages 
 
   Returns: nothing */
void update_counters(Page *mem_pages, int used_pages) {
    
    /* Scan through pages and update counters according to their R bits */
    /* Hint: use bitwise AND(&) OR(|) and shift(>>) to work with bits */
    
}

int main(int argc, char ** argv)
{
    int hits = 0, faults = 0;
    
    if (argc >= 2)
        pagenum = atoi(argv[1]);
    
    Page *page_arr = (Page *)malloc(pagenum * sizeof(Page));
    FILE *f = fopen("./input.txt", "r");
    
    while(fscanf(fr, "%d", &reference) > 0) {
        /* Call touch_page() here */
    }
    
    fclose(f);
    
    printf("Hit/miss ratio: %d:%d\n", hits, faults);
    return EXIT_SUCCESS;
}
