/*
* Exercise 1-16
* Revise the main routine of the longest-line program so it will correctly print the 
* length of arbitrary long input lines, and as much as possible of the text.
*/

#include <stdio.h>
#define MAXLINE 100

int getLine(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max; 
    int c;
    char line[MAXLINE];
    char longest[MAXLINE];

    max = 0;

    while ((len = getLine(line, MAXLINE)) > 0) {
        if (len == MAXLINE - 1 && line[len - 1] != '\n') {
            while ((c = getchar()) != EOF && c != '\n') {
                ++len;
            }
        }
        if (len > max) {
            max = len;
            copy(longest, line);
        }
    }

    if (max > 0) {
        printf("\n");
        printf("Longest line (buffer size: 100 characters): %s\n", longest);
        printf("Length: %d\n", max);
    }

    return 0;
}

int getLine(char s[], int limit) {
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        ++i;
    }
}

