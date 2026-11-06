#include <stdio.h>

/* Exercise 1-24: Check matching parentheses, brackets and braces.
   Also skips delimiters inside strings, character constants and comments. */
#define MAX_STACK 10000

int main(void)
{
    int c, state = 0, escaped = 0, line = 1, error = 0;
    char stack[MAX_STACK];
    int stack_line[MAX_STACK];
    int top = 0;

    /* states: 0 normal, 1 string, 2 char, 3 line comment,
       4 block comment, 5 block-comment star */
    while ((c = getchar()) != EOF) {
        int next;
        if (c == '\n') ++line;

        if (state == 1 || state == 2) {
            if (escaped) escaped = 0;
            else if (c == '\\') escaped = 1;
            else if ((state == 1 && c == '"') || (state == 2 && c == '\''))
                state = 0;
            continue;
        }
        if (state == 3) {
            if (c == '\n') state = 0;
            continue;
        }
        if (state == 4) {
            if (c == '*') state = 5;
            continue;
        }
        if (state == 5) {
            if (c == '/') state = 0;
            else if (c != '*') state = 4;
            continue;
        }

        if (c == '"') { state = 1; continue; }
        if (c == '\'') { state = 2; continue; }
        if (c == '/') {
            next = getchar();
            if (next == '/') { state = 3; continue; }
            if (next == '*') { state = 4; continue; }
            if (next != EOF) ungetc(next, stdin);
            continue;
        }

        if (c == '(' || c == '[' || c == '{') {
            if (top >= MAX_STACK) { printf("Error: nesting too deep\n"); return 1; }
            stack[top] = (char)c;
            stack_line[top++] = line;
        } else if (c == ')' || c == ']' || c == '}') {
            char expected = (c == ')') ? '(' : (c == ']') ? '[' : '{';
            if (top == 0 || stack[top - 1] != expected) {
                printf("Unmatched closing '%c' at line %d\n", c, line);
                error = 1;
            } else --top;
        }
    }

    if (state == 1 || state == 2 || state == 4 || state == 5) {
        printf("Warning: unterminated string, character constant, or block comment\n");
        error = 1;
    }
    while (top > 0) {
        --top;
        printf("Unclosed '%c' from line %d\n", stack[top], stack_line[top]);
        error = 1;
    }
    if (!error) printf("No delimiter errors found.\n");
    return error;
}
