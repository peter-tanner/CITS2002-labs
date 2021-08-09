
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#include "first_day_of_month.c"
#include "year_utils.c"

#define WEEK_LENGTH 7

// Adds padding so it's centered.
void printHeader(int month, int year) {
    int len = strlen(MONTH_NAME[month-1]) + 5; // Let's assume the year length is 4.
    int lPad = (3*WEEK_LENGTH - len)/2;
    printf("%*s %d\n", 12, MONTH_NAME[month-1], year);
}

static bool LEFT_HAND = false;

int leftIdx(int i) {
    switch (LEFT_HAND)
    {
    case true:
        return 6-i;
    default:
        return i;
    }
}

void printCal(int month, int year) {
    printHeader(month, year);
    for (int i = 0; i < WEEK_LENGTH; i++)
    {
        printf("%s ", DAY_NAME[leftIdx(i)]);
    }
    printf("\n");

    // Original solution just printed but easier to use 
    // 2d array for left hand mode.
    int limit = monthLimit(month, year);
    int week[WEEK_LENGTH] = {0};
    int idx = first_day_of_month(month, year);
    int day_ = 1;
    for (int i = 1; i < 6; i++)
    {
        while (idx < WEEK_LENGTH)
        {
            if (day_ > limit) {
                break;
            }
            week[idx] = day_;
            day_++;
            idx++;
        }
        
        // print row
        idx = 0;
        for (int j = 0; j < WEEK_LENGTH; j++)
        {
            int d = week[leftIdx(j)];
            switch (d)
            {
            case 0:
                printf("   ");
                break;
            default:
                printf("%-3d", d);
                break;
            }
        }
        memset(week, 0, sizeof week); // clear int array
        printf("\n");
    }
    printf("\n");
}


int main(int argc, char const *argv[])
{
    int year = 1;
    int month = 1;
    switch (argc)
    {
    case 0:
    case 1:
        {
            struct tm tm = getCurrentTime();
            year = tm.tm_year+1900;
            month = tm.tm_mon+1;
        }
        break;
    case 4:
        LEFT_HAND = (strcmp(argv[3], "true") == 0);
    case 3:
        year = atoi(argv[1]);
        month = atoi(argv[2]);
        if (month >= 1 && month <= 12 && year >= 1) {
            break;
        }
    default:
        printf("Incorrect arguments - expected no arguments or two arguments\ncal year month\ncal year month lefthanded_mode(true|false)\n");
        exit(EXIT_FAILURE);
        break;
    }
    
    printCal(month, year);
    exit(EXIT_SUCCESS);
    return 0;
}