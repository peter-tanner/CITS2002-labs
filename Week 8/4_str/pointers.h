#ifndef _STR_POINTERS_H
#define _STR_POINTERS_H

extern char *strcat_p(char *dest, char *src)

extern int strncmp_p(char *s1, char *s2, size_t n)

extern int strcmp_p(char *s1, char *s2)

extern char *strchr_p(char *s, int c)

extern char *strrchr_p(char *s, int c)

extern char *strpbrk_p(char *s, char *accept)

extern char *strstr_p(char *haystack, char *needle)

#endif