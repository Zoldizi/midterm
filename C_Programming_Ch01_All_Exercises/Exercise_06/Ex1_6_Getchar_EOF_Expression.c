#include <stdio.h>

/* Exercise 1-6: Verify that getchar() != EOF is 0 or 1. */
int main(void)
{
    int result;
    printf("Enter one character, then press Enter: ");
    result = (getchar() != EOF);
    printf("getchar() != EOF evaluates to %d\n", result);
    return 0;
}
