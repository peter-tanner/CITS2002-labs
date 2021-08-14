/*
* Write a function named my_strcmp() to determine if one string is
  (lexicographically, or alphabetically) less than, equal to, or greater than
  another string. Your function should accept the two character arrays as its
  arguments, and return either: -1 if the first string is less than the second
  string, 0 if the two strings are equal, or 1 if the first string is greater
  than the second string.
* Call your function from the main() function with the code:
  my_strcmp(argv[1], argv[2]).
*/

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

// Note that in many programming languages, uppercase characters have a lower
// value than lowercase characters.
int alphabet_index(char c) {
    if (isalpha(c))
    {
        if (isupper(c)) {
            return c - 'A';
        } else {
            return c - 'a' + 26;
        }
    }
    return 0;
}

int my_strcmp(char s1[], char s2[]) {
    int s1_len = strlen(s1);
    int s2_len = strlen(s2);
    size_t i = 0;
    while (s1[i] != '\0' && s2[i] != '\0')
    {
        int s1_idx = alphabet_index(s1[i]);
        int s2_idx = alphabet_index(s2[i]);
        if (s1_idx > s2_idx) {
            return 1;
        } else if (s1_idx < s2_idx) {
            return -1;
        }
        i++;
    }
    if (s1_len > s2_len) {
        return 1;
    } else if (s2_len > s1_len) {
        return -1;
    }
    return 0;
}

int main(int argc, char *argv[])
{
    if (argc != 3)
    {
        printf("Only two strings for comparison allowed\n");
        exit(EXIT_FAILURE);
    }
    printf("%d\n",my_strcmp(argv[1], argv[2]));
    return 0;
}
