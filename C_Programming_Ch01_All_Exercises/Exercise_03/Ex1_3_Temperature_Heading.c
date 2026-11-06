#include <stdio.h>

/* Exercise 1-3: Add a heading to the Fahrenheit-Celsius table. */
int main(void)
{
    int fahr;
    printf("Fahrenheit\tCelsius\n");
    for (fahr = 0; fahr <= 300; fahr += 20) {
        double celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%10d\t%6.1f\n", fahr, celsius);
    }
    return 0;
}
