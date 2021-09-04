#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>

int main(int argc, char const *argv[])
{
    if (argc != 3)
    {
        printf("Usage: goodchessmove [GAMESTATE] [OUTPUT]\n");
        exit(EXIT_FAILURE);
    }
    
    // placeholder for a real chess program
    printf("Executing chess move. GAMESTATE: %s, OUTPUT: %s\n",
           argv[1], argv[2]);

    // do chess
    sleep(5);

    fflush(stdout);
    printf("Finished executing chess move. Wrote %s\n", argv[2]);
    exit(EXIT_SUCCESS);
}
