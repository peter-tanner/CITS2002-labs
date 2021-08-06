/*
* 🌶 [2D array, nested loop] Fill a 2D array of, say, 10x20 integers with
* non-negative random integers. Without using your language's builtin/standard
* sort() method/function, print out the second largest value in the array.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


#define X_LENGTH 10
#define Y_LENGTH 20

// Testing
void iterArray(int arr[][Y_LENGTH]) {
    int n = 0;
    for (int i = 0; i < X_LENGTH; i++)
    {
        for (int j = 0; j < Y_LENGTH; j++)
        {
            arr[i][j] = n;
            n++;
        }
    }
}

void randomizeArray(int arr[][Y_LENGTH]) {
    srand(time(NULL)); // Seed rng
    for (int i = 0; i < X_LENGTH; i++)
    {
        for (int j = 0; j < Y_LENGTH; j++)
        {
            arr[i][j] = rand();
        }
    }
}

int twoLargest(int arr[][Y_LENGTH]) {
    int secondLargest = 0;
    int largest = 0;
    for (int i = 0; i < X_LENGTH; i++)
    {
        for (int j = 0; j < Y_LENGTH; j++)
        {
            if (arr[i][j] > largest)
            {
                secondLargest = largest;
                largest = arr[i][j];
            }
        } 
    }
    return secondLargest;
}

int main(void)
{
    int arr[X_LENGTH][Y_LENGTH];
    // randomizeArray(arr);
    iterArray(arr);
    printf("Second largest : %d\n", twoLargest(arr));
    return 0;
}


