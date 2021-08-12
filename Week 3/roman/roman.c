/*
* 🌶 🌶 Write a program that prints out all "roman numeral" equivalents of the 
 numbers between 1 and the single argument supplied to the program. Use the
 rules for writing Roman numerals, and the online calculator, from:
 Calculator Soup (just for the numerals I, V, X, L, C, D, and M).
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "numerals.c"

void arabic_to_roman(int n, struct numeral numerals[]) {
    int idx = 0;
    while (n > 0 && idx < NUMERAL_AMOUNT)
    {
        int value = numerals[idx].value;
        if ( (n-value) < 0 )
        {
            idx++;
        } else {
            n -= value;
            numerals[idx].count++;
        }
    }
}

void print_roman(struct numeral numerals[]) {
    for (size_t i = 0; i < NUMERAL_AMOUNT; i++)
    {
        char *numeral = numerals[i].numeral;
        for (size_t j = 0; j < numerals[i].count; j++)
        {
            printf("%s",numeral);
        }
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    if (argc != 2)
    {
        printf("input one integer number\n");
        exit(EXIT_FAILURE);
    }

    int n = atoi(argv[1]);
    struct numeral numerals[NUMERAL_AMOUNT];
    memcpy(&numerals, &NUMERALS, sizeof NUMERALS);
    arabic_to_roman(n, numerals);
    if (n > 3999)
    {
        printf("[!] Outside of standard roman numerals.\n");
    }
    
    printf("%s = ",argv[1]);
    print_roman(numerals);

    exit(EXIT_SUCCESS);
    return 0;
}
