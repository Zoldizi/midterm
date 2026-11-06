/*
 * Exercise 3-4
 * Convert any int value to a decimal string, including the minimum int.
 * The negative value is never negated as a signed int.
 * Compile: gcc -std=c99 -Wall -Wextra -pedantic Exercise_3_4_itoa_INT_MIN.c -o ex3_4
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

void itoa_safe(int n, char s[])
{
    unsigned int value;
    int i = 0;

    if (n < 0)
        value = 0u - (unsigned int)n;
    else
        value = (unsigned int)n;

    do {
        s[i++] = (char)('0' + value % 10u);
        value /= 10u;
    } while (value != 0u);

    if (n < 0)
        s[i++] = '-';

    s[i] = '\0';
    reverse(s);
}

int main(void)
{
    char text[50];

    itoa_safe(0, text);
    printf("0 -> %s\n", text);

    itoa_safe(-12345, text);
    printf("-12345 -> %s\n", text);

    itoa_safe(2147483647, text);
    printf("2147483647 -> %s\n", text);

    itoa_safe((-2147483647 - 1), text);
    printf("minimum int -> %s\n", text);

    return 0;
}
