#ifndef _STR_ARRAYS_H
#define _STR_ARRAYS_H

extern char *strcat_a(char dest[], char src[]);

extern int strncmp_a(char s1[], char s2[], size_t n);

extern int strcmp_a(char s1[], char s2[]);

extern char *strchr_a(char s[], int c);

extern char *strrchr_a(char s[], int c);

extern char *strpbrk_a(char s[], char accept[]);

extern char *strstr_a(char haystack[], char needle[]);

#endif