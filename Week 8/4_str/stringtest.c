
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "arrays.h"
#include "pointers.h"

void print_cmp(char s1[], char s2[], int n)
{
    if (n == 0) {
        printf("strcmp(%s,%s) = %i\n", s1, s2, strcmp(s1, s2));
        printf("\tstrcmp_a(%s,%s) = %i\n", s1, s2, strcmp_a(s1, s2));
    } else {
        printf("strncmp(%s,%s,%i) = %i\n", s1, s2, n, strncmp(s1, s2, n));
        printf("\tstrncmp_a(%s,%s,%i) = %i\n", s1, s2, n, strncmp_a(s1, s2, n));
    }
}

void print_chr(char str[], char c)
{
    char *strchr_ptr = strchr(str, c);
    printf("strchr(): V %c; PTR %lu\n", *strchr_ptr, strchr_ptr-&str[0]);
    strchr_ptr = strchr_a(str, c);
    printf("\tstrchr_a(): V %c; PTR %lu\n", *strchr_ptr, strchr_ptr-&str[0]);
    strchr_ptr = strrchr(str, c);
    printf("strrchr(): V %c; PTR %lu\n", *strchr_ptr, strchr_ptr-&str[0]);
    strchr_ptr = strrchr_a(str, c);
    printf("\tstrrchr_a(): V %c; PTR %lu\n", *strchr_ptr, strchr_ptr-&str[0]);
}

void print_pbrk(char str[], char accept[])
{
    char *strpbrk_ptr = strpbrk(str, accept);
    printf("strpbrk(): V %c; PTR %lu\n", *strpbrk_ptr, strpbrk_ptr-&str[0]);
    strpbrk_ptr = strpbrk_a(str, accept);
    printf("\tstrpbrk_a(): V %c; PTR %lu\n", *strpbrk_ptr, strpbrk_ptr-&str[0]);
}

void print_strstr(char haystack[], char needle[])
{
    char *strstr_ptr = strstr(haystack, needle);
    printf("strstr(): PTR %lu\n", strstr_ptr-&haystack[0]);
    strstr_ptr = strstr_a(haystack, needle);
    printf("\tstrstr_a(): PTR %lu\n", strstr_ptr-&haystack[0]);
}

int main(int argc, char const *argv[])
{
    char string_1[40] = "Hello ";
    char string_2[] = "World!";
    
    // TEST strcat()
    char *dest = strcat_a(string_1, string_2);
    printf("%s\n", dest);

    // TEST strcmp()
    print_cmp("ABC",    "ABC",  0);
    print_cmp("ABCD",   "AB",   0);
    print_cmp("AB",     "ABC",  0);
    print_cmp("ABA",    "ABZ",  0);
    print_cmp("ABJ",    "ABC",  0);

    // TEST strncmp()
    print_cmp("ABC",    "AB",   3);
    print_cmp("ABC",    "AB",   2);

    // TEST strchr(), strrchr()
    char string_3[] = "Sussy susser";
    print_chr(string_3,'u');

    // TEST strpbrk()
    print_pbrk(string_3,"yer");
    print_pbrk(string_3,"s");
    
    // TEST strstr()
    print_strstr(string_3,"sus");
    print_strstr(string_3,"ss");
    return 0;
}
