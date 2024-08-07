/*
* Exercise 1-20
* Write a program 'detab' that replaces tabs in the input with the proper number of 
* blanks to space to the next tab stop. Assume a fixed set of tab stops, say every n columns.
* Should n be a variable or a symbolic parameter?
*
* n should be a symbolic parameter as the tab stop normally isn't dynamic during program
* execution.  Also, it can be changed in one place.
*/

#include <stdio.h>

#define TAB_STOP 4


void detab(void);

int main() {
    detab();
    return 0;
}

void detab(void) {
    int c, i;

    while ((c = getchar()) != EOF) {
        if (c == '\t') {
            for (i = 0; i < TAB_STOP; ++i) {
                putchar(' ');
            }
        } else {
            putchar(c);
        }
    }
}
