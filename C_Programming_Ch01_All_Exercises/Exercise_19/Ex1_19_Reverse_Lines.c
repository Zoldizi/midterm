#include <stdio.h>

/* Exercise 1-19: Reverse each input line using reverse(s). */
static void reverse(char s[])
{
    size_t left = 0, right = 0;
    char temp;
    while (s[right] != '\0') ++right;
    if (right == 0) return;
    --right;
    while (left < right) {
        temp = s[left]; s[left] = s[right]; s[right] = temp;
        ++left; --right;
    }
}

int main(void)
{
    int c;
    char line[10000];
    size_t n = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            line[n] = '\0';
            reverse(line);
            printf("%s\n", line);
            n = 0;
        } else if (n < sizeof line - 1) line[n++] = (char)c;
    }
    if (n > 0) {
        line[n] = '\0';
        reverse(line);
        printf("%s\n", line);
    }
    return 0;
}
