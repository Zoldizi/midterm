#include <stdio.h>

/* Exercise 1-4: Print the Celsius-Fahrenheit table. */
int main(void)
{
    int celsius;
    printf("Celsius\tFahrenheit\n");
    for (celsius = 0; celsius <= 300; celsius += 20) {
        double fahr = (9.0 / 5.0) * celsius + 32.0;
        printf("%7d\t%10.1f\n", celsius, fahr);
    }
    return 0;
}
