/*
* Exercise 1-13
* Write a program to print a histogram of the lengths of words in its input. It is easy
* to draw the histogram with the bars horizontal; a vertical orientation is more challenging.
*/

#include <stdio.h>

#define IN  1
#define OUT 0
#define MAX_WORD_LENGTH 25

int main() {
    int c, i, j, state, length;
    int lengths[MAX_WORD_LENGTH];

    state = OUT;
    length = 0;
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        lengths[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c == ' ' || c == '\n' || c == '\t') {
            state = OUT;
            if (length < MAX_WORD_LENGTH) {
                ++lengths[length];
            } else {
                ++lengths[MAX_WORD_LENGTH - 1];
            }
            length = 0;
        } else if (state == OUT) {
            state = IN;
        }

        if (state == IN) {
            ++length;
        }
    }

    printf("\n");
    for (i = 0; i < MAX_WORD_LENGTH; ++i) {
        printf("%2d: ", i);
        for (j = 0; j < lengths[i]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
