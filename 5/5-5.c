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

void mystrncmp(char *s, char *t, int n) {
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

    mystrncpy(a, b, 50);
    printf("strncpy: %s, %s\n", a, b);
}
