#include <stdio.h>
#include <limits.h>

/* Exercise 2-6: Return x with n bits beginning at position p replaced
   by the rightmost n bits of y. Bit positions are counted from 0 at
   the least-significant bit. */
static unsigned int setbits(unsigned int x, unsigned int p,
                            unsigned int n, unsigned int y)
{
    const unsigned int width = (unsigned int)(sizeof(unsigned int) * CHAR_BIT);
    unsigned int i, mask = 0U, field = 0U;

    if (n == 0U || p >= width || n > p + 1U)
        return x;
    if (n == width)
        mask = UINT_MAX;
    else
        for (i = 0; i < n; ++i)
            mask |= 1U << i;

    field = (y & mask) << (p + 1U - n);
    mask <<= (p + 1U - n);
    return (x & ~mask) | field;
}

int main(void)
{
    unsigned int x, p, n, y;
    printf("Enter x, p, n, y (unsigned integers): ");
    if (scanf("%u %u %u %u", &x, &p, &n, &y) != 4)
        return 1;
    printf("Result: %u (0x%X)\n", setbits(x, p, n, y),
           setbits(x, p, n, y));
    return 0;
}
