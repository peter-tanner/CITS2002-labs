
/*
* 1 [integer arithmetic, basic loop] When Australia first adopted decimal
* currency in 1966, coins had the denominations of 1c, 2c, 5c, 10c, 20c, and
* (a round!) 50c. If a person purchased something valued at $1 or less, and paid
* with a $1 note (yes), write a program to list the minimum number of coins, and
* their demoninations, that they should receive as change.
*/

#include <stdlib.h>
#include <stdio.h>

/*
* argument => cost in cents.
* Assume a value of less than 100c as per the question.
* Assume only the first argument has a price, else use the default example price
*/
int main(int argc, char const *argv[])
{
    int price = 53;
    if (argc > 1)
    {
        price = 0;
        int i = 0;
        while (argv[1][i] != '\0')
        {
            int digit = argv[1][i]-'0';
            if (digit > 9 || digit < 0) 
            {
                exit(EXIT_FAILURE);
            }
            price *= 10;
            price += digit;
            i++;
        }
    }
    int remainder = 100 - price;
    const int coinValues[] = {50, 20, 10, 5, 2, 1};
    printf("Change: ");
    for (size_t i = 0; i < 6; i++)
    {
        int coinValue = coinValues[i];
        if (remainder / coinValue > 0) {
            printf("%d %dc coins, ", remainder/coinValue, coinValue);
            remainder -= coinValue*(remainder/coinValue);
        }
    }
    printf("\n");
    exit(EXIT_SUCCESS);
}
