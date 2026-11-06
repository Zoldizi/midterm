#include <stdio.h>
#include <ctype.h>
#include <limits.h>

/* Exercise 2-3: Convert a hexadecimal string to its integer value.
   Accepts optional 0x/0X prefix and digits 0-9, a-f, A-F.
   Returns 1 on success and 0 for invalid input or overflow. */
static int htoi(const char *s, unsigned int *result)
{
    unsigned int value = 0;
    int digit, digits = 0;

    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
        s += 2;

    while (*s != '\0') {
        unsigned char ch = (unsigned char)*s++;

        if (ch >= '0' && ch <= '9')
            digit = ch - '0';
        else if (tolower(ch) >= 'a' && tolower(ch) <= 'f')
            digit = tolower(ch) - 'a' + 10;
        else
            return 0;

        if (value > (UINT_MAX - (unsigned int)digit) / 16U)
            return 0;

        value = value * 16U + (unsigned int)digit;
        ++digits;
    }

    if (digits == 0)
        return 0;

    *result = value;
    return 1;
}

int main(void)
{
    char input[128];
    unsigned int value;

    printf("Enter a hexadecimal number: ");
    if (scanf("%127s", input) != 1)
        return 1;

    if (htoi(input, &value))
        printf("Decimal value: %u\n", value);
    else
        printf("Invalid hexadecimal number or value is too large.\n");

    return 0;
}
