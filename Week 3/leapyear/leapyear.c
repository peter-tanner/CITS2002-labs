/*
* A year is a leap year if it is divisible by 400, or if it is divisible by 4 
  and not divisible by 100. For example - 1996, 2000, and 2012 were leap years,
  while 1899, 1900, and 2013 were not. Write a program that prints whether a
  year, supplied as a command-line argument, is a leap year or not.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        printf("No input provided! Provide one or more years to check\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 1; i < argc; i++)
    {
        int year = atoi(argv[i]);
        char *value = "No";
        if (isLeapYear(year))
        {
            value = "Yes";
        }
        printf("%d => %s\n",year,value);
    }
    exit(EXIT_SUCCESS);
    return 0;
}
