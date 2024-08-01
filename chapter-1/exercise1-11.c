/* 
* Exercise 1-11 
* How would you test the word count program? 
* What kinds of input are most likely to uncover bugs if there are any?
*/
#include <stdio.h>

#define IN  1 /* Inside a word */
#define OUT 0 /* Outside a word */

int main() {
    int c, nl, nw, nc, state;
    state = OUT;
    nc = nl = nw = 0;

    while ((c = getchar()) != EOF) {
        ++nc;
        if (c == '\n') {
            ++nl;
        }
        if (c == ' ' || c == '\t' || c == '\n') {
            state = OUT;
        } else if (state == OUT) {
            state = IN;
            ++nw;
        }
    }

    printf("line count: %d\nword count: %d\ncharacter count: %d\n", nl, nw, nc);
}

/*
* I would test the word count program with input that is not expected: different escape characters, i.e.'\b'.
* Different escape characters would uncover bugs since they should not be counted
* as part of words, e.g. hello\bworld would be counted all as one word.
*/
