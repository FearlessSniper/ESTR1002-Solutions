#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long max(long a, long b) {
    if (a > b)
        return a;
    else
        return b;
}

long powi(long x, long n) {
    long ans = 1;
    for (int i = 0; i < n; i++) {
        ans *= x;
    }
    return ans;
}

long pyramid_num(long pyramid[24][24], int n, int i, int j) {
    if (i == n - 1)
        return pyramid[i][j];
    return pyramid[i][j] * powi(10, (n - i - 1)) +
           max(pyramid_num(pyramid, n, i + 1, j),
               pyramid_num(pyramid, n, i + 1, j + 1));
}

int main(int argc, char** argv) {
    int n;
    scanf("%d", &n);
    long pyramid[24][24];
    // Read pyramid
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i + 1; j++) {
            scanf("%ld", &(pyramid[i][j]));
        }
    }
    printf("%ld", pyramid_num(pyramid, n, 0, 0));

    return 0;
}