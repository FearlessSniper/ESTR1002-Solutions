#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    long double phi = (1 + sqrtl(5))/2;
    int x = ceill((n - 1 + .5 * log10l(5)) / log10l(phi));
    printf("%d", x);
    return 0;
}