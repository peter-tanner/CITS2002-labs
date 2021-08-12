/*
* Trivially implement Ackermann's function.
* Extend your implementation to count the number of recursive calls and the 
  maximum recursive depth required for, say, A(1, 2) and A(3, 3).
* 🌶 🌶 Redesign your implementation so that it doesn't require any global
  variables to maintain the counts of recursive calls and maximum recursive
  depth.
*/

#include <stdio.h>
#include <stdlib.h>

// This is for the challenge (🌶 🌶). Trivial solution below.
struct ack_state {
    int value;
    int max_depth;
    int current_depth;
    int call_count;
};

/*
note about max depth:
https://courses.cs.cornell.edu/cs412/2001SP/hw/bench/ack.html
max depth of \(A(3,k)\) is \(2^{k+3}-1\)
*/
void ackermann(int m, int n, struct ack_state *state) {
    state->call_count++;
    state->current_depth++;
    if (m == 0) {
        if (state->current_depth > state->max_depth)
        {
            state->max_depth = state->current_depth;
        }
        state->value = n+1;
    } else if (n == 0) {
        ackermann(m-1, 1, state);
    } else {
        ackermann(m, n-1, state);
        ackermann(m-1, state->value, state);
    }
    state->current_depth--;
}

int main(int argc, char const *argv[])
{
    if (argc != 3) {
        printf("Only two integer inputs allowed for ackermann function\n");
        exit(EXIT_FAILURE);
    }
    int m = atoi(argv[1]);
    int n = atoi(argv[2]);
    struct ack_state *state;
    state = malloc(sizeof(struct ack_state));
    ackermann(m, n, state);
    printf("ackermann(%d,%d) = %d\n", m, n, state->value);
    printf("ackermann calls: %d\n", state->call_count);
    printf("maximum call depth: %d\n", state->max_depth);
    exit(EXIT_SUCCESS);
    return 0;
}

// Trivial ackermann
/*
int ackermann(int m, int n) {
    if (m == 0) {
        return n+1;
    } else if (n == 0) {
        return ackermann(m-1, 1);
    }
    return ackermann(m-1, ackermann(m, n-1));
}
*/