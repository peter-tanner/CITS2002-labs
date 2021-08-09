
## Workshop 1 content
Workshop content: https://web.archive.org/web/20210809074913/https://teaching.csse.uwa.edu.au/units/CITS2002/workshops/workshop2.php\
`first_day_of_month.c`: https://web.archive.org/web/20210809075040/https://teaching.csse.uwa.edu.au/units/CITS2002/workshops/first_day_of_month.c 

EXTRA WORK
* There's some required information that we haven't yet covered in lectures (information we can get from our computer's operating system). Try to identify that extra information.
* Consider the file first_day_of_month.c whose function determines the first day (Sun, Mon, ...) of a requested month. Identify the functions that are used to determine this information, and read their documentation for your system.
* We know that Linux utility programs can receive optional command-line arguments to specify actions beyond their default actions. In the case of the cal utility, if two (optional) arguments are provided, we are specifying the required month and year to be printed.
* Assuming we receive the additional two command-line arguments, which the C program receives as character strings, we can 'convert' their string representations of integers to integer values using the standard atoi() function.
* Extend your program to detect optional command-line arguments, and to print the requested calendar.
* 🌶 And how could we support left-handers?
* 🌶 🌶 Wow! What happened in September 1752? (which you don't have to deal with!) :
```
prompt> cal 9 1752

   September 1752
Su Mo Tu We Th Fr Sa 
       1  2 14 15 16
17 18 19 20 21 22 23
24 25 26 27 28 29 30
```