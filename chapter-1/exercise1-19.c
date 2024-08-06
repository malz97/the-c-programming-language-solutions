/*
* Exercise 1-19
* Write a function reverse(s) that reverse the character string s. Use it to write a
* program that reverses its input a line at a time.
*/

#include <stdio.h>
#define MAXLINE 1000

void reverse(char s[]);
int mygetline(char s[], int limit);

int main() {
    char line[MAXLINE];
    int len;
    
    while ((len = mygetline(line, MAXLINE)) > 0) {
        reverse(line);
        printf("%s\n", line);
    }

    return 0;
}

void reverse(char s[]) {
    int i, j;
    char temp;
    
    i = j = 0;
    while (s[j] != '\0') {
        ++j;
    }
    
    --j;

    if (s[j] == '\n') {
        --j;
    }

    while (i < j) {
        temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        --j;
        ++i;
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
