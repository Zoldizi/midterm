#include <stdio.h>

/* Exercise 2-4: Delete from s1 every character that occurs in s2. */
static void squeeze(char s1[], const char s2[])
{
    int i, j, k;

    for (i = k = 0; s1[i] != '\0'; ++i) {
        for (j = 0; s2[j] != '\0' && s1[i] != s2[j]; ++j)
            ;
        if (s2[j] == '\0')
            s1[k++] = s1[i];
    }
    s1[k] = '\0';
}

int main(void)
{
    char text[256], remove[256];

    printf("Enter the first string: ");
    if (!fgets(text, sizeof text, stdin)) return 1;
    printf("Enter characters to remove: ");
    if (!fgets(remove, sizeof remove, stdin)) return 1;

    /* Remove the newline characters read by fgets. */
    {
        int i;
        for (i = 0; text[i] != '\0'; ++i)
            if (text[i] == '\n') { text[i] = '\0'; break; }
        for (i = 0; remove[i] != '\0'; ++i)
            if (remove[i] == '\n') { remove[i] = '\0'; break; }
    }

    squeeze(text, remove);
    printf("Result: %s\n", text);
    return 0;
}
