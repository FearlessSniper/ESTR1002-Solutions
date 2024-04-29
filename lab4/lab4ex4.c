#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    int is_prime = (n==2) || (n==3) || ((n % 2 != 0) && (n % 3 != 0));
    for (long long i = 6; (i-1)*(i-1) <= n && is_prime; i+=6)
    {
        is_prime &= (n % (i-1) != 0) && (n % (i+1) != 0);
    }
    if (is_prime) {
        printf("yes");
    }
    else {
        printf("no");
    }
    return 0;
}
