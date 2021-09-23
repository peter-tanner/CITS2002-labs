/*
* 🌶 🌶 Write a function named sortPointers() that sets an array of integer 
  pointers to point to the elements of another array in ascending order.
* Your function should accept three parameters: the array of integers, the array
  of integer pointers to assign, and the integer count of the number of elements
  in the array, and hence should have the prototype:
    void sortPointers(int src[], int *ptrs[], int n);

* Your function should not change the original array, nor create any other
  arrays in completing this task.
*/

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

#define TEST_LENGTH 16

void swap_pointers(int **a, int **b)
{
    int *tmp = *a;
    *a = *b;
    *b = tmp;
}

bool sorted(int *ptrs[], int n)
{
    for (size_t i = 1; i < n; i++) {
        if (*ptrs[i-1] > *ptrs[i]) {
            swap_pointers(&ptrs[i-1],&ptrs[i]);
            return false;
        }
    }
    return true;    
}

// V. SLOW SORT
void sortPointers(int src[], int *ptrs[], int n)
{
    for (size_t i = 0; i < n; i++) {
        ptrs[i] = &src[i];
    }
    while (!sorted(ptrs,n));    // KEEP SWAPPING WHILE NOT SORTED - SLOW SORT.
}


// TEST sortPointers()
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
    
    int *ptrs[TEST_LENGTH];
    int src[TEST_LENGTH];
    intialize_rand_arr(src);
    
    
    sortPointers(src, ptrs, TEST_LENGTH);


    for (size_t i = 0; i < TEST_LENGTH; i++) {
        printf("%i\t%lu\n",*ptrs[i],(long)ptrs[i]);
    }
    
    return 0;
}
