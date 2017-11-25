#include <stdio.h>

void mystrncpy(char *dest, char *src, int n) {
    int i, x;

    i = 0;
    while ((*(dest + i) = *(src + i)) != '\0' && i < (n - 1)) {
        i++;
    }
}

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

int mystrncmp(char *s1, char *s2, int n) {
    int i;

    for (i = 0; i < (n - 1); i++) {
        if (*(s1 + i) > *(s2 + i)) {
            return 1;
        } else if (*(s1 + i) < *(s2 + i)) {
            return -1;
        }
    }

    return 0;
}

int main() {
    char a[100] = "abcz abc";
    char b[100] = "abc abc";

    printf("strncmp: %d\n", mystrncmp(a, b, 3));
}
