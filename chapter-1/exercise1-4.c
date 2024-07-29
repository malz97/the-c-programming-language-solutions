/*
    Exercise 1-4. 
    Write a program to print the corresponding Celsius to Fahrenheit table.
*/

#include <stdio.h>

int main() {
    float fahr, celsius;
    float lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    celsius = lower;
    printf("%3c\t%6c\n%10s\n", 'C', 'F', "----------------");
    while (celsius <= upper) {
        fahr = (9.0/5.0) * celsius + 32.0;
        printf("%3.0f\t%6.0f\n", celsius, fahr);
        celsius = celsius + step;
    }
}
