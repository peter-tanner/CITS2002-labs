/*
 * 🌶 🌶 🌶 If you had to write some code that iterated through all the
  possibilities for three variables in the range 0 to 10, you would probably
  write code similar to:

    for(int a = 0; a < 10; ++a) {
        for(int b = 0; b < 10; ++b) {
            for(int c = 0; c < 10; ++c) {
                ; // LOOP-BODY USING a, b, AND c
            }
        }
    }
  But what if you had to extend this to 4, 5, or even 10+ "nested" loops?
  Instead of further nesting more loops, it is possible to write a function that
  acts as a "superloop", performing the equivalent of n nested loops with just
  one loop. Write a function to do this, taking an argument n that indicates the
  number of nested loops your function should perform. To do this, you will need
  to keep a 1-dimensional array of n values that maintain the state of each loop
  during the execution of your function.
*/

#include <stdlib.h>
#include "superloop.h"

struct __superloop_state {
    void (*function)(int, int (*)[]);
    int (*value)[];
    int level;
    int depth;
    int start;
    int end;
    int increment;
};

void __loop(struct __superloop_state *state)
{
    if (state->level < state->depth)
    {
        for (int i = state->start; i < state->end; i += state->increment)
        {
            (*state->value)[state->level] = i;
            state->level++;
            __loop(state);
            state->level--;
        }
    } else {
        (*state->function)(state->depth, state->value);
    }
}

void superloop(int depth, int start, int end, int increment, void (*function)(int, int (*)[]))
{
    int (*value)[depth];
    value = malloc(depth*sizeof(int));
    struct __superloop_state state = {
        function,
        value,
        0,
        depth,
        start,
        end,
        abs(increment)
    };
    __loop(&state);
}