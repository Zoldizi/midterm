#include <stdio.h>

/* Exercise 1-23: Remove C comments, preserving quoted strings/chars. */
int main(void)
{
    int c, next;
    enum { NORMAL, SLASH, LINE_COMMENT, BLOCK_COMMENT,
           BLOCK_STAR, STRING, CHARACTER, STRING_ESCAPE, CHAR_ESCAPE } state = NORMAL;

    while ((c = getchar()) != EOF) {
        switch (state) {
        case NORMAL:
            if (c == '/') state = SLASH;
            else {
                putchar(c);
                if (c == '"') state = STRING;
                else if (c == '\'') state = CHARACTER;
            }
            break;
        case SLASH:
            if (c == '/') state = LINE_COMMENT;
            else if (c == '*') state = BLOCK_COMMENT;
            else {
                putchar('/');
                putchar(c);
                state = (c == '"') ? STRING : (c == '\'') ? CHARACTER : NORMAL;
            }
            break;
        case LINE_COMMENT:
            if (c == '\n') { putchar('\n'); state = NORMAL; }
            break;
        case BLOCK_COMMENT:
            if (c == '*') state = BLOCK_STAR;
            else if (c == '\n') putchar('\n');
            break;
        case BLOCK_STAR:
            if (c == '/') state = NORMAL;
            else if (c != '*') {
                if (c == '\n') putchar('\n');
                state = BLOCK_COMMENT;
            }
            break;
        case STRING:
            putchar(c);
            if (c == '\\') state = STRING_ESCAPE;
            else if (c == '"') state = NORMAL;
            break;
        case CHARACTER:
            putchar(c);
            if (c == '\\') state = CHAR_ESCAPE;
            else if (c == '\'') state = NORMAL;
            break;
        case STRING_ESCAPE:
            putchar(c); state = STRING; break;
        case CHAR_ESCAPE:
            putchar(c); state = CHARACTER; break;
        }
    }
    if (state == SLASH) putchar('/');
    return 0;
}
