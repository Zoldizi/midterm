#include <stdio.h>
#include <limits.h>
#include <float.h>

/* Exercise 2-1:
   Determine ranges of char, short, int and long, signed and unsigned,
   using standard headers and direct computation. Also display floating
   point limits from float.h. */

#define SHOW_UNSIGNED(label, type, max_macro) \
    printf("%-18s size=%lu byte(s), header range: 0 .. %llu\n", \
           label, (unsigned long)sizeof(type), (unsigned long long)(max_macro))

#define SHOW_SIGNED(label, type, min_macro, max_macro) \
    printf("%-18s size=%lu byte(s), header range: %lld .. %lld\n", \
           label, (unsigned long)sizeof(type), \
           (long long)(min_macro), (long long)(max_macro))

static unsigned long long all_ones_for_bits(unsigned int bits)
{
    unsigned long long value = 0;
    unsigned int i;
    for (i = 0; i < bits && i < sizeof(unsigned long long) * CHAR_BIT; ++i)
        value = value * 2ULL + 1ULL;
    return value;
}

static void show_computed(const char *name, unsigned int bits)
{
    unsigned long long unsigned_max = all_ones_for_bits(bits);
    unsigned long long signed_max = unsigned_max / 2ULL;

    printf("%-18s %u value bits: unsigned 0 .. %llu; "
           "usual signed range: -%llu .. %llu\n",
           name, bits, unsigned_max, signed_max + 1ULL, signed_max);
}

int main(void)
{
    puts("CHARACTER / INTEGER RANGES (from standard headers)");
    SHOW_SIGNED("char", char, CHAR_MIN, CHAR_MAX);
    SHOW_SIGNED("signed char", signed char, SCHAR_MIN, SCHAR_MAX);
    SHOW_UNSIGNED("unsigned char", unsigned char, UCHAR_MAX);

    SHOW_SIGNED("short", short, SHRT_MIN, SHRT_MAX);
    SHOW_UNSIGNED("unsigned short", unsigned short, USHRT_MAX);
    SHOW_SIGNED("int", int, INT_MIN, INT_MAX);
    SHOW_UNSIGNED("unsigned int", unsigned int, UINT_MAX);
    SHOW_SIGNED("long", long, LONG_MIN, LONG_MAX);
    SHOW_UNSIGNED("unsigned long", unsigned long, ULONG_MAX);

#ifdef LLONG_MAX
    SHOW_SIGNED("long long", long long, LLONG_MIN, LLONG_MAX);
    SHOW_UNSIGNED("unsigned long long", unsigned long long, ULLONG_MAX);
#endif

    puts("\nDIRECT COMPUTATION (assuming conventional two's-complement signed integers)");
    show_computed("signed char", (unsigned int)(sizeof(signed char) * CHAR_BIT));
    show_computed("short", (unsigned int)(sizeof(short) * CHAR_BIT));
    show_computed("int", (unsigned int)(sizeof(int) * CHAR_BIT));
    show_computed("long", (unsigned int)(sizeof(long) * CHAR_BIT));

    puts("\nFLOATING-POINT LIMITS (from float.h)");
    printf("float:       FLT_MIN=%e  FLT_MAX=%e  FLT_EPSILON=%e\n",
           (double)FLT_MIN, (double)FLT_MAX, (double)FLT_EPSILON);
    printf("double:      DBL_MIN=%e  DBL_MAX=%e  DBL_EPSILON=%e\n",
           DBL_MIN, DBL_MAX, DBL_EPSILON);
    printf("long double: LDBL_MIN=%Le  LDBL_MAX=%Le  LDBL_EPSILON=%Le\n",
           LDBL_MIN, LDBL_MAX, LDBL_EPSILON);
    return 0;
}
