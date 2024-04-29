#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int eq_slope(long long x1, long long y1, long long x2, long long y2, long long x3, long long y3) {
    long long lhs = y3 * x2 - y3 * x1 - y1 * x2;
    long long rhs = x3 * y2 - x3 * y1 - x1 * y2;
    return lhs == rhs;
}

double pl_distance(double x1, double y1, double x2, double y2, double x3, double y3) {
    double A = y2-y1, B = x1-x2, C = y1 * (x2-x1) - x1 * (y2-y1);
    return fabs(A * x3 + B * y3 + C) / sqrt(A * A + B * B);
}

int main(int argc, char **argv) {
    int a, b, c, d, e, f;
    scanf("%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f);
    if (eq_slope(a, b, c, d, e, f)) {
        printf("Online!\n");
    } else {
        printf("%.4f\n", pl_distance(a, b, c, d, e, f));
    }
    return 0;
}