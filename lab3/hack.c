#include <stdio.h>

int isqrt(int x) {
    int n = 0;
    while (n * n < x) {
        n++;
    }
    if (n * n == x) return n;
    else return -1;
}

int main() {
    printf("%d", -8 % -2);
    return 0;
}
