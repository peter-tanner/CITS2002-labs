/*
* A computer password is often consider "safe" (i.e. hard to guess) if it
  contains a mixture of uppercase and lowercase characters and digits. Write a
  function named isSafe() to determine if a potential password (a string) has at
  least two uppercase characters, two lowercase characters, and two digits. Your
  function should take a single character array as its argument and return a
  Boolean value to indicate whether the password is considered safe or not.
* See the online documentation (man pages) for help with the isalpha(),
  islower(), and isupper() functions. Include the appropriate header file
  <ctype.h> into your program.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

bool isSafe(char const passwd[]) {
    size_t i = 0;
    unsigned int uppercase = 0;
    unsigned int lowercase = 0;
    unsigned int digit = 0;
    while (passwd[i] != '\0')
    {
        if (isalpha(passwd[i])) {
            if (isupper(passwd[i])) {
                uppercase++;
            } else {
                lowercase++;
            }
        } else {
            digit++;    //Assume non-alphabet characters as digits
        }        
        i++;
    }
    return uppercase > 1 && lowercase > 1 && digit > 1;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        if (isSafe(argv[i])) {
            printf("safe ");
        } else {
            printf("unsafe ");
        }
    }
    printf("\n");
    exit(EXIT_SUCCESS);
    return 0;
}
