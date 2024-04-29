#include <stdio.h>

int main() {
    long long n;
    scanf("%lld", &n);
    long long sum = 0;
    int is_prime = 1;
    while (n > 1 && is_prime)
    {
        if (n % 2 == 0)
        {
            sum += 2;
            n /= 2;
        } else if (n % 3 == 0)
        {
            sum += 3;
            n /= 3;
        } else {
            int found_prime = 0;
            int prime;
            for (size_t i = 5; i*i <= n && !found_prime; i+=6)
            {
                if (n % i == 0) {
                    prime = i;
                    found_prime = 1;
                }
                if (n % (i+2) == 0) {
                    prime = i+2;
                    found_prime = 1;
                }
            }
            if (found_prime) {
                sum += prime;
                n /= prime;
            }
            else {
                sum += n;
                is_prime = 0;
            }
        }
        
        
    }
    printf("%lld", sum);
    return 0;
}
