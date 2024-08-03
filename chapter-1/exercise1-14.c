/*
* Exercise 1-14
* Write a program to print a histogram of the frequencies of different characters 
* in its input.
*/

#define START    33
#define END      126
#define MAX_SIZE END - START + 1

#include <stdio.h>

int main() {
    int c, i, j, index;
    int frequencies[MAX_SIZE];

    for (i = 0; i < MAX_SIZE; ++i) {
        frequencies[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        index = c - '!';
        if (index >= 0 && index < MAX_SIZE) {
            ++frequencies[index];
        }
    }

    printf("\n");
    for (i = START; i < END + 1; ++i) {
        index = i - '!';
        printf("%c: ", i);
        for (j = 0; j < frequencies[index]; ++j) {
            printf("*");
        }
        printf("\n");
    }
}
