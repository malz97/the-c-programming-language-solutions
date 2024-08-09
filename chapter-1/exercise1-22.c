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


int mygetline(char s[], int lim);
void fold(char s[], int len);

int main() {
    int len;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        if (len > FOLD_LENGTH) {
            fold(line, len);
        } else {
            printf("%s", line);
        }
    }
    return 0;
}

int mygetline(char s[], int lim) {
    int c, i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != ' '; ++i) {
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
    int i, last_blank, column;

    last_blank = column = 0;
    for (i = 0; i < len; ++i) {
        if (s[i] == ' ' || s[i] == '\t') {
            last_blank = i;
        }
        ++column;
        if (column > FOLD_LENGTH) {
            if (last_blank > 0) {
                s[last_blank] = '\n';
                column = i - last_blank;
                last_blank = 0;
            } else {
                printf("\n");
                column = 1;
            }
        }
        putchar(s[i]);
    }
}
