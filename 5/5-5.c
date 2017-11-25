#include <stdio.h>

void mystrncat(char *s, char *t, int n) {
    int i, j, x;

    i = j = 0;
    while (*(s + i) != '\0') {
        i++;
    }

    x = 1;
    while ((*(s + i++) = *(t + j++)) != '\0' && x < n) {
        x++;
    }
}

int main() {
    char a[100] = "abc";
    char b[100] = "defghijklmnop";

    mystrncat(a, b, 5);
    printf("strncat: %s, %s\n", a, b);
}
