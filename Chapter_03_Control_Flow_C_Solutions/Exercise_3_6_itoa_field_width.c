/*
 * Exercise 3-6
 * Convert an integer to decimal and pad it with leading blanks
 * when the requested minimum field width is larger than the result.
 * Compile: gcc -std=c99 -Wall -Wextra -pedantic Exercise_3_6_itoa_field_width.c -o ex3_6
 */
#include <limits.h>
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

void itoa_width(int n, char s[], int width)
{
    char digits[sizeof(int) * CHAR_BIT + 3];
    int length = 0;
    int padding;
    int i;
    unsigned int value;

    if (n < 0)
        value = 0u - (unsigned int)n;
    else
        value = (unsigned int)n;

    do {
        digits[length++] = (char)('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);

    if (n < 0)
        digits[length++] = '-';

    digits[length] = '\0';
    reverse(digits);

    padding = width - length;
    if (padding < 0)
        padding = 0;

    for (i = 0; i < padding; i++)
        s[i] = ' ';

    for (i = 0; i < length; i++)
        s[padding + i] = digits[i];

    s[padding + length] = '\0';
}

int main(void)
{
    char result[100];

    itoa_width(123, result, 8);
    printf("|%s|\n", result);

    itoa_width(-45, result, 8);
    printf("|%s|\n", result);

    itoa_width(123456, result, 3);
    printf("|%s|\n", result);

    return 0;
}
