/*
* Exercise 1-17
* Write a program to print all input lines that are longer than 80 characters.
*/

#include <stdio.h>
#define MAXLINE 1000
#define CUTOFF  80

int mygetline(char line[], int limit);

int main() {
    int len;
    char line[MAXLINE];

    printf("Lines that contain more than %d characters:\n", CUTOFF);
    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > CUTOFF) {
            printf("%s", line);
        }
    }

    return 0;
}

int mygetline(char line[], int limit) {
    int i, c;
    
    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        line[i] = c;
    }

    if (c == '\n') {
        line[i] = c;
        ++i;
    }
    
    line[i] = '\0';

    return i;
}
