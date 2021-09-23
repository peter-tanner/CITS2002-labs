Using the example strlen() and strcpy() functions of Lecture 13 as a guide, write pairs of functions to implement versions of the following standard C functions:
* strcat
* strcmp
* strncmp
* strchr
* strrchr
* 🌶 strpbrk
* 🌶 🌶 strstr

Maintain two separate C source files for this task: one file for the array-based versions of each function (named arrays.c), and one file for the pointer-based versions (named pointers.c). Develop two separate header files, one containing the prototypes of the array-based functions (named arrays.h), and the other containing the prototypes of the pointer-based functions (named pointers.h).

Create a single testing program named stringtest.c, containing the only main() function for this question, that tests each of the functions you write. The file stringtest.c should include both of your header files.
Approach the writing of each function by following these steps:
Firstly, read the appropriate online Linux manual entry for each function (e.g. run man strcat). Pay particular attention to the parameters of the function and its return value. Note that the online documentation will frequently use the (as yet not explained) keywords const and restrict. For now, simply ignore these and do not reproduce them in your functions (ask a demonstrator if interested in what they're for).

Next, develop a version of each function using arrays (not pointers), in arrays.c, As an example, name your first function strcat_a().

Write a short test function in stringtest.c file that calls your new function several times to test its execution. Depending on the function being tested, suitable parameters to the function will include simple short strings, long strings, empty strings, identical strings (when comparing them), very different strings, strings differing in only a single character, and strings containing, or otherwise, a required character (for strchr).

Next, develop a version of each function using pointers (not arrays) in pointers.c. As an example, name your first function strcat_p(). Undertake the same tests on your pointer-based functions as you did on your array-based ones.