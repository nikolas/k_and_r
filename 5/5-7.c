#include <stdio.h>
#include <string.h>
#include "alloc.h"
#include "getlinef.h"

#define MAXLEN 1000

int readlines(char *lineptr[], int maxlines) {
    int len, nlines;
    char *p, line[MAXLEN];

    nlines = 0;
    while ((len = getlinef(line, MAXLEN)) > 0) {
        if (nlines >= maxlines || (p = alloc(len)) == NULL) {
            return -1;
        } else {
            line[len-1] = '\0';
            strcpy(p, line);
            lineptr[nlines++] = p;
        }
    }

    return nlines;
}

int main() {
    char *s[100];

    printf("reading...\n");
    printf("nlines: %d\n", readlines(s, 100));
}
