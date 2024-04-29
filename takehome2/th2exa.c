#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    int x, c;
    scanf("%d%d", &x, &c);
    int total_milk = 0;
    int milk = x / c;
    while (milk > 0)
    {
        x = x % c + milk;
        total_milk += milk;
        milk = x / c;
    }
    printf("%d", total_milk);
    
    return 0;
}