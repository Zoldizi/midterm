#include <stdio.h>

/* Exercise 1-15: Use a function for Fahrenheit-to-Celsius conversion. */
double fahr_to_celsius(double fahr)
{
    return (5.0 / 9.0) * (fahr - 32.0);
}

int main(void)
{
    int fahr;
    printf("Fahrenheit\tCelsius\n");
    for (fahr = 0; fahr <= 300; fahr += 20)
        printf("%10d\t%6.1f\n", fahr, fahr_to_celsius((double)fahr));
    return 0;
}
