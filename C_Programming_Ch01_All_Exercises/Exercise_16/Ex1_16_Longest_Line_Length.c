#include <stdio.h>
#include <stdlib.h>

/* Exercise 1-16: Read arbitrarily long lines and print the longest line
   length and as much of the line as was read. */
static char *read_line(size_t *length)
{
    size_t cap = 128, n = 0;
    int c;
    char *s = (char *)malloc(cap);
    if (!s) return NULL;

    while ((c = getchar()) != EOF && c != '\n') {
        if (n + 1 >= cap) {
            char *tmp;
            cap *= 2;
            tmp = (char *)realloc(s, cap);
            if (!tmp) { free(s); return NULL; }
            s = tmp;
        }
        s[n++] = (char)c;
    }
    if (c == EOF && n == 0) { free(s); return NULL; }
    s[n] = '\0';
    *length = n;
    return s;
}

int main(void)
{
    char *line, *longest = NULL;
    size_t len, max = 0;

    while ((line = read_line(&len)) != NULL) {
        if (len > max) {
            char *copy = (char *)realloc(longest, len + 1);
            if (!copy) { free(line); free(longest); return 1; }
            longest = copy;
            for (size_t i = 0; i <= len; ++i) longest[i] = line[i];
            max = len;
        }
        free(line);
    }
    if (longest) {
        printf("Longest line length: %lu\n", (unsigned long)max);
        printf("%s\n", longest);
    }
    free(longest);
    return 0;
}
