#include <stdio.h>
#include <math.h>

// return sqrt of x if sqrt is integer
// else return -1
int isqrt(int x) {
    int n = 0;
    while (n * n < x) {
        n++;
    }
    if (n * n == x) return n;
    else return -1;
}

int main(void) {
    int human, alien;
    scanf("%d%d", &human, &alien);
    // solve base by quadratic
    int a = alien/100, b=(alien/10)%10, c=alien%10;
    if (a == 0 && b == 0) {
        if (human == alien) printf("%d\n", alien+1);
        else printf("CHEATED\n");
    }
    else if (a == 0) {
        int base = (human-c)/b;
        if ((human-c) % b != 0 || base <= 0 || (base < 10 && (base <= c || base <= b))) {
            printf("CHEATED\n");
        }
        else {
            printf("%d\n", base);
        }
    } else {
        int unit_digit = c;
        c -= human; // use unit_digit for unit digit instead of c; c becomes c in quadratic
        int disc = b * b - 4 * a * c;
        int sqrt_disc = isqrt(disc);
        if (sqrt_disc == -1) {
            printf("CHEATED\n");
            return 0;
        }
        int sol1 = (-b + sqrt_disc)/(2*a), sol2 = (-b-sqrt_disc)/(2*a);
        int flag1 = (-b+sqrt_disc)%(2*a)==0 && sol1 > 0;
        int flag2 = (-b-sqrt_disc)%(2*a)==0 && sol2 > 0;
        if (sol1 < 10) {
            flag1 &= sol1 > a && sol1 > b && sol1 > unit_digit;
        }
        if (sol2 < 10) {
            flag2 &= sol2 > a && sol2 > b && sol2 > unit_digit;
        }
        if (flag1 && flag2) {
            printf("%d", (sol1 < sol2)? sol1 : sol2);
        } else if (flag1 || flag2) {
            printf("%d", (flag1)? sol1: sol2);
        } else {
            printf("CHEATED\n");
        }
    }
    return 0;
}
