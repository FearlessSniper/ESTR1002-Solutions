#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define DIGITS 2000

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int sum(unsigned char *a, int a_digits, unsigned char *b, int b_digits, unsigned char *c) {
    int max_digits = max(a_digits, b_digits) + 1;
    c[DIGITS-1] = 0;
    int i;
    for (i = DIGITS-1; i > DIGITS-max_digits; i--)
    {
        div_t dv = div(a[i] + b[i] + c[i], 10);
        c[i] = dv.rem;
        c[i-1] = dv.quot;
    }
    if (c[i] != 0) return max_digits;
    else return max_digits-1;
}

int multip(unsigned char *a, int a_digits, int b, unsigned char *c) {
    unsigned char ans[DIGITS] = {0};
    unsigned char a1[DIGITS] = {0};
    int a1_digits = 0;
    for (int i = 0; i < b; i++)
    {
        a1_digits = sum(a, a_digits, a1, a1_digits, c);
        memcpy(a1, c, sizeof(unsigned char[DIGITS]));
    }
    return a1_digits;
}


int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    unsigned char a[DIGITS] = {0};
    a[DIGITS-1] = 1;
    int a_digits = 1;
    unsigned char b[DIGITS] = {0};
    for (int i = 1; i <= n; i++)
    {
        a_digits = multip(a, a_digits, i, b);
        memcpy(a, b, sizeof(unsigned char [DIGITS]));
    }
    for (int i = DIGITS-a_digits; i < DIGITS; i++)
    {
        putchar(a[i]+'0');
    }
    
    return 0;
}