/*
* Each call to the standard C11 function rand() returns a different random
  integer. Running the same program multiple times results in exactly the same
  sequence of random integers. While this is generally unexpected ("hey, they
  are not random"!), it is very helpful for debugging programs without the
  randomness.
* We can provide each execution with a more random sequence of random numbers by
  seeding the random number generator with the C statement srand( time(NULL) );
    * Write a simple program to fill an array of 10 integers with random numbers
      from rand(). Run the program several times, printing the contents of the
      array.
    * Now, use srand() to seed the generation of random numbers. Run the program
      several times, printing the contents of the array.
    * Extend your program by passing the initialised array to another function
      which finds and prints the largest value in the array.
    * Finally, extend the program's function to place the array's largest value
      into the array's first element (index position 0), "pushing" all other
      values down in the array (0→1, 1→2, 2→3, and so on).
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <string.h>

#define ARRAY_LENGTH 10

void randomize_array(int arr_len, int arr[])
{
    for (size_t i = 0; i < arr_len; i++)
    {
        arr[i] = rand();
    }
}

int max(int arr_len, int arr[])
{
    int max = -__INT32_MAX__;
    for (size_t i = 0; i < arr_len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}

int count(int arr_len, int arr[], int n) {
    int count = 0;
    for (size_t i = 0; i < arr_len; i++)
    {
        if (arr[i] == n)
        {
            count++;
        }
        
    }
    return count;
}

// Implementation will account for very rare occurence of duplicate max values.
// (even though it is very, VERY unlikely).
int shift_max(int arr_len, int arr[]) {
    int arr_[arr_len];
    memcpy(arr_, arr, sizeof(int)*arr_len);
    int m = max(arr_len, arr);
    int m_count = count(arr_len, arr, m);
    int idx = m_count;
    for (size_t i = 0; i < m_count; i++)
        arr[i] = m;
    for (size_t i = 0; i < arr_len; i++)
    {
        if (arr_[i] != m)
        {
            arr[idx] = arr_[i];
            idx++;
        }
    }
}

int main(void)
{
    srand(time(NULL));
    int rand_arr[ARRAY_LENGTH];

    randomize_array(ARRAY_LENGTH, rand_arr);
    shift_max(ARRAY_LENGTH, rand_arr);

    printf("Max: %d\n", max(ARRAY_LENGTH, rand_arr));
    for (size_t i = 0; i < ARRAY_LENGTH; i++)
    {
        printf("%d ", rand_arr[i]);
    }
    printf("\n");

    exit(EXIT_SUCCESS);
    return 0;
}
