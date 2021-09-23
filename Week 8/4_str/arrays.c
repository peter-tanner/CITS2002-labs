
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdint.h>

#include "arrays.h"

// the dest string must have enough space for the result.  If dest is not large
// enough, program behavior is unpredictable
char *strcat_a(char dest[], char src[])
{
    size_t src_len     = strlen(src);
    size_t dest_len    = strlen(dest);
    for (size_t i = 0; i < src_len; i++) {
        dest[i + dest_len] = src[i];
    }
    dest[src_len + dest_len] = '\0';
    return dest;
}

int strncmp_a(char s1[], char s2[], size_t n)
{
    size_t i = 0;
    while ( (s1[i] != '\0' || s2[i] != '\0') && i < n ) {
        if (s1[i] != s2[i]) {
            return s1[i] - s2[i];
        }
        i++;
    }
    return 0;
}

int strcmp_a(char s1[], char s2[])
{
    return strncmp_a(s1, s2, SIZE_MAX);
}

char *strchr_a(char s[], int c)
{
    size_t str_len = strlen(s);
    for (size_t i = 0; i < str_len; i++) {
        if (s[i] == c) {
            return &s[i];
        }       
    }
    return NULL;
}

char *strrchr_a(char s[], int c)
{
    for (size_t i = strlen(s)-1; i >= 0; i--) {
        if (s[i] == c) {
            return &s[i];
        }       
    }
    return NULL;
}

char *strpbrk_a(char s[], char accept[])
{
    size_t i = 0;
    size_t accept_len = strlen(accept);
    while (s[i] != '\0') {
        for (size_t j = 0; j < accept_len; j++) {
            if (s[i] == accept[j]) {
                return &s[i];
            }
        }
        i++;
    }
    return NULL;
}

bool __substring_match__(char str[], char substr[], size_t start)
{
    size_t i = 0;
    while (substr[i] != '\0') {
        if (str[i+start] != substr[i]) {
            return false;
        }
        i++;
    }
    return true;
}

char *strstr_a(char haystack[], char needle[])
{
    size_t i = 0;
    while (haystack[i] != '\0') {
        if (__substring_match__(haystack,needle,i)) {
            return &haystack[i];
        }
        i++;
    }
    return NULL;
}
