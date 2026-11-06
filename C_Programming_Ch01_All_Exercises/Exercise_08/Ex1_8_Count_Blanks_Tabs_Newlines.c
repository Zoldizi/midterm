#include <stdio.h>

/* Exercise 1-8: Count blanks, tabs, and newline characters in input. */
int main(void)
{
    int c, blanks = 0, tabs = 0, newlines = 0;
    while ((c = getchar()) != EOF) {
        if (c == ' ') ++blanks;
        else if (c == '\t') ++tabs;
        else if (c == '\n') ++newlines;
    }
    printf("Blanks: %d\nTabs: %d\nNewlines: %d\n", blanks, tabs, newlines);
    return 0;
}
