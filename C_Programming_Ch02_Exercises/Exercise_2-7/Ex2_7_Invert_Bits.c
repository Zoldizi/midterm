#include <stdio.h>
#include <limits.h>

/* Exercise 2-7: Invert n bits beginning at position p in x.
   Bit positions are counted from 0 at the least-significant bit. */
static unsigned int invert(unsigned int x, unsigned int p, unsigned int n)
{
    const unsigned int width = (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int i, mask = 0U;

    if (n == 0U || p >= width || n > p + 1U)
        return x;

    for (i = 0; i < n; ++i)
        mask |= 1U << i;

    mask <<= (p + 1U - n);
    return x ^ mask;
}

int main(void)
{
    unsigned int x, p, n, result;
    printf("Enter x, p, n (unsigned integers): ");
    if (scanf("%u %u %u", &x, &p, &n) != 3)
        return 1;

    result = invert(x, p, n);
    printf("Result: %u (0x%X)\n", result, result);
    return 0;
}
