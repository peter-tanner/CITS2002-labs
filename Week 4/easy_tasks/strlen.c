/*
* Write a function named my_strlen() that calculates and returns the length of a
  string. Your function should take one argument, a character array that
  represents the string, and return an integer - the length of the string. The
  calling function (the main() function) should print the integer returned by
  your my_strlen() function.
* Test your function with some string constants and by passing to it some
  command-line arguments.
*/

#include <stdio.h>
#include <stdlib.h>

int my_strlen(char const str[]) {
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}

int main(int argc, char const *argv[])
{
    for (size_t i = 1; i < argc; i++)
    {
        printf("%d ", my_strlen(argv[i]));
    }
    printf("\n");
    return 0;
}
