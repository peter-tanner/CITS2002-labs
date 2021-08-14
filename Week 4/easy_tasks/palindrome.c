/*
* A palindrome is a word that reads the same forwards as it does backwards. For
  example, the words noon and madam are palindromes. Write a function named
  isPalindrome() which determines if a string, supplied as the single character
  array argument to the function, is a palindrome or not, returning a Boolean.
  Use the strlen() function to determine the length of the argument string.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool isPalindrome(char const str[]) {
    int str_length = strlen(str);
    for (size_t i = 0; i < str_length/2; i++)
    {
        if (str[i] != str[str_length-i-1]) {
            return false;
        }
    }
    return true;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        if (isPalindrome(argv[i]))
        {
            printf("yes ");
        } else {
            printf("no ");
        }
    }
    printf("\n");
    exit(EXIT_SUCCESS);
    return 0;
}
