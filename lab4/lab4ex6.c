#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);
    int cokes = 0;
    while (m >= 6 || n >= 3) {
        if (n >= 3) {
            n -= 2;
            cokes++;
        }
        else if (m >= 6) {
            m -= 6;
            cokes++;
            n++;
        }
    }
    printf("%d", cokes);
    return 0;
}
