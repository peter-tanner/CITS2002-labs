
#include <time.h>
#include <stdbool.h>

static char *DAY_NAME[] = {"Su", "Mo", "Tu", "We", "Th", "Fr", "Sa"};
static char *MONTH_NAME[] = {
                                "January", "February", "March", "April",
                                "May", "June", "July", "August", "September",
                                "October", "November", "December"
                            };


bool isLeapYear(int year) {
    return year % 4 == 0 && (year % 100 != 0 || year % 400 == 0);
}

int monthLimit(int month, int year)
{
    bool leapYear = isLeapYear(year);
    switch (month)
    {
    case 2:
        return 28 + leapYear;    
    default:
        return 31 - (month - 1) % 7 % 2;
    }
}

struct tm getCurrentTime() {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    return tm;
}