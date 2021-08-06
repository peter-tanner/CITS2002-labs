#include <stdio.h>   // => printf()
#include <stdlib.h>  // => exit(), EXIT_SUCCESS, EXIT_FAILURE
#include <string.h>  // strlen()
#include <ctype.h>   // isupper(), islower()

#include <unistd.h>

// Compile this program with:
//    cc -std=c11 -Wall -Werror -o rotate rotate.c

//  The rotate function returns the character ROT positions further along the
//  alphabetic character sequence from c, or c if c is not lower-case

char rotate(char c, int rot)
{
    // Check if c is lower-case or not
    if(islower(c)) {
        // The ciphered character is ROT positions beyond c,
        // allowing for wrap-around
        return ('a' + (c - 'a' + rot) % 26);
    } else if (isupper(c))
        return ('A' + (c - 'A' + rot) % 26);
    else {
        return c;
    }
}

void rotateString(char string[], int rot) {
    // Define a variable for a later loop
    int i;
    // Calculate the length of the first argument
    int length = strlen(string);

    // Loop for every character in the text
    for(i = 0; i < length; i++) {
        // Determine and print the ciphered character
        char c = string[i];
        printf("%d :\t%c => %c\n", i, c, rotate(c, rot));
    }

    // Print one final new-line character
    printf("\n");
}

//  Execution of the whole program begins at the main function

int main(int argcount, char *argvalue[])
{
    int rot = 13;
    for (int i = 1; i < argcount; i++)
    {
        char *ptr;
        int n = (int)strtol(argvalue[i], &ptr, 10);
        if (*ptr == '\0') {
            rot = n;
            printf("Rotate by %d\n\n", rot);
        } else {
            // Try reading file
            if (access(argvalue[i], F_OK) == 0)
            {
                printf("-- Open file %s --\n\n", argvalue[i]);
                FILE* f = fopen(argvalue[i], "r");
                char c;
                while ((c = getc(f)) != EOF)
                {
                    putchar(rotate(c, rot));
                }
                fclose(f);
            }
            
            // Else interpret as string
            printf("-- String %d --\n\n",i);
            rotateString(argvalue[i], rot);
            printf("-- End of string %d --\n\n",i);
        }

    }
    
    // Exit indicating success
    exit(EXIT_SUCCESS);
    return 0;
}
