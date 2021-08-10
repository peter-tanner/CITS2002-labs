/*
Write programs to print each of the following shapes. Use C's for loops to 
control your printing, rather than just 'fixed' calls to printf (imagine 
if a command-line argument indicated how big the Christmas tree should be!):
a. *        b.     *    c. *****    d.     *
   **             **       ****           ***
   ***           ***       ***           *****
   ****         ****       **           *******
   *****       *****       *           *********
*/

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

#define DEFAULT_HEIGHT 5

void repeatChar(char c, int pad, int n) {
    printf("%*s", pad, "");
    for (int i = 0; i < n; i++)
    {
        printf("%c",c);
    }
}


void drawTree(int n, bool reverse, bool pad, bool cone) {
    int incr = 1;
    if (cone) {
        incr = 2;
        n++;
    }
    for (int i = 1; i <= n; i+=incr)
    {
        if (reverse) {
            if (pad) {
                repeatChar('*',i/incr,n-i);
            } else {
                repeatChar('*',0,n-i);
            }
        } else {
            if (pad) {
                repeatChar('*',(n-i)/incr,i);
            } else {
                repeatChar('*',0,i);
            }
        }
        printf("\n");
    }
}

void drawTreeOption(int argc, char const *argv[], int n) {
    bool cone = false;
    bool right = false;
    bool inverted = false;
    for (int i = 0; i < argc; i++)
    {
        if (strcmp(argv[i], "--cone") == 0) {
            cone = true;
            right = true;
        } else if (strcmp(argv[i], "--right") == 0) {
            right = true;
        } else if (strcmp(argv[i], "--inverted") == 0) {
            inverted = true;
        }
    }

    if (n <= 0) {
        n = DEFAULT_HEIGHT;
    }
    
    drawTree(n, inverted, right, cone);
}

int main(int argc, char const *argv[])
{
    if (argc > 1) {
        drawTreeOption(argc, argv, atoi(argv[1]));
    } else {
        drawTreeOption(0, NULL, 0);
    }
    exit(EXIT_SUCCESS);
    return 0;
}
