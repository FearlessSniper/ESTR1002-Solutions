#include <stdio.h>

int main() {
    int pow;
    scanf("%d", &pow);
    long acc = 1;
    for (int i = 0; i <= pow; i++)
    {
        printf("3^%d=%ld\n", i, acc);
        acc *= 3;
    }
    
}