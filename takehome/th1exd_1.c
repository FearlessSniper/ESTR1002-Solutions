#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    long double a, b, n;
    scanf("%Lf%Lf%Lf", &a, &b, &n);
    printf("%.0Lf", fmodl(fmodl(a, n)+fmodl(b, n), n));
    return 0;
}