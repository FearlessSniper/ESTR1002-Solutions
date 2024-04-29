#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    int d[4];
    scanf("%d.%d.%d.%d", &d[0], &d[1], &d[2], &d[3]);
    int good = 1;
    for (int i = 0; i < 4; i++)
    {
        good &= (d[i] >= 0) && (d[i] <= 255);
    }
    if (good) {
        printf("yes\n");
    } else {
        printf("no\n");
    }
    return 0;
}