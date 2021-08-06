/*
* 3 [floating-point numbers] In Lecture-2 we saw how some (in fact, most)
* floating-point values cannot be represented exactly on contemporary computers
* and, so, we must use them with great caution, or not at all. In your chosen
* programming language, repeat the exercise from Lecture-2, displaying
* sufficient decimal-points to 'expose' the problem.
*/

#include <stdio.h>

int main(void)
{
    float f = 1024.533;
    printf("%.25f\n",f);
    // Answer is 1024.5329589843750000000000000 due to imprecision.
    return 0;
}
