/**
 * @file lab8ex1.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief 
 * @version 0.1
 * @date 23-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>

long count_square_path(int n, int x, int y) {
    // diagonal: y = x
    long sum = 0;
    if (x == n && y == n) return 1;
    if (y <= x+1 && x+1 <= n) {
        sum += count_square_path(n, x+1, y);
        sum += count_square_path(n, x+1, y+1);
    }
    if (y+1 <= x) {
        sum += count_square_path(n, x, y+1);
    }
    return sum;
}

int main(int argc, char const *argv[])
{
    int n;
    scanf("%d", &n);
    printf("%ld", count_square_path(n, 0, 0));
    return 0;
}

