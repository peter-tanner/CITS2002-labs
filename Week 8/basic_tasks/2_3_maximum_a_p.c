/*
* Write a function named maximum_a() that accepts an integer array and the
  number of elements in that array as parameters, returning a pointer to the 
  maximum integer in the array. It should have the prototype:
    int *maximum_a(int values[], int n);
* Your function should access elements of values as an array.

* Write a (very similar) version of the maximum_a() function that now accepts 
  the integer array as a pointer. It should have the prototype:
    int *maximum_p(int *values, int n);
* Use *pointer arithmetic* to complete this task.
*/

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define TEST_LENGTH 16

int *maximum_a(int values[], int n)
{
    int *max = &values[0];
    for (size_t i = 0; i < n; i++) {
        if (values[i] > *max) {
            max = &values[i];
        }
    }
    return max;
}

int *maximum_p(int *values, int n)
{
    int *max = &values[0];
    int *end = &values[0]+n;
    for (int *v_ptr = max; v_ptr < end; v_ptr++) {
        if (*v_ptr > *max) {
            max = v_ptr;
        }
    }
    return max;
}

// TEST maximum_a()
void intialize_rand_arr(int *arr)
{
    putchar('[');
    for (size_t i = 0; i < TEST_LENGTH; i++) {
        int value = rand() % 512;
        printf("%i, ", value);
        arr[i] = value;
    }
    printf("]\n");
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));

    int arr[TEST_LENGTH];
    intialize_rand_arr(arr);

    int *maximum_a_result = maximum_a(arr, TEST_LENGTH);
    printf("maximum_a() : Maximum is %i\n", *maximum_a_result);

    int *maximum_p_result = maximum_p(arr, TEST_LENGTH);
    printf("maximum_p() : Maximum is %i\n", *maximum_p_result);

    return 0;
}
