/*
 * Exercise 3-5
 * Convert an integer to a string in base b (2 through 36).
 * Digits above 9 are represented by uppercase A through Z.
 * Returns 1 on success and 0 if the base is outside the supported range.
 * Compile: gcc -std=c99 -Wall -Wextra -pedantic Exercise_3_5_itob.c -o ex3_5
 */
#include <stdio.h>

void reverse(char s[])
{
    int left = 0;
    int right = 0;
    char temp;

    while (s[right] != '\0')
        right++;
    right--;

    while (left < right) {
        temp = s[left];
        s[left] = s[right];
        s[right] = temp;
        left++;
        right--;
    }
}

int itob(int n, char s[], int b)
{
    unsigned int value;
    int i = 0;

    if (b < 2 || b > 36)
        return 0;

    if (n < 0)
        value = 0u - (unsigned int)n;
    else
        value = (unsigned int)n;

    do {
        unsigned int digit = value % (unsigned int)b;
        if (digit < 10u)
            s[i++] = (char)('0' + digit);
        else
            s[i++] = (char)('A' + (digit - 10u));

        value /= (unsigned int)b;
    } while (value != 0u);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
    return 1;
}

int main(void)
{
    char result[50];

    if (itob(255, result, 16))
        printf("255 in base 16 = %s\n", result);

    if (itob(25, result, 2))
        printf("25 in base 2 = %s\n", result);

    if (itob(-31, result, 16))
        printf("-31 in base 16 = %s\n", result);

    return 0;
}
