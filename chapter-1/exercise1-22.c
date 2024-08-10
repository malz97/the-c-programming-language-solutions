/*
* Exercise 1-22
* Write a program to "fold" long input lines into two or more shorter lines after the
* last non-blank character that occurs before the n-th column of input. Make sure your
* program does something intelligent with very long lines, and if there are no blanks
* or tabs before the specified column.
*/

#include <stdio.h>

#define FOLD_LENGTH 20
#define MAXLINE 1000
#define TABSTOP 8


int mygetline(char s[], int lim);
void detab(char to[], char from[]);

int main() {
    int len;
    char line[MAXLINE];
    char detabbed[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        detab(detabbed, line);
        printf("%s", detabbed);
    }

    return 0;
}

int mygetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void detab(char to[], char from[]) {
    int i, j, pos, spaces;

    pos = 0;
    for (i = 0; from[i] != '\0'; ++i) {
        if (from[i] == '\t') {
            spaces = TABSTOP - (pos % TABSTOP);
            for (j = 0; j < spaces; ++j) {
                to[pos] = ' ';
                ++pos;
            }
        } else {
            to[pos] = from[i];
            ++pos;
        }
    }

    to[pos] = '\0';
}
