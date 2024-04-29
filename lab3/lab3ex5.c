#include <stdio.h>

int reverse_number(int n) {
    int ans = 0;
    while (n > 0) {
        ans *= 10;
        ans += n % 10;
        n /= 10;
    }
    return ans;
}

int convert_base(int n, int base) {
    int ans = 0;
    int is_leading = 1;
    int lead_zeros = 0;
    while (n > 0) {
        ans *= 10;
        int digit = n % base;
        is_leading &= (digit == 0);
        if (is_leading && digit == 0) lead_zeros++;
        if (digit > 9) return -1;
        ans += digit;
        n /= base;
    }
    int t = reverse_number(ans);
    for (int i = 0; i < lead_zeros; i++) {
        t *= 10;
    }
    return t;
}


int main() {
    int human, alien;
    scanf("%d%d", &human, &alien);
    if (human == 1) {
        if (alien == 1) {
            printf("2\n");
            return 0;
        }
    }
    for (int base = 2; base <= human; base++) {
        int result = convert_base(human, base);
        if (result == alien) {
            printf("%d\n", base);
            return 0;
        }
        if (result < alien) break;
    }
    printf("CHEATED\n");
    return 0;
}
