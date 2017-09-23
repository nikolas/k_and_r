#include <stdio.h>
#include <ctype.h>

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

int getint(int *pn) {
    int c;
    int d;
    int sign;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    if (c == '+' || c == '-') {
        printf("handling sign\n");
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = getch();
        if (!isdigit(d)) {
            ungetch(d);
            ungetch(c);
            return c;
        }
    }

    for (*pn = 0; isdigit(c); c = getch())
        *pn = 10 * *pn + (c - '0');

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main() {
    int i = 26;
    int z = getint(&i);
    printf("getint(&i): %c\n", z);
    printf("i: %d\n", i);
}
