#include <stdio.h>

/* Exercise 1-14: Frequency histogram of input characters.
   Counts printable ASCII characters; other characters are ignored. */
int main(void)
{
    int c, freq[128] = {0}, i, j;
    while ((c = getchar()) != EOF) {
        if (c >= 32 && c <= 126) ++freq[c];
    }

    printf("Character frequency histogram:\n");
    for (i = 32; i <= 126; ++i) {
        if (freq[i] > 0) {
            if (i == ' ') printf("' '");
            else printf(" '%c'", i);
            printf(": ");
            for (j = 0; j < freq[i]; ++j) putchar('*');
            putchar('\n');
        }
    }
    return 0;
}
