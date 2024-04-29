#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>

int main(int argc, char **argv) {
    int alpha[26]; // alpha: AaBb...
    for (int i = 0; i < 26; i++) {
        alpha[i] = 0;
    }
    int max = -1;
    char c;
    while ((c = getchar()) != '\n') {
        if (isalpha(c)) {
            int index = tolower(c)-'a';
            alpha[index]++;
            if (alpha[index] > max) {
                max = alpha[index];
            }
        }
    }
    for (int i = 0; i < 26; i++) {
        if (alpha[i] == max) {
            printf("%c ", i+'a');
        }
    }
    printf("%d", max);
    return 0;
}
