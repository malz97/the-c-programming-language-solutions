/*
* Write a program to count blanks, tabs, and newlines.
*/

#include <stdio.h>

int main() {
    int c, nl, tabs, blanks;
    nl = 0;
    tabs = 0;
    blanks = 0;
    while ((c = getchar()) != EOF) {
        if (c == '\n') {
            ++nl;
        }
        if (c == '\t') {
            ++tabs;
        }
        if (c == ' ') {
            ++blanks;
        }
    }

    printf("\n");
    printf("New lines: %d\n", nl);
    printf("Tabs: %d\n", tabs);
    printf("Blanks: %d\n", blanks);
}
