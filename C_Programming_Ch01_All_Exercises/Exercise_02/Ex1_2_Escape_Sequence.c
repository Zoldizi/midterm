#include <stdio.h>

/* Exercise 1-2: Experiment with an unrecognized escape sequence. */
int main(void)
{
    /* A portable way to print a backslash followed by c: */
    printf("Safe output: \\c\n");

    /*
       Uncomment this line to test an unrecognized escape sequence.
       Its behavior is not portable; your compiler may warn or reject it.
       printf("Test: \c\n");
    */
    return 0;
}
