// see superloop.c for information
// remember to add ./superloop.c to gcc for this to compile!

#include <stdio.h>
#include <stdlib.h>
#include "superloop.h"


void func(int length, int (*values)[]) {
    for (size_t i = 0; i < length; i++)
    {
        printf("%d ", (*values)[i]);
    }
    printf("\n");
}

int main(int argc, char const *argv[])
{
    if (argc != 5)
    {
        printf("Expected 4 arguments\ntest_superloop <loop_depth> <start> <end> <increment>\n");
        exit(EXIT_FAILURE);
    }

    superloop(atoi(argv[1]), atoi(argv[2]), atoi(argv[3]), atoi(argv[4]), func);
    exit(EXIT_SUCCESS);
    return 0;
}
