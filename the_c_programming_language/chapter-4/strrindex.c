#include <stdlib.h>
#include <stdio.h>
#include "../lib/strings.h"

int strrindex(char s[], char t[]);

int diffIdx(const char *s, const char *t, int tLen);

void check(char t[], int expected);

char *str = "abcdefab";

void main() {
    check("ab", 6);
    check("bc", 1);
    check("cb", -1);
    check("fa", 5);
    printf("All tests passed");
}

int strrindex(char s[], char t[]) {
    int tLen = strlen(t);
    int sLen = strlen(s);

    if (sLen < tLen) {
        return -1;
    }

    for (int i = sLen - tLen; i >= 0; i--) {
        if (diffIdx(&s[i], t, tLen) == -1) {
            return i;
        }
    }

    return -1;
}

int diffIdx(const char *s, const char *t, int tLen) {
    for (int j = 0; j < tLen; j++) {
        if (s[j] != t[j]) {
            return j;
        }
    }
    return -1;
}

void check(char t[], int expected) {
    printf("checking %s\n", t);
    int res = strrindex(str, t);
    if (res != expected) {
        printf("%d != %d\n", res, expected);
        exit(-1);
    }
}
