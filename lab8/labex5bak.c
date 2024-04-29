/**
 * @file lab8ex5.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief 
 * @version 0.1
 * @date 26-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int in_rect(int x, int y, int w, int b) {
    return (0 <= x && x < w-1 && 0 <= y && y < b-1);
}

unsigned long long snakes(int x, int y, int w, int b, int n) {
    if (n == 1) return 1l;
    unsigned long long sum = 0;
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (in_rect(x+dx, y+dy, w, b)) {
                sum += snakes(x+dx, y+dy, w, b, n-1);
            }
        }
    }
    return sum;
}

int main(int argc, char **argv) {
    int n, w, b;
    scanf("%d%d%d", &n, &w, &b);
    printf("%llu", snakes((w-1)/2, (b-1)/2, w, b, n));
    return 0;
}