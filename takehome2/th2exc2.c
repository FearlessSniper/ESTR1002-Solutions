#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int max(int a, int b) {
    if (a > b) return a;
    else return b;
}

int sum(unsigned char *a, int a_digits, unsigned char *b, int b_digits, unsigned char *c) {
    int max_digits = max(a_digits, b_digits) + 1;
    c[999] = 0;
    int i;
    for (i = 999; i > 1000-max_digits; i--)
    {
        div_t dv = div(a[i] + b[i], 10);
        c[i] += dv.rem;
        c[i-1] = dv.quot;
    }
    if (c[i] != 0) return max_digits;
    else return max_digits-1;
}


int main(int argc, char **argv) {
    unsigned char a[1000] = {0};
    unsigned char b[1000] = {0};
    unsigned char c[1000] = {0};
    a[999] = 1;
    b[999] = 1;
    unsigned char *nums[3] = {a, b, c};
    int n_digits[3] = {1, 1, sum(nums[0], 1, nums[1], 1, nums[2])};
    // n digits = 1000 - sum + 1
    int n;
    scanf("%d", &n);
    int i;
    for (i = 3; n_digits[2] < n; i++)
    {
        // Circular shift the numbers
        unsigned char *first = nums[0];
        nums[0] = nums[1];
        nums[1] = nums[2];
        nums[2] = first;
        // Circular shift the number of digits
        n_digits[0] = n_digits[1];
        n_digits[1] = n_digits[2];
        n_digits[2] = sum(nums[0], n_digits[0], nums[1], n_digits[1], nums[2]);
    }
    if (n == 1) printf("1");
    else printf("%d", i);
    return 0;
}