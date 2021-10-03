#include <stdlib.h>
#include <stdio.h>
#include "hashtable.h"

void print_list(LIST *list)
{
    int content = 0;
    while (list != NULL) {
        printf("%s => ",list->item);
        list = list->next;
    }
    putchar('\n');
}

void print_hashtable(HASHTABLE *hashtable)
{
    for (size_t i = 0; i < HASHTABLE_N_BUCKETS; i++) {
        if (hashtable->buckets[i] != NULL) {
            printf("%lu\t|\t",i);
            print_list(hashtable->buckets[i]);
        }
    }
}

int main(int argc, char const *argv[])
{
    LIST *list = NEW_LIST();
    ADD_TO_LIST(list, "World");
    ADD_TO_LIST(list, "Hello");
    print_list(list);
    printf("%d\n", find_in_list(list,"Hello"));
    printf("%d\n", find_in_list(list,"Hell"));

    HASHTABLE *hashtable = new_hashtable();
    add_string_to_hashtable(hashtable, "Hello");
    printf("%d\n", find_string_in_hashtable(hashtable,"Hell"));
    printf("%d\n", find_string_in_hashtable(hashtable,"World"));
    add_string_to_hashtable(hashtable, "World");
    printf("%d\n", find_string_in_hashtable(hashtable,"World"));
    print_hashtable(hashtable);
    return 0;
}