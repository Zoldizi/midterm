#include <stdio.h>
#include <ctype.h>

/* Exercise 1-12: Print the input one word per line. */
int main(void)
{
    int c, in_word = 0;
    while ((c = getchar()) != EOF) {
        if (isspace((unsigned char)c)) {
            if (in_word) putchar('\n');
            in_word = 0;
        } else {
            putchar(c);
            in_word = 1;
        }
    }
    if (in_word) putchar('\n');
    return 0;
}
