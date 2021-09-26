
// SOLUTION 1 - DYNAMIC MEMORY WITH realloc()

/*
* 1. Write a C program, named listints, which will print the integers requested
  via a single command-line argument. The list of integers is to appear in 
  strictly increasing order, with each requested integer appearing once and only
  once (even if duplicated in the request).
* Simple examples of its use are:
    prompt> listints 8
    will print:  8

    prompt> listints 3,5,9
    will print:  3 5 9

    prompt> listints 1-10
    will print:  1 2 3 4 5 6 7 8 9 10

    prompt> listints 1-10,6
    will print:  1 2 3 4 5 6 7 8 9 10
* 🌶 🌶 And some much more difficult examples:
    prompt> listints 2000-2020,40-50
    prompt> listints 1-10,2010-2020,3000000-3000010
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define RANGE_SEP '-'
#define LIST_SEP ','

typedef struct {
    long start;
    long end;
} RANGE;

int sort_range(const void *v1, const void *v2)
{
    RANGE* range_1 = (RANGE*)v1;
    RANGE* range_2 = (RANGE*)v2;
    return (range_1->start - range_2->start);
}

char *substr(char *str, char *end)
{
    size_t length = end - str;
    char *substring = malloc(length + 1);
    strncpy(substring,str,length);
    *(substring+length) = '\0';
    return substring;
}

RANGE convert_to_range(char *range_str)
{
    char *sep = strchr(range_str, RANGE_SEP);
    RANGE range;
    if (sep != NULL) {
        sep++;
        range.start = atol(substr(range_str,sep-1));
        range.end   = atol(sep);
    } else {
        range.start = atol(range_str);
        range.end = range.start;
    }

    if (range.end < range.start) {
        fprintf(stderr, "ERROR: End range must be before start range.\n");
        exit(EXIT_FAILURE);
    }
    return range;
}

RANGE *split_ranges(char *list, size_t *list_size)
{
    size_t range_list_max = 1;
    RANGE *range_list = malloc(sizeof(RANGE));
    if (range_list == NULL) {
        fprintf(stderr, "ERROR: Couldn't allocate memory.\n");
        exit(EXIT_FAILURE);
    }
    RANGE *range = range_list;

    char *end;
    while ( (end = strchr(list, LIST_SEP)) != NULL ) {
        // EXTRACT ONE RANGE.
        char *element = substr(list, end);

        // EXPAND MEMORY
        if (*list_size >= range_list_max) {
            range_list_max *= 2;
            range_list = realloc(range_list, range_list_max * sizeof(RANGE));
            if (range_list == NULL) {
                fprintf(stderr, "ERROR: Couldn't allocate memory.\n");
                exit(EXIT_FAILURE);
            }
            range = range_list + *list_size;
        }

        *range = convert_to_range(element);
        range++;
        
        *list_size = (size_t)(range - range_list);
        list = end + 1;
    }

    qsort(range_list, *list_size, sizeof(RANGE), sort_range);    
    return range_list;
}

long max(long v1, long v2)
{
    if (v1 < v2) {
        return v2;
    }
    return v1;
}

void print_ranges(RANGE *range_list, size_t list_size)
{
    long max_number = 0;
    for (size_t i = 0; i < list_size; i++) {
        RANGE *range = range_list + i;
        for (size_t n = max(range->start, max_number); n <= range->end; n++)
        {
            max_number = n+1;
            printf("%lu ",n);
        }
    }
    putchar('\n');
}

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: listints [INTEGER RANGE]\n");
        exit(EXIT_FAILURE);
    }
    
    // STRING WITH A ',' APPENDED TO MAKE THE SPLIT WORK.
    char *ext_str = malloc(strlen(argv[1]) + 1);
    strcpy(ext_str,argv[1]);
    strcat(ext_str,",");

    size_t list_size = 0;
    RANGE *range_list = split_ranges(ext_str, &list_size);
    print_ranges(range_list, list_size);
    return 0;
}
