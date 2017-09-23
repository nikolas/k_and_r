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

int getfloat(float *pn) {
    int c;
    int d;
    int sign;
    int below_one = 0;

    while (isspace(c = getch()))
        ;

    if (!isdigit(c) && c != EOF && c != '+' && c != '-') {
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1 : 1;
    if (c == '+' || c == '-') {
        d = getch();
        if (!isdigit(d)) {
            ungetch(d);
            ungetch(c);
            return c;
        } else {
            c = d;
        }
    }

    float place = 0.1;
    for (*pn = 0; isdigit(c) || c == '.'; c = getch()) {
        if (isdigit(c) && !below_one) {
            *pn = 10 * *pn + (c - '0');
        } else if (isdigit(c) && below_one) {
            *pn = *pn + (place * (c - '0'));
            place /= 10;
        } else if (c == '.' && !below_one) {
            below_one = 1;
        }
    }

    *pn *= sign;

    if (c != EOF)
        ungetch(c);

    return c;
}

int main() {
    float f = 26.0;
    int z = getfloat(&f);
    printf("getfloat(&f): %c\n", z);
    printf("f: %f\n", f);
}
