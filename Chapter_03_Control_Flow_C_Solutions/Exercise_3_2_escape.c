/*
 * Exercise 3-2
 * Convert newline and tab characters to visible escape sequences and back.
 * Compile: gcc -std=c99 -Wall -Wextra -pedantic Exercise_3_2_escape.c -o ex3_2
 */
#include <stdio.h>

void escape(char s[], const char t[])
{
    int i = 0;
    int j = 0;

    while (t[i] != '\0') {
        switch (t[i]) {
        case '\n':
            s[j++] = '\\';
            s[j++] = 'n';
            break;
        case '\t':
            s[j++] = '\\';
            s[j++] = 't';
            break;
        default:
            s[j++] = t[i];
            break;
        }
        i++;
    }
    s[j] = '\0';
}

void unescaped(char s[], const char t[])
{
    int i = 0;
    int j = 0;

    while (t[i] != '\0') {
        if (t[i] == '\\' && t[i + 1] != '\0') {
            if (t[i + 1] == 'n') {
                s[j++] = '\n';
                i += 2;
            } else if (t[i + 1] == 't') {
                s[j++] = '\t';
                i += 2;
            } else {
                s[j++] = t[i++];
            }
        } else {
            s[j++] = t[i++];
        }
    }
    s[j] = '\0';
}

int main(void)
{
    char input[] = "Hello\tworld\nThis is a test.";
    char escaped[sizeof(input) * 2];
    char restored[sizeof(input)];

    escape(escaped, input);
    unescaped(restored, escaped);

    printf("Original string:\n%s\n\n", input);
    printf("Escaped string:\n%s\n\n", escaped);
    printf("Unescaped string:\n%s\n", restored);

    return 0;
}
