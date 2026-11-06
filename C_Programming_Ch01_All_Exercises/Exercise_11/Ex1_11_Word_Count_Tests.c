#include <stdio.h>
#include <ctype.h>
#include <string.h>

typedef struct {
    const char *input;
    int expected_words;
} TestCase;

static int count_words(const char *s)
{
    int count = 0, in_word = 0;
    while (*s) {
        if (isspace((unsigned char)*s)) in_word = 0;
        else if (!in_word) { in_word = 1; ++count; }
        ++s;
    }
    return count;
}

/* Exercise 1-11: Test cases for a word-counting program.
   Cases include empty input, whitespace, one word, repeated spaces,
   tabs, newlines, punctuation, and words at the input boundaries. */
int main(void)
{
    TestCase tests[] = {
        {"", 0},
        {"     ", 0},
        {"hello", 1},
        {"hello world", 2},
        {"  hello   world  ", 2},
        {"one\ttwo\nthree", 3},
        {"a\n\nb\tc", 3},
        {"word,word! end.", 2}
    };
    int i, total = (int)(sizeof tests / sizeof tests[0]);
    int failures = 0;

    for (i = 0; i < total; ++i) {
        int actual = count_words(tests[i].input);
        printf("Test %d: expected %d, got %d — %s\n",
               i + 1, tests[i].expected_words, actual,
               actual == tests[i].expected_words ? "PASS" : "FAIL");
        if (actual != tests[i].expected_words) ++failures;
    }
    printf("%d/%d tests passed.\n", total - failures, total);
    return failures != 0;
}
