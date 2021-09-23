/*
* Write a function named money that accepts a single integer parameter that 
  represents a total number of cents, and breaks the total down into its numbers 
  of dollars and cents. Your function should calculate the number of dollars, 
  and the number of "left-over" cents, and provide these to its calling function 
  through its parameters. For example, a value of 524 should be "returned" as 5
  dollars and 24 cents.
* Your function should have the prototype:
    void money(int total, int *dollars, int *cents);
* and be called as:
    money(524, &dollars, &cents);
*/

#include <stdlib.h>
#include <stdio.h>

void money(int total, int *dollars, int *cents)
{
    *dollars = total/100;
    *cents = total % 100;
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        fprintf(stderr, "Usage: money [INT CENTS]\n");
        exit(EXIT_FAILURE);
    }
    
    int dollars;
    int cents;
    money(atoi(argv[1]), &dollars, &cents);
    printf("%i dollars, %i cents.\n", dollars, cents);
    exit(EXIT_SUCCESS);
}
