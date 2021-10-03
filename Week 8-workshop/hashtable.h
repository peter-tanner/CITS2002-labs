#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "hashstring.h"

#if defined(__linux__)
extern char *strdup(const char *);
#endif

#define HASHTABLE_N_BUCKETS 1000

typedef struct __list__ {
    char *item;
    struct __list__ *next;
} LIST;

typedef struct {
    LIST *buckets[HASHTABLE_N_BUCKETS];
} HASHTABLE;

extern bool find_in_list(LIST*, char*);

#define ADD_TO_LIST(list,string) ((list) = add_to_list((list),(string)))

#define NEW_LIST() (NULL)

extern HASHTABLE *new_hashtable();

extern void add_string_to_hashtable(HASHTABLE*, char*);

extern bool find_string_in_hashtable(HASHTABLE*, char*);
