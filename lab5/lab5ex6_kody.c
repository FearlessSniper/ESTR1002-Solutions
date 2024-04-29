#include <stdio.h>

#include <stdlib.h>

// needed for memset
#include <string.h>

#include <math.h>

int main(void) {
    int i, j, sqrtN;
    int a, b, c;
    int sum = 0;
    int prime[10000]; // warning: overflows on TC3; increase size
    scanf("%d%d%d", &a, &b, &c);
    char sieve[2000000 + 1];
    memset(sieve, 1, b + 1);
    sqrtN = (unsigned int)(sqrt(b) + 0.5);
    for (i = 2; i <= sqrtN; i++) {
        if (sieve[i] == 1) {
            for (j = i + i; j <= b; j += i)
                sieve[j] = 0;
        }
    }
    // sieve[i] is 1 if prime; else composite
    // Below: list all prime numbers and put it in prime[]
    // d: running count of primes
    int prime_count = 0;
    for (i = 2; i <= b; i++) {
        if (sieve[i] == 1) {
            prime[prime_count] = i;
            prime_count++;
        }
    }
    for (i = a; i <= b; i++) {
        // g == 1
        // f: prime count for prime[]
        // counter: factor count for a
        int factor_count = 0; // fix#1: need to reset counter for each number
        for (j=0; j < prime_count; j++) { // fix#2: bc d is added 1 before assigned to f, f is 1 more than number of primes in prime[]
            if (i % prime[j] == 0)
                factor_count++;
            if (factor_count > c)
                break;
        }
        if (factor_count == c)
            sum++;
    }
    printf("%d", sum);
    return 0;
}