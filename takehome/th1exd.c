#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

typedef unsigned long long ull;

ull mod(ull a, ull b) {
    return a - b * (a / b);
}

int main(int argc, char **argv) {
    unsigned long long a, b, n;
    scanf("%llu%llu%llu", &a, &b, &n);
    printf("%llu", mod(mod(a, n)+mod(b, n), n));
    return 0;
}