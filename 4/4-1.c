#include <stdio.h>
#include <string.h>

int strrindex(char s[], char t[]) {
    int i, j, k;

    int slen = strlen(s);
    int tlen = strlen(t);

    char buf[666];

    // The last character it can possibly match is
    // at slen - tlen
    for (i = (slen - tlen); i >= 0; i--) {
        strncpy(buf, s + (sizeof(char) * i), tlen);
        if (strncmp(buf, t, tlen) == 0) {
            printf("Match - %d\n", i);
            return i;
        }
    }

    return -1;
}

int main() {
    printf("strrindex(babcdef, abc): %d\n", strrindex("abcbabcdef", "abc"));
}
