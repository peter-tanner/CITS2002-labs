/*
* 6. 🌶 Why did we do this? The performance of a hashtable can be dramatically
  better than other data structures, such as arrays, lists and binary trees.

    ** ANSWER: Hashtables have almost O(1) performance. A traditional O(n) array
       lookup is used for each bucket, but because the size of a bucket (n) is
       small, this is a relatively small amount of time. The hash function is 
       used to access one bucket. This function is independent of size 
       (constant time complexity), so performance will tend to O(1) as the 
       number of buckets tends to infinity (Assuming a perfect hash function).
       For an array, the traditional array search has to potentially go through
       n array items, so it has O(n) performance which is worse.

* For a collection of several thousand (a million?) random strings use the
  gettimeofday() system-call to measure how long in takes to insert, and to then
  find, the same set of strings with both an array and your new hashtable.
*/

#include "benchmark_hashtable.h"

char *random_string(size_t length)
{
    char *string = malloc(length);
    for (size_t i = 0; i < length; i++) {
        string[i] = '0' + rand() % 72;
    }
    return string;
}

bool find_string_array(char *string, char **arr, size_t length)
{
    for (size_t i = 0; i < length; i++) {
        if (strcmp(string, arr[i]) == 0) {
            return true;
        }
    }
    return false;
}

void intialize_benchmark(char **arr, HASHTABLE *hashtable)
{
    for (size_t i = 0; i < TEST_LENGTH; i++) {
        char *string = random_string(STRING_LENGTH);
        arr[i] = string;
        add_string_to_hashtable(hashtable, string);
    }
}

bool one_benchmark(char **arr, HASHTABLE *hashtable,
                   suseconds_t *dt_arr, suseconds_t *dt_hash)
{

    char *random_string = arr[rand() % TEST_LENGTH];
    struct timeval start;
    struct timeval end;
    gettimeofday(&start, NULL);
    find_string_array(random_string, arr, TEST_LENGTH);
    gettimeofday(&end, NULL);
    *dt_arr = end.tv_usec - start.tv_usec;
    if (end.tv_usec < start.tv_usec) return false;
    
    
    gettimeofday(&start, NULL);
    find_string_in_hashtable(hashtable, random_string);
    gettimeofday(&end, NULL);
    *dt_hash = end.tv_usec - start.tv_usec;
    if (end.tv_usec < start.tv_usec) return false;

    return true;
}

void print_stats(suseconds_t *times, size_t length, char *fmt_str)
{
    double avg = 0;
    suseconds_t min = __LONG_MAX__;
    suseconds_t max = 0;
    for (size_t i = 0; i < length; i++)
    {
        avg += times[i]*1.0/length; // LESS PRECISE DUE TO FP MATH.
        if (times[i] < min) {
            min = times[i];
        }
        if (times[i] > max) {
            max = times[i];
        }
    }
    printf(fmt_str, avg, min, max);
}

void benchmark(char **arr, HASHTABLE *hashtable)
{
    suseconds_t times_hash[BENCHMARK_ITERATIONS];
    suseconds_t times_array[BENCHMARK_ITERATIONS];
    for (size_t i = 0; i < BENCHMARK_ITERATIONS; i++) {
        bool success = false;
        while (!success) {
            success = one_benchmark(arr, hashtable,
                      &times_array[i], &times_hash[i]);
        }
    }
    print_stats(times_array, BENCHMARK_ITERATIONS, "ARRAY   : AVERAGE %lf MIN %d MAX %d\n");
    print_stats(times_hash, BENCHMARK_ITERATIONS,  "HASHMAP : AVERAGE %lf MIN %d MAX %d\n");
}

int main(int argc, char const *argv[])
{
    srand(time(NULL));
    HASHTABLE *hashtable = new_hashtable();
    char *arr[TEST_LENGTH];
    intialize_benchmark(arr,hashtable);
    benchmark(arr,hashtable);
    return 0;
}