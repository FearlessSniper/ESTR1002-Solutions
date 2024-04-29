#include <stdio.h>

int main() {
    int a, b, m;
    scanf("%d%d%d", &a, &b, &m);
    if (b >= a) {
        int i;
        for (i = a; i <= b-1; i++) {
            if (i % m == 0) {
                printf("#, ");
            }
            else printf("%d, ", i);
        }
        if (i % m == 0) {
            printf("#");
        }
        else printf("%d", i);
    }
    else {
        printf("no numbers");
    }
    return 0;
}