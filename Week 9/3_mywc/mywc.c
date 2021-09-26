/*
* 3. Both Linux and macOS provide a standard command named wc (an abbreviation for
  wordcount!) which determines the number of lines, words, and characters in a
  named file. You can read about this command using the online documentation: 
  (man wc).
* For this task, you will develop your own version of the wc program named mywc.

* a. Firstly, write a function named counter() that calculates and prints out
  the number of lines contained within a file. Your counter() function should
  take one argument, a character array that provides a filename.
* b. Next, modify your mywc program and the counter() function to either count
  the lines of a file, named on the command-line, or to count the input
  "arriving" via the stdin stream. We often described such a program as a
  filter.
* c. Next, extend your counter() function so that it now also counts, and 
  prints, the number of characters and words found in the file. Be careful with 
  the meaning of a "word" - it's just a sequence of any characters surrounded by
  whitespace characters. Check your printed results against those of the 
  standard wc program.
* d. Next, observe that our counter() function is printing its three 
  results - as we can only return a single result. Modify the counter() function
  so that its three calculated results are now "given" back to the calling
  function through pointers passed as parameters. Now, the calling function will
  have the results placed in its own local variables, and be able to print
  (or use) the results itself.

* 4. 🌶 Now, using the standard getopt() function introduced in Lecture 17, add
  support for command-line options to your mywc utility from Task-3.
* Add command-line options to request:

    -c to report the number of characters,
    -l to report the number of lines,
    -L to report the maximum line length (as supported on Linux, but not macOS),
       and
    -w to report the number of words.

* Ensure that your program still works with meaningful defaults if no options
  are provided on the command-line.
* Ensure that your program checks that the provided command-line arguments are
  sensible - if they are not, issue an appropriate error message to stderr after
  all options have been processed.
*/

#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <ctype.h>

void counter_stats(FILE *file, int *lines, int *words, int *characters)
{
    char buffer[BUFSIZ];
    // PROCESS IN CHUNKS
    bool word = false;
    while ( fgets(buffer, BUFSIZ, file) != NULL ) {
        char *c = &buffer[0];
        while ( *c != '\0' ) {
            // COUNT WORDS
            if (word && isspace(*c)) {
                (*words)++;
                word = false;
            } else if (!word) {
                word = true;
            }
            // COUNT CHARACTERS
            (*characters)++;
            // COUNT NEWLINES
            if ( *c == '\n' ) {
                (*lines)++;
            }
            c++;
        }
    }
}

// NUMBER OF LINES IN A FILE.
void counter(char *path, int *lines, int *words, int *characters)
{
    FILE *file;
    if (path == NULL) {
        file = stdin;
    } else {
        file = fopen(path, "r");
    }
    
    if (file != NULL) {
        counter_stats(file, lines, words, characters);
    } else {
        fprintf(stderr, "Error reading file.\n");
        exit(EXIT_FAILURE);
    }
    
}

int main(int argc, char *argv[])
{
    char *file = argv[1];
    // CHECK IF WE ARE ACCEPTING INPUT FROM A PIPE.
    if (argc > 2) {
        fprintf(stderr, "Usage: mywc [FILE]\n");
        exit(EXIT_FAILURE);
    }
    
    int lines;
    int words;
    int characters;
    counter(argv[1], &lines, &words, &characters);
    printf( "LINES %d, WORDS %d, CHARACTERS %d\n",
            lines, words, characters  );
    return 0;
}