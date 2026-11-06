#include <stdio.h>

/* Exercise 1-5: Print the temperature table from 300 down to 0. */
int main(void)
{
    int fahr;
    printf("Fahrenheit\tCelsius\n");
    for (fahr = 300; fahr >= 0; fahr -= 20) {
        double celsius = (5.0 / 9.0) * (fahr - 32);
        printf("%10d\t%6.1f\n", fahr, celsius);
    }
    return 0;
}
