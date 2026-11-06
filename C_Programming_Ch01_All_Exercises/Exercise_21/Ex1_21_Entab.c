#include <stdio.h>

#define TAB_WIDTH 8

/* Exercise 1-21: Replace runs of blanks with tabs and blanks.
   A tab is used when it reaches a tab stop and saves at least one character. */
int main(void)
{
    int c, column = 0, blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            ++blanks;
            ++column;
        } else {
            while (blanks > 0) {
                int to_stop = TAB_WIDTH - (column - blanks) % TAB_WIDTH;
                if (to_stop > 1 && blanks >= to_stop) {
                    putchar('\t');
                    blanks -= to_stop;
                } else {
                    putchar(' ');
                    --blanks;
                }
            }
            putchar(c);
            if (c == '\n') column = 0;
            else if (c == '\t') column += TAB_WIDTH - column % TAB_WIDTH;
            else ++column;
        }
    }
    while (blanks-- > 0) putchar(' ');
    return 0;
}
