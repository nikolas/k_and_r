#include <ctype.h>
#include <math.h>
#include <stdio.h>

double atof(char s[]) {
    double val, eval, power, base;
    int i, sign, esign;

    for (i = 0; isspace(s[i]); i++)
        ;

    sign = (s[i] == '-') ? -1 : 1;

    if (s[i] == '+' || s[i] == '-') {
        i++;
    }

    for (val = 0.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
    }
    if (s[i] == '.') {
        i++;
    }
    for (power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0;
    }

    base = sign * val / power;

    // Check for e notation
    if (s[i] == 'e' || s[i] == 'E') {
        i++;

        esign = (s[i] == '-') ? -1 : 1;

        if (s[i] == '+' || s[i] == '-') {
            i++;
        }

        for (eval = 0.0; isdigit(s[i]); i++) {
            eval = 10.0 * eval + (s[i] - '0');
        }
        printf("eval: %f", pow(eval, 2.0));
    }
    printf("s: %c\n", s[i]);

    return base;
}

int main() {
    char s[] = "56.1412e-6";
    printf("atof(%s): %f\n", s, atof(s));
    printf("* 2 =: %f\n", atof(s) * 2);
}
