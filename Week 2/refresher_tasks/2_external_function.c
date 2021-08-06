/*
* 2 [calling external function] Using your chosen programming language, write a
* short program to print out today's date and time
* (example output: Thu Jul 29 18:19:34 2021). The actual format is unimportant.
*/

// man strftime

#include <time.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    char outstr[200];
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);
    if (tmp == NULL) {
        exit(EXIT_FAILURE);
    }
    strftime(outstr, sizeof(outstr), "%FT%T", tmp);
    printf("%s\n", outstr);
    exit(EXIT_SUCCESS);
}
