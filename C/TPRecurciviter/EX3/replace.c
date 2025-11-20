//
// Created by louis.tanchou on 20/11/2025.
//

#include <stdio.h>
#include <stdlib.h>

char* replace(char* s, char c, char d, int i)
{
    if (s == NULL || s[i] == '\0') {
        return s;
    }

    if (s[i] == c) {
        s[i] = d;
    }

    return replace(s, c, d, i + 1);
}

int main() {
    char str[] = "hello world";
    char c = 'o';
    char d = 'a';

    printf("Original string: %s\n", str);
    replace(str, c, d, 0);
    printf("Modified string: %s\n", str);

    return 0;
}