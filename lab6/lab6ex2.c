#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char **argv) {
    char c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c) || c == '-') {
            putchar(tolower(c));
        }
    }
    return 0;
}
