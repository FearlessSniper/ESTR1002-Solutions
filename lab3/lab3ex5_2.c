#include <stdio.h>

int from_base(int n, int base) {
    int value = 0;
    int multiplier = 1;
    while (n > 0) {
        value += (n % 10) * multiplier;
        multiplier *= base;
        n /= 10;
    }
    return value;
}

int main(void) {
    from_base(25, 13);
    int human, alien;
    scanf("%d%d", &human, &alien);
    if (alien >= 1 && alien <= 9) {
        if (alien == human) printf("10\n");
        else printf("CHEATED\n");
        // buggy here
    }
    if (human > alien) {
        // base must be > 10
        int result = from_base(alien, 11);
        int base = 11;
        while (result <= human) {
            if (result == human) {
                printf("%d\n", base);
                return 0;
            }
            base++;
            result = from_base(alien, base);
        }
        printf("CHEATED\n");
    } else if (human < alien) {
        // base must be < 10
        int result = from_base(alien, 2);
        int base = 2;
        while (result <= human) {
            if (result == human) {
                printf("%d\n", base);
                return 0;
            }
            base++;
            result = from_base(alien, base);
        }
        printf("CHEATED\n");

    } else printf("10\n");
    return 0;
}
