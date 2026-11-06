#include <stdio.h>

/* Exercise 2-5: Return the first index in s1 containing any character
   from s2, or -1 if there is no match. */
static int any(const char s1[], const char s2[])
{
    int i, j;
    for (i = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0'; ++j) {
            if (s1[i] == s2[j])
                return i;
        }
    }
    return -1;
}

int main(void)
{
    char first[256], second[256];
    int position, i;

    printf("Enter the first string: ");
    if (!fgets(first, sizeof first, stdin)) return 1;
    printf("Enter the character set to search for: ");
    if (!fgets(second, sizeof second, stdin)) return 1;

    for (i = 0; first[i] != '\0'; ++i)
        if (first[i] == '\n') { first[i] = '\0'; break; }
    for (i = 0; second[i] != '\0'; ++i)
        if (second[i] == '\n') { second[i] = '\0'; break; }

    position = any(first, second);
    printf("First matching position: %d\n", position);
    return 0;
}
