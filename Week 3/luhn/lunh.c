/*
The Luhn algorithm was developed by German computer scientist Hans Peter Luhn in
1954, and is used by many credit card companies to distinguish valid credit card
numbers from random sequences of digits. To determine if a given credit card
number passes the Luhn test:
* Consider the card's digits from right-to-left.
* Taking the first, third, ... and every odd digit (from right-to-left), sum
  them to form the sum s1
* Taking the second, fourth ... and every even digit (from right-to-left):
    * Multiply each even digit by two, sum that product's digits, and add 
      together all those sums to form the sum s2
* If (s1 + s2) ends in zero, then the original number was a valid credit card
  number!
* Encourage everyone in the Lab to give you their credit card number (so you can 
  test your code, of course).
*/

#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

bool number(char c) {
    int n = c - '0';
    return n >= 0 && n <= 9;
}

bool checkCreditCard(char const *cc) {
    int start = strlen(cc)-1;
    int s1 = 0;
    int s2 = 0;
    bool odd = true;
    bool success = true;
    for (int i = start; i >= 0; i--)
    {
        if (!number(cc[i]))
        {
            success = false;
            return false;
            break;
        }
        
        if (odd) {
            s1 += (cc[i] - '0');
        } else {
            s2 += (cc[i] - '0');
        }
        odd = !odd;
    }
    s2 *= 2;
    return success && (s1+s2) % 10 == 0;
}

int main(int argc, char const *argv[])
{
    if (argc < 2)
    {
        printf("Expected one or more CC numbers\n");
        exit(EXIT_FAILURE);
    }
    
    for (int i = 1; i < argc; i++)
    {
        if (checkCreditCard(argv[i])) {
            printf("Valid credit card number %s\n",argv[i]);
        } else {
            printf("Invalid credit card number %s\n",argv[i]);
        }
    }
    exit(EXIT_SUCCESS);
    return 0;
}
