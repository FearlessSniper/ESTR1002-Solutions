#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

char sieve[2000001]; // max n: 2000000

int main() {
	int n;
	scanf("%d", &n);
	memset(sieve, 1, 2000001);
	int sqrtN = (int)ceil(sqrt(n));
	long sum = 0;
	int i;
	for (i = 2; i <= sqrtN; i++) {
		if (sieve[i] == 1) {
			sum += i;
			for (int j = i + i; j <= n; j += i) {
				sieve[j] = 0;
			}
		}
	}
	for (i; i <= n; i++) {
		if (sieve[i]) sum += i;
	}
	printf("%ld", sum);
	return 0;
}