/*
* Exercise 1-18
* Write a program to remove trailing blanks and tabs from each line of input, and to 
* delete entirely blank lines.
*/

#include <stdio.h>
#define MAXLINE 1000

void trim(char line[], int length);
int mygetline(char line[], int limit);

int main() {
    int len, i;
    char line[MAXLINE];

    while ((len = mygetline(line, MAXLINE)) > 0) {
        trim(line, len);
        printf("%s", line);
    }
}

int mygetline(char line[], int limit) {
    int c, i;

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

void trim(char line[], int length) {
    int i;
    i = length - 1;

    if (line[i] == '\n') {
        --i;
    }

    while (i >= 0  && (line[i] == ' ' || line[i] == '\t')) {
        --i;
    }

    if (i >= 0 && line[length - 1] == '\n') {
        line[i + 1] = '\n';
        line[i + 2] = '\0';
    } else {
        line[i + 1] = '\0';
    }

}
