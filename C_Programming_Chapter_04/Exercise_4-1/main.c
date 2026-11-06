/* Exercise 4-1: find the rightmost occurrence of t in s. */
#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

static int read_line(char s[], int limit)
{
    int c = 0, i = 0;
    while (i < limit - 1 && (c = getchar()) != EOF && c != '\n')
        s[i++] = (char)c;
    if (c == '\n')
        s[i++] = '\n';
    s[i] = '\0';
    return i;
}

int strrindex(const char s[], const char t[])
{
    int i, j;
    size_t slen = strlen(s), tlen = strlen(t);
    if (tlen == 0 || tlen > slen)
        return -1;

    for (i = (int)(slen - tlen); i >= 0; --i) {
        for (j = 0; j < (int)tlen && s[i + j] == t[j]; ++j)
            ;
        if (j == (int)tlen)
            return i;
    }
    return -1;
}

int main(void)
{
    char line[MAXLINE], pattern[MAXLINE];
    int n;

    printf("Pattern: ");
    if (!fgets(pattern, sizeof pattern, stdin))
        return 1;
    pattern[strcspn(pattern, "\r\n")] = '\0';
    if (pattern[0] == '\0') {
        fprintf(stderr, "Pattern must not be empty.\\n");
        return 1;
    }

    printf("Enter lines (Ctrl+D to finish):\\n");
    while ((n = read_line(line, MAXLINE)) > 0) {
        int pos = strrindex(line, pattern);
        if (pos >= 0)
            printf("%sRightmost index: %d\\n", line, pos);
    }
    return 0;
}
