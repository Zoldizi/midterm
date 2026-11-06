#include <stdio.h>
#include <limits.h>

/* Exercise 2-8: Rotate the bits of x to the right by n positions.
   Rotation is performed across the full width of unsigned int. */
static unsigned int rightrot(unsigned int x, unsigned int n)
{
    const unsigned int width = (unsigned int)(sizeof(unsigned int) * CHAR_BIT);

    n %= width;
    if (n == 0U)
        return x;

    return (x >> n) | (x << (width - n));
}

int main(void)
{
    unsigned int x, n;
    printf("Enter x and rotation count n: ");
    if (scanf("%u %u", &x, &n) != 2)
        return 1;

    printf("Result: %u (0x%X)\n", rightrot(x, n), rightrot(x, n));
    return 0;
}
