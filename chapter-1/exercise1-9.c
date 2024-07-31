/*
* Exercise 1-9.
* Write a program to copy its input to its output, replacing each string
* of one or more blanks by a single blank
*/

#include <stdio.h>

int main() {
    int c, blanks;
    blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c != ' ' || (c == ' ' && blanks < 1)) {
            putchar(c);
        }
        if (c == ' ') {
            ++blanks;
        } else {
            blanks = 0;
        }
    }
}
