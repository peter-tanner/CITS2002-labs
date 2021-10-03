#include "hashtable.h"

/*
*   LIST DATATYPE
*/

bool find_in_list(LIST *list, char *string)
{
    while (list != NULL) {
        if (strcmp(string, list->item) == 0) {
            return true;
        }
        list = list->next;
    }
    return false;
}

LIST *add_to_list(LIST *list, char *string)
{
    if (find_in_list(list,string)) {
        return list;
    }

    char *string_copy = strdup(string);
    if (string_copy == NULL) {
        fprintf(stderr, "strdup failed.\n");
        exit(EXIT_FAILURE);
    }

    LIST *new_node = malloc(sizeof(LIST));
    if (new_node == NULL) {
        fprintf(stderr, "malloc failed.\n");
        exit(EXIT_FAILURE);
    }
    new_node->item = string_copy;
    new_node->next = list;
    return new_node;
}

#define ADD_TO_LIST(list,string) ((list) = add_to_list((list),(string)))
#define NEW_LIST() (NULL)

/*
*   HASHTABLE DATATYPE
*/

HASHTABLE *new_hashtable()
{
    HASHTABLE *hashtable = malloc( sizeof(HASHTABLE) );
    return hashtable;
}

void add_string_to_hashtable(HASHTABLE *hashtable, char *string)
{
    size_t index = hash_string(string) % HASHTABLE_N_BUCKETS;
    ADD_TO_LIST(hashtable->buckets[index], string);
}

bool find_string_in_hashtable(HASHTABLE *hashtable, char *string)
{
    size_t index = hash_string(string) % HASHTABLE_N_BUCKETS;
    return find_in_list(hashtable->buckets[index], string);
}