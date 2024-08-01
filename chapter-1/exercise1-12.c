/*
* Exercise 1-12
* Write a program that prints its input one word per line.
*/

#include <stdio.h>

#define IN  1
#define OUT 0

int main() {
    int c, state;
    c = 0;
    state = OUT;

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
            putchar('\n');
        } else if (state == OUT) {
            putchar(c);
            state = IN;
        } else if (state == IN) {
            putchar(c);
        }
    }
}
