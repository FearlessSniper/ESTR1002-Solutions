#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

void grid_lsum(unsigned long long srcgrid[20][20], unsigned long long dstgrid[20][20], int x, int y, int w, int b) {
    unsigned long long lsum = 0;
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++) {
            if (x+dx >= 0 && y+dy >= 0 && x+dx < w-1 && y+dy < b-1) {
                lsum += srcgrid[x+dx][y+dy];
            }
        }
    }
    dstgrid[x][y] = lsum;
}

unsigned long long snakes(int n, int w, int b) {
    unsigned long long grida[20][20] = {0ull};
    grida[(w-1)/2][(b-1)/2] = 1;
    unsigned long long gridb[20][20];
    unsigned long long (*old)[20] = grida, (*new)[20] = gridb;
    for (int step = 0; step < n-1; step++) {
        for (int i = 0; i < w-1; i++)
        {
            for (int j = 0; j < b-1; j++)
            {
                grid_lsum(old, new, i, j, w, b);
            }
        }
        // swap the grids
        unsigned long long (*temp)[20] = old;
        old = new;
        new = temp;
    }
    unsigned long long sum = 0;
    for (int i = 0; i < w-1; i++)
    {
        for (int j = 0; j < b-1; j++)
        {
            sum += old[i][j];
        }
    }
    return sum;
}



int main(int argc, char **argv) {
    int n, w, b;
    scanf("%d%d%d", &n, &w, &b);
    printf("%llu", snakes(n, w, b));
    return 0;
}