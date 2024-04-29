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

int f(int human, int alien) {
    // solve base by quadratic
    int a = alien/100, b=(alien/10)%10, c=alien%10-human;
    if (a == 0 && b == 0) {
        if (human == alien) return alien+1;
        else return -1;
    }
    else if (a == 0) {
        if (c % b != 0 || -c/b <= 0) {
            return -1;
        }
        else {
            return -c/b;
        }
    } else {
        int disc = b * b - 4 * a * c;
        int sqrt_disc = isqrt(disc);
        if (sqrt_disc == -1) {
            return -1;
        }
        int sol1 = (-b + sqrt_disc)/(2*a), sol2 = (-b-sqrt_disc)/(2*a);
        int flag1 = (-b+sqrt_disc)%(2*a)==0 && sol1 > 0;
        int flag2 = (-b-sqrt_disc)%(2*a)==0 && sol2 > 0;
        if (flag1 && flag2) {
            return (sol1 < sol2)? sol1 : sol2;
        } else if (flag1 || flag2) {
            return (flag1)? sol1: sol2;
        } else {
            return -1;
        }
    }

}

int main(void) {
    // exhausive testing
    for (int i = 1; i <= 999; i++)
    {
        for (int j = 1; j <= 999; j++)
        {
            int base = f(i, j);
            if (base != -1) {
                int val = j/100*(base*base) + ((j/10)%10)*base + j%10;
                if (val != i) {
                    printf("%d %d %d\n", i, j, base);
                } else {
                    printf("OK");
                }
            }
        }
    }
    
}
