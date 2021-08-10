/*
* Write a program that prints out the ordinal description of the (assumed to be 
  numerical) arguments supplied to the program. For example:

prompt> ./ordinal 1 6 11 12 21 22 23
1st
6th
11th
12th
21st
22nd
23rd
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

void ordinal(int n) {
    char *suffix;
    switch (n % 10)
    {
    case 1:
        suffix = "st";
        break;
    case 2:
        suffix = "nd";
        break;
    case 3:
        suffix = "rd";
        break;
    default:
        suffix = "th";
        break;
    }
    if (n % 100 > 10 && n % 100 < 20) {
        suffix = "th";
    }
    printf("%d%s\n", n, suffix);
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Need one or more numbers to convert\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 1; i < argc; i++)
    {
        ordinal(atoi(argv[i]));
    }
    
    return 0;
}
