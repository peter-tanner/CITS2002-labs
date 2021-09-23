
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

// the dest string must have enough space for the result.  If dest is not large
// enough, program behavior is unpredictable
char *strcat_p(char *dest, char *src)
{
    char *return_ptr = dest;
    dest += strlen(src);
    while (*src != '\0')
    {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return return_ptr;
}

int strncmp_p(char *s1, char *s2, size_t n)
{
    size_t i = 0;
    while ( (*s1 != '\0' || *s2 != '\0') && i < n ) {
        if (*s1 != *s2) {
            return *s1 - *s2;
        }
        s1++;
        s2++;
        i++;
    }
    return 0;
}

int strcmp_p(char *s1, char *s2)
{
    return strncmp_p(s1, s2, SIZE_MAX);
}

char *strchr_p(char *s, int c)
{
    while (*s != '\0') {
        if (*s == c) {
            return s;
        }
        s++;
    }
    return NULL;
}

char *strrchr_p(char *s, int c)
{
    char *s_ = *s + strlen(s) - 1;
    while (s_ >= s) {
        if (*s == c) {
            return s;
        }
        s--;
    }
    return NULL;
}

char *strpbrk_p(char *s, char *accept)
{
    size_t accept_len   = strlen(accept);
    while (*s != '\0') {
        for (char *c = accept; c < accept+accept_len; c++) {
            if (*s == *c) {
                return s;
            }
        }
    }
    return NULL;
}

bool __substring_match__(char *haystack_start, char *needle)
{
    while (*needle != '\0') {
        if (*haystack_start != *needle) {
            return false;
        }
        haystack_start++;
        needle++;
    }
    return true;
}

char *strstr_p(char *haystack, char *needle)
{
    while (*haystack != '\0') {
        if (__substring_match__(haystack,needle)) {
            return haystack;
        }
        haystack++;
    }
    return NULL;
}
