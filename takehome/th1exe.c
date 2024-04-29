#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

typedef unsigned long long ull;

unsigned long long ullsqrt(unsigned long long x) {
    ull left = 0ull;
    ull right = 4294967296ull;
    while (right - left > 1) {
        ull mid = (left + right) / 2;
        if (mid * mid > x) {
            right = mid;
        } else left = mid;
    }
    return left;
}

int main(int argc, char **argv) {
    unsigned long long n;
    scanf("%llu", &n);
    unsigned long long sqrt_n = ullsqrt(n);
    ull sqrl = sqrt_n * sqrt_n;
    if (sqrl == n) printf("%llu", sqrl);
    else {
        ull sqrh = (sqrt_n + 1) * (sqrt_n + 1);
        if (n - sqrl < sqrh - n) {
            printf("%llu", sqrl);
        } else {
            printf("%llu", sqrh);
        }
    }
    return 0;
}