/*
* Exercise 1-21
* Write a program 'entab' that replaces strings of blanks by the minimum number of tabs
* and blanks to achieve the same spacing.  Use the same tab stops as for 'detab'. When 
* either a tab or a single blank would suffice to reach a tab stop, which should be given
* preference?
*/

#include <stdio.h>

#define TABSTOP 8
#define MAXLINE 1000

int main() {
    int c, nb, nt, pos;

    nb = nt = pos = 0;

    while ((c = getchar()) != EOF) {
        if (c == ' ') {
            if ((pos + 1) % TABSTOP != 0) {
                ++nb;
            } else {
                nb = 0;
                ++nt;
            }
        } else {
            while (nt > 0) {
                putchar('\t');
                --nt;
            }
            if (c == '\t') {
                nb = 0;
            } else {
                while (nb > 0) {
                    putchar(' ');
                    --nb;
                }
            }

            putchar(c);

            if (c == '\n') {
                pos = -1;
            } else if (c == '\t') {
                pos = pos + (TABSTOP - pos % TABSTOP) - 1;
            }
        }
        ++pos;
    }

    return 0;
}
