#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

//  written by Chris.McDonald@uwa.edu.au
//
//  compile:  cc -std=c11 -Wall -Werror -o stackmachine stackmachine.c

#define STACK_SIZE 1000

int stackmachine(FILE *input)
{
    int         stack[STACK_SIZE];         // a large stack
    int         SP = -1;             // stack is initially empty

    char        line[100];

//  READ FROM input UNTIL WE REACH THE END-OF-FILE
    while(fgets(line, sizeof line, input) != NULL) {
        char word1[50], word2[50];

//  SPLIT THE LINE INTO UP TO TWO WORDS
        int wcount = sscanf(line, "%s %s", word1, word2);

        if(wcount == 2) {
            if(strcmp(word1, "push") == 0) {
//              perform actions for the "push" instruction
//              using word2 (an integer value)
                stack[++SP] = atoi(word2);
            } else if(strcmp(word1, "pop") == 0) {
                SP--;
            }

//          add other instructions here....
        } else if(wcount == 1 && SP > 0) {
            if(strcmp(word1, "add") == 0) {
//              perform actions for the "add" instruction
                stack[--SP] = stack[SP] + stack[SP-1];
            } else if(strcmp(word1, "subtract") == 0) {
                stack[--SP] = stack[SP-1] - stack[SP];
            } else if(strcmp(word1, "multiply") == 0) {
                stack[--SP] = stack[SP] * stack[SP-1];
            }
//          add other instructions here....
        } else if (SP < 2) {
            fprintf(stderr, "HALT: Pointer out of range\n");
            exit(EXIT_FAILURE);
        }
        if (SP < 0 || SP >= STACK_SIZE) {
            fprintf(stderr, "HALT: Pointer out of range\n");
            exit(EXIT_FAILURE);
        }
        
        printf("%d\n",stack[SP]);

        if(wcount == 0) {
            fprintf(stderr, "HALT: unrecognised line: %s\n", line);
            exit(EXIT_FAILURE);
        }
    }

//  RETURN THE FINAL RESULT (FROM THE TOP-OF-STACK)
    return stack[SP--];
}

int main(int argc, char *argv[])
{
    int result;
    argv[1] = "./stackinstructions.txt";
//  CHECK THE NUMBER OF ARGUMENTS
    if(argc > 1) {
        FILE *fp        = fopen(argv[1], "r");

//  ATTEMPT TO OPEN AND EVALUATE THE INSTRUCTIONS FROM A FILE
        if(fp == NULL) {
            fprintf(stderr, "HALT: cannot open '%s'\n", argv[1]);
            exit(EXIT_FAILURE);
        }
        result = stackmachine(fp);
        fclose(fp);                     // we opened it, so we close it
    }

//  OTHERWISE, EVALUATE THE INSTRUCTIONS FROM stdin (THE KEYBOARD)
    else {
        result = stackmachine(stdin);
    }

//  PRINT THE FINAL RESULT (FROM THE TOP-OF-STACK)
    printf("result = %i\n", result);

//  YOU CAN PROVIDE ANY (OR ALL!) OF THE FOLLOWING LINES (DOESN'T MATTER)
    exit(EXIT_SUCCESS);
    return EXIT_SUCCESS;
    return 0;
}
