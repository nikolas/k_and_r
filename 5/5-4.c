#include <stdio.h>

/**
 * Returns 1 if string s ends with string t, otherwise 0.
 */
int strend(char *s, char *t) {
    int i = 0;
    int j = 0;

    while (*(s + i) != '\0') {
        while (*(s + i + j) == *(t + j)) {
            if (*(s + i + j + 1) == '\0' && *(t + j + 1) == '\0') {
                // Got to the end of both strings, return 1.
                return 1;
            }

            j++;
        }

        j = 0;
        i++;
    }

    return 0;
}

int main() {
    char *a = "abc";
    char *b = "bc";

    printf("strend: %d\n", strend(a, b));
}
