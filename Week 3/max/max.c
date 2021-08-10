/*
* Write a program which accepts exactly 3 command-line arguments (other than the 
  program's name in argvalue[0]), converts each to an integer value, and prints
  the maximum of the 3 values.
* Rewrite your solution to the previous task so that it now prints the maximum 
  of an arbitrary number of command-line arguments, perhaps 3, or 10, or 20....
*/

#include <stdlib.h>
#include <stdio.h>


int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        printf("No input provided!\n");
        exit(EXIT_FAILURE);
    }
    
    int max = -__INT32_MAX__;
    for (int i = 0; i < argc; i++)
    {
        if (atoi(argv[i]) > max)
        {
            max = atoi(argv[i]);
        }
    }
    printf("Maximum value: %d\n",max);
    exit(EXIT_SUCCESS);
    return 0;
}
