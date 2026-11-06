#include <stdio.h>
#include <stdlib.h>

/* Exercise 1-17: Print all input lines longer than 80 characters. */
int main(void)
{
    int c;
    size_t len = 0, cap = 128;
    char *line = (char *)malloc(cap);
    if (!line) return 1;

    while ((c = getchar()) != EOF) {
        if (c != '\n') {
            if (len + 1 >= cap) {
                char *tmp;
                cap *= 2;
                tmp = (char *)realloc(line, cap);
                if (!tmp) { free(line); return 1; }
                line = tmp;
            }
            line[len++] = (char)c;
        } else {
            if (len > 80) {
                line[len] = '\0';
                printf("%s\n", line);
            }
            len = 0;
        }
    }
    if (len > 80) {
        line[len] = '\0';
        printf("%s\n", line);
    }
    free(line);
    return 0;
}
