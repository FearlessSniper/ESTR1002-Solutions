#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int compare_char(const void* a, const void* b) {
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;
    if (arg1 < arg2)
        return -1;
    if (arg1 > arg2)
        return 1;
    return 0;
}

void gen(char* digits, int n_digits, int state, char* cur) {
    for (int i = 0; i < n_digits; i++) {
        if (state == 0 &&
            !(digits[i] == '2' || digits[i] == '3' || digits[i] == '5' || 
             digits[i] == '6' || digits[i] == '7' || digits[i] == '9')) {
            continue;
        }
        cur[state] = digits[i];
        if (state == 7) {
            printf("%s", cur);
            if (strncmp(cur, "3943", 4) == 0) {
                printf(" CUHK");
            }
            printf("\n");
        } else {
            gen(digits, n_digits, state + 1, cur);
        }
    }
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    char digits[5];
    for (int i = 0; i < n; i++) {
        scanf(" %c", &digits[i]);
    }
    qsort(digits, n, sizeof(char), compare_char);
    char cur[9] = {0};
    gen(digits, n, 0, cur);
    return 0;
}