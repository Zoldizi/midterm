#include <stdio.h>
#include <ctype.h>

#define FOLD_COLUMN 40

/* Exercise 1-22: Fold long input lines near the specified column. */
int main(void)
{
    int c, column = 0, last_space = -1;
    char buffer[10000];
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            buffer[column] = '\0';
            printf("%s\n", buffer);
            column = 0;
            last_space = -1;
            continue;
        }
        if (column < (int)sizeof buffer - 1) {
            buffer[column++] = (char)c;
            if (isspace((unsigned char)c)) last_space = column - 1;
        }
        if (column >= FOLD_COLUMN) {
            int cut = (last_space >= 0 && last_space < column - 1) ? last_space : column;
            int i;
            for (i = 0; i < cut; ++i) putchar(buffer[i]);
            putchar('\n');
            if (cut < column) {
                int remain = column - cut;
                for (i = 0; i < remain; ++i) buffer[i] = buffer[cut + i];
                column = remain;
            } else column = 0;
            last_space = -1;
            for (i = 0; i < column; ++i)
                if (isspace((unsigned char)buffer[i])) last_space = i;
        }
    }
    if (column > 0) {
        buffer[column] = '\0';
        printf("%s", buffer);
    }
    return 0;
}
