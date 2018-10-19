#include <errno.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>

#define TICK_TIME 0.02  //20 msecs
#define PAGES_NUM 100

struct page {
    bool ref;
    int number;
    unsigned long long age;
};

clock_t last_time;
//struct page null_page = {.number = -1, .age = 0};
int pagenum = PAGES_NUM;

bool touch_page(struct page *page_arr, int ref, int *pages_used) {
    
    // returned value
    bool result = false;
    clock_t curr_time = clock();
    double cpu_time_used = ((double) (curr_time - last_time)) / CLOCKS_PER_SEC;
    
    // how far we should shift age to the right
    int shift = cpu_time_used / TICK_TIME;
    int i;
    
    // Shifting itself
    while (shift >= 1) {
        curr_time = clock() - cpu_time_used + shift * TICK_TIME;
        for(i = 0; i < *pages_used; i++) {
            page_arr[i].age >>= 1;
            
            if (page_arr[i].ref)
                page_arr[i].age |= ~(~0ull >> 1);
            else
                page_arr[i].age &= (~0ull >> 1);
            page_arr[i].ref = false;
        }
        shift--;
    }
    
    bool touched = false;
    
    // If page is presented in pageframe
    for(i = 0; i < *pages_used; i++) {
        if (page_arr[i].number == ref) {
            page_arr[i].ref = true;
            touched = true;
        }
    }
    
    // otherwie
    if(!touched) {
        result = true;
        
        // Either add page
        if (*pages_used < pagenum) {
            page_arr[*pages_used] = (struct page){.ref = true, .number = ref, .age = ~(~0ull >> 1)};
            (*pages_used)++;
        }
        // The less age the better is candidate to evict
        for (i = 0; i < *pages_used; i++) {
            if (page_arr[i].age < page_arr[best_i].age)
                best_i = i;
        }
        page_arr[best_i] = (struct page){.ref = true, .number = ref, .age = ~(~0ull >> 1)};
    }
}

return result;
}


// A big assumtion here is that references to memory are much more frequent than 1 in 20msecs, so we are able to update age of pages during reference
int main(int argc, char ** argv)
{
    // how many pages are currently in use
    int curr_page_used = 0;
    if (argc >= 2)
        pagenum = atoi(argv[1]);
    
    struct page * page_arr = (struct page *)malloc(pagenum * sizeof(struct page));
    
    FILE *fr = fopen("./input.txt", "r");
    FILE *fw = fopen("./output.txt", "w");
    
    int reference;
    int faults = 0;
    int hits = 0;
    
    // for appropriate simulating of OS ticks
    last_time = clock();
    
    while(fscanf(fr, "%d", &reference) > 0) {
        printf("%d: %d\n", hits, reference);
        if (touch_page(page_arr, reference, &curr_page_used)) {
            faults++;
            fprintf(fw, "miss\n");
        }
        hits++;
    }
    printf("Hits: %d", hits);
    hits -= faults;
    
    printf("Hit/miss ratio: %f\n", (float)hits/(float)faults);
    
    fclose(fr);
    fclose(fw);
    
    return 0;
}
