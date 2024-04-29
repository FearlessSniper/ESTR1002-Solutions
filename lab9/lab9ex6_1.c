#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

enum Brick {
    B2B2=0,
    B2B3H,
    B2B3V,
    B2B4H,
    B2B4V,
};

typedef unsigned long long Table[7][7][7][19][19][5];

int in_bounds(int x, int y, enum Brick brick, int w, int b) {
    switch (brick)
    {
    case B2B2:
        return x >= 0 && x < w-1 && y >= 0 && y < b-1;
        break;
    case B2B3H:
        return x >= 0 && x < w-2 && y >= 0 && y < b-1;
        break;
    case B2B3V:
        return x >= 0 && x < w-1 && y >= 0 && y < b-2;
        break;
    case B2B4H:
        return x >= 0 && x < w-3 && y >= 0 && y < b-1;
        break;
    case B2B4V:
        return x >= 0 && x < w-1 && y >= 0 && y < b-3;
        break;
    default:
        return -1;
        break;
    }
}

unsigned long long count(int m, int n, int k, int w, int b, int x, int y, enum Brick brick, Table dp);

unsigned long long try_brick(int x_min, int x_max, int y_min, int y_max, int x, int y, enum Brick brick, int m, int n, int k, int w, int b, Table dp) {
    switch (brick)
    {
    case B2B2:
        m--;
        break;
    case B2B3H:
    case B2B3V:
        n--;
        break;
    case B2B4H:
    case B2B4V:
        k--;
        break;
    default:
        break;
    }
    unsigned long long acc = 0;
    for (int dx = x_min; dx <= x_max; dx++)
    {
        for (int dy = y_min; dy <= y_max; dy++)
        {
            if (in_bounds(x+dx, y+dy, brick, w, b)) {
                unsigned long long t = count(m, n, k, w, b, x+dx, y+dy, brick, dp);
                dp[m][n][k][x+dx][y+dy][brick] = t;
                acc += t;
            }
        }
    }
    return acc;
    
}

unsigned long long count(int m, int n, int k, int w, int b, int x, int y, enum Brick brick, Table dp) {
    if (m == 0 && k == 0 && n == 0) {
        return 1;
    }
    unsigned long long c = dp[m][n][k][x][y][brick];
    if (c != 0) {
        return c;
    }
    unsigned long long acc = 0;
    switch (brick)
    {
    case B2B2:
        // Place another 2x2
        if (m > 0) {
            acc += try_brick(-1, 1, -1, 1, x, y, B2B2, m, n, k, w, b, dp);
        }
        if (n > 0) {
            acc += try_brick(-2, 1, -1, 1, x, y, B2B3H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -2, 1, x, y, B2B3V, m, n, k, w, b, dp);
        }
        if (k > 0)
        {
            acc += try_brick(-3, 1, -1, 1, x, y, B2B4H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -3, 1, x, y, B2B4V, m, n, k, w, b, dp);
        }
        break;
    case B2B3H:
        if (m > 0) {
            acc += try_brick(-1, 2, -1, 1, x, y, B2B2, m, n, k, w, b, dp);
        }
        if (n > 0) {
            acc += try_brick(-2, 2, -1, 1, x, y, B2B3H, m, n, k, w, b, dp);
            acc += try_brick(-1, 2, -2, 1, x, y, B2B3V, m, n, k, w, b, dp);
        }
        if (k > 0) {
            acc += try_brick(-3, 2, -1, 1, x, y, B2B4H, m, n, k, w, b, dp);
            acc += try_brick(-1, 2, -3, 1, x, y, B2B4V, m, n, k, w, b, dp);
        }
        break;
    case B2B3V:
        if (m > 0) {
            acc += try_brick(-1, 1, -1, 2, x, y, B2B2, m, n, k, w, b, dp);
        }
        if (n > 0) {
            acc += try_brick(-2, 1, -1, 2, x, y, B2B3H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -2, 2, x, y, B2B3V, m, n, k, w, b, dp);
        }
        if (k > 0) {
            acc += try_brick(-3, 1, -1, 2, x, y, B2B4H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -3, 2, x, y, B2B4V, m, n, k, w, b, dp);
        }
        break;
    case B2B4H:
        if (m > 0) {
            acc += try_brick(-1, 3, -1, 1, x, y, B2B2, m, n, k, w, b, dp);
        }
        if (n > 0) {
            acc += try_brick(-2, 3, -1, 1, x, y, B2B3H, m, n, k, w, b, dp);
            acc += try_brick(-1, 3, -2, 1, x, y, B2B3V, m, n, k, w, b, dp);
        }
        if (k > 0) {
            acc += try_brick(-3, 3, -1, 1, x, y, B2B4H, m, n, k, w, b, dp);
            acc += try_brick(-1, 3, -3, 1, x, y, B2B4V, m, n, k, w, b, dp);
        }
        break;
    case B2B4V:
        if (m > 0) {
            acc += try_brick(-1, 1, -1, 3, x, y, B2B2, m, n, k, w, b, dp);
        }
        if (n > 0) {
            acc += try_brick(-2, 1, -1, 3, x, y, B2B3H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -2, 3, x, y, B2B3V, m, n, k, w, b, dp);
        }
        if (k > 0) {
            acc += try_brick(-3, 1, -1, 3, x, y, B2B4H, m, n, k, w, b, dp);
            acc += try_brick(-1, 1, -3, 3, x, y, B2B4V, m, n, k, w, b, dp);
        }
        break;
    }
    return acc;
}

int main(int argc, char **argv) {
    int m, n, k, w, b;
    scanf("%d%d%d%d%d", &m, &n, &k, &w, &b);
    Table *dp = calloc(1, sizeof(Table));
    printf("%llu", count(m-1, n, k, w, b, (w-1)/2, (b-1)/2, B2B2, *dp));
    free(dp);
    return 0;
}