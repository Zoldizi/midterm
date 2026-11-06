#include <stdio.h>

/* Exercise 1-18: Remove trailing blanks and tabs; discard blank lines. */
int main(void)
{
    int c;
    char line[10000];
    size_t len = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
                --len;
            if (len > 0) {
                fwrite(line, 1, len, stdout);
                putchar('\n');
            }
            len = 0;
        } else if (len < sizeof line) {
            line[len++] = (char)c;
        }
    }
    while (len > 0 && (line[len - 1] == ' ' || line[len - 1] == '\t'))
        --len;
    if (len > 0) fwrite(line, 1, len, stdout);
    return 0;
}
