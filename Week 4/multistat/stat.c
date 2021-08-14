/*
* 🌶 Lecture 6 introduced C11's structures and presented an example of how
  application programs can request and receive information from the underlying
  operating system The example involved the gettimeofday() system-call and the
  struct timeval structure.
* Similarly, applications can determine information about a file's attributes
  using the stat() system-call and the struct stat structure. Note that we need
  to read Section 2 of the online manual:

	prompt> man 2 stat
	
  otherwise we'll receive the documentation from Section 1.

* Write a program which accepts a number of filenames on the command-line, and
  prints (just as an integer) the modification-time of each file.
* Now, extend the program to also print each file's size (in bytes) and the
  (more useful string) modification-time of each file, using the ctime()
  function.
*/

#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <string.h>
#include <time.h>

int main(int argc, char const *argv[])
{
    struct stat *stat_result;
    stat_result = malloc(sizeof(struct stat));
    for (size_t i = 1; i < argc; i++)
    {
        stat(argv[i], stat_result);
        const time_t *mod_time = &(stat_result->st_mtim).tv_sec;
        char *time_human_readable = ctime(mod_time);
        printf("File \"%s\":\n", argv[i]);
        printf(" => last_modified: %s", time_human_readable);
        printf(" => size: %ld\n\n", stat_result->st_size);
    }
    
    return 0;
}
