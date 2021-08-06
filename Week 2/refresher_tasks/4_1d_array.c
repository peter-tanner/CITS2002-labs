/*
* 4 [integer arithmetic, 1D array] Revise (or learn) how to generate a 
* non-negative random integer in your chosen programming language. Saturday 
* Lotto involves drawing 6 unique numbers, between 1 and 45. Write a simple 
* program to choose and display your 6 lucky numbers.
*/

#include <time.h>
#include <stdlib.h>
#include <stdio.h>

#define NUMBERS 6
#define LOWER 1
#define UPPER 45
#define RANGE UPPER-LOWER+1


int main(void)
{
    srand(time(NULL)); // Seed rng
    int luckyNumbers[NUMBERS];
    for (size_t i = 0; i < NUMBERS; i++)
    {
        luckyNumbers[i] = rand() % RANGE + LOWER;
    }

    // Could've printf in the last loop but seems like the exercise wants 
    // a 1D array.

    printf("Lucky numbers ");
    for (size_t i = 0; i < NUMBERS; i++)
    {
        printf("%d ",luckyNumbers[i]);
    }
    printf("\n");
    
    return 0;
}

