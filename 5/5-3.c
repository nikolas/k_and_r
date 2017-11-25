#include <stdio.h>

void mystrcat(char s[], char t[]) {
    int i, j;

    i = j = 0;
    while (s[i] != '\0') {
        i++;
    }
    while ((s[i++] = t[j++]) != '\0')
        ;
}

void pointerstrcat(char *s, char *t) {
    // This is a more confusing version of the
    // confusing mystrcat function above.
    int i, j;

    i = j = 0;
    while (*(s + i) != '\0') {
        i++;
    }
    while ((*(s + i++) = *(t + j++)) != '\0')
        ;
}

int main() {
    char s[200];
    char t[100];
    s[0] = 'a';
    s[1] = 'b';
    s[2] = '\0';
    t[0] = 'd';
    pointerstrcat(s, t);

    printf("buffer: %s\n", s);
}
