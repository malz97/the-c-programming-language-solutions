/*
* Exercise 1-22
* Write a program to "fold" long input lines into two or more shorter lines after the
* last non-blank character that occurs before the n-th column of input. Make sure your
* program does something intelligent with very long lines, and if there are no blanks
* or tabs before the specified column.
*/

#include <stdio.h>

#define FOLD_LENGTH 20
#define TABSTOP 8
#define MAXLINE 1000

int mygetline(char s[], int limit);
void fold(char s[], int len);

int main() {
    char line[MAXLINE];
    int len;

    while ((len = mygetline(line, MAXLINE)) > 0) {
        fold(line, len);
    }
    return 0;
}

int mygetline(char s[], int limit) {
    int c, i;

    for (i = 0; i < limit - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        ++i;
    }

    s[i] = '\0';

    return i;
}

void fold(char s[], int len) {
    int i, j, column, last_blank;
    column = 0;
    last_blank = -1;

    for (i = 0; i < len; ++i) {
        if (s[i] == '\t') {
            column = column + (TABSTOP - (column % TABSTOP));
        } else {
            ++column;
        }

        if (s[i] == ' ' || s[i] == '\t') {
            last_blank = i;
        }

        if (column > FOLD_LENGTH) {
            if (last_blank > -1) {
                s[last_blank] = '\n';
                i = last_blank - 1;
            } else {
                putchar('\n');
                --i;
            }
            column = 0;
            last_blank = -1;
        } else {
            putchar(s[i]);
        } 

        if (s[i] == '\n') {
            column = 0;
        }
    }
}
