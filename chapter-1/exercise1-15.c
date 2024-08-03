/*
* Exercise 1.15
* Rewrite the temperature conversion program of Section 1.2 to use a function 
* for conversion.
*/

#include <stdio.h>

#define LOWER  0
#define UPPER  120
#define STEP   5 

float convertToCelsius(float fahr);

int main() {
    float fahr, celsius;

    printf("Fahrenheit - Celsius Conversion Table\n");
    printf("=====================================\n");
    printf("\t%10s\t%10s\t\t\n", "Fahrenheit", "Celsius");
    printf("=====================================\n");

    fahr = LOWER;
    while (fahr <= UPPER) {
        celsius = convertToCelsius(fahr);
        printf("\t%10.0f\t%10.1f\t\n", fahr, celsius);
        fahr = fahr + STEP;
    }

    printf("=====================================\n");
}


float convertToCelsius(float fahr) {
    return (5.0/9.0) * (fahr - 32);
}
