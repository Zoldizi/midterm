#include <stdio.h>

#define TAB_WIDTH 8

/* Exercise 1-20: Replace tabs with blanks up to the next tab stop. */
int main(void)
{
    int c, column = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            int spaces = TAB_WIDTH - column % TAB_WIDTH;
            while (spaces-- > 0) putchar(' ');
            column += TAB_WIDTH - column % TAB_WIDTH;
        } else {
            putchar(c);
            if (c == '\n') column = 0;
            else if (c == '\b') { if (column > 0) --column; }
            else ++column;
        }
    }
    return 0;
}
