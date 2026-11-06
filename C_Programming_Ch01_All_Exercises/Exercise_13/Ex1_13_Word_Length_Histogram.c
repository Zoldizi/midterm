#include <stdio.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 20

/* Exercise 1-13: Horizontal histogram of word lengths. */
int main(void)
{
    int c, length = 0, counts[MAX_WORD_LENGTH + 1] = {0};
    int i, j;

    while ((c = getchar()) != EOF) {
        if (isspace((unsigned char)c)) {
            if (length > 0) {
                if (length > MAX_WORD_LENGTH) length = MAX_WORD_LENGTH;
                ++counts[length];
                length = 0;
            }
        } else {
            ++length;
        }
    }
    if (length > 0) {
        if (length > MAX_WORD_LENGTH) length = MAX_WORD_LENGTH;
        ++counts[length];
    }

    printf("Word length histogram (20 means 20 or more):\n");
    for (i = 1; i <= MAX_WORD_LENGTH; ++i) {
        if (counts[i] > 0) {
            printf("%2d: ", i);
            for (j = 0; j < counts[i]; ++j) putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
