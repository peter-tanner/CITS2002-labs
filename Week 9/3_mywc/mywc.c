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
#include <getopt.h>

#define OPTIONS "clLw"

typedef struct {
    int count;
    bool print;
} WC_STAT;

typedef struct {
    WC_STAT lines;
    WC_STAT words;
    WC_STAT characters;
    WC_STAT max_characters;
} WC_STATS;

// ACTUAL COUNTING HERE.
void counter_stats(FILE *file, WC_STATS *stats)
{
    // PROCESS IN CHUNKS
    char buffer[BUFSIZ];

    bool word = false;
    int line_characters = 0;

    while ( fgets(buffer, BUFSIZ, file) != NULL ) {
        char *c = &buffer[0];
        while ( *c != '\0' ) {
            // COUNT WORDS.
            if (word && isspace(*c)) {
                stats->words.count++;
                word = false;
            } else if (!word) {
                word = true;
            }
            // COUNT CHARACTERS.
            stats->characters.count++;
            line_characters++;
            // COUNT NEWLINES.
            if ( *c == '\n' ) {
                if (line_characters > stats->max_characters.count) {
                    // EXCLUDES NEWLINE IN COUNT (-1).
                    stats->max_characters.count = line_characters - 1;
                }
                stats->lines.count++;
                line_characters = 0;
            }
            c++;
        }
    }
}

// NUMBER OF LINES IN A FILE.
void counter(char *path, WC_STATS *stats)
{
    FILE *file;
    if (path == NULL) {
        file = stdin;
    } else {
        file = fopen(path, "r");
    }
    
    if (file != NULL) {
        counter_stats(file, stats);
    } else {
        fprintf(stderr, "Error reading file.\n");
        exit(EXIT_FAILURE);
    }
}

void process_options(WC_STATS *options, int argc, char **argv, char **filename)
{
    int option;
    while ( (option = getopt(argc, argv, OPTIONS)) != EOF ) {
        switch (option) {
        case 'c':
            options->characters.print = true;
            break;
        case 'L':
            options->max_characters.print = true;
            break;
        case 'l':
            options->lines.print = true;
            break;
        case 'w':
            options->words.print = true;
            break;
        }
    }

    // DEFAULT OPTS.
    if (optind == 1) {
        options->words.print        = true;
        options->characters.print   = true;
        options->lines.print        = true;
    }
    
    // getopt MOVES THE NON-OPTION ARGUMENTS (FILENAME) TO THE END OF ARGV.
    if (optind < argc) {
        *filename = argv[optind];   // ONLY USE FIRST FILENAME.
    }
    
}

void print_stat(WC_STAT stat, char *fmt_str)
{
    if (stat.print) {
        printf(fmt_str, stat.count);
    }
}

void print_stats(WC_STATS *stats)
{
    print_stat(stats->characters,       "CHARACTERS     %d\n");
    print_stat(stats->words,            "WORDS          %d\n");
    print_stat(stats->lines,            "LINES          %d\n");
    print_stat(stats->max_characters,   "LINE_MAX_CHARS %d\n");
}

int main(int argc, char *argv[])
{
    WC_STATS *stats = malloc(sizeof(WC_STATS));
    char *file;

    process_options(stats, argc, argv, &file); printf("%s\n", file);
    counter(file, stats);
    print_stats(stats);

    return 0;
}