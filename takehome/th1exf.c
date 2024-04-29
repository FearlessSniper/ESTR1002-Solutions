#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    char map[600][600];
    int r, c;
    scanf("%d%d", &r, &c);
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            scanf(" %c", &map[i][j]);
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (map[i][j] == '*') {
                putchar('*');
                continue;
            }
            int count = 0;
            for (int dx = -1; dx <= 1; dx++) {
                for (int dy = -1; dy <= 1; dy++)
                {
                    int x_new = i + dx, y_new = j + dy;
                    if (x_new >= 0 && x_new < r && y_new >= 0 && y_new < c) {
                       if (map[x_new][y_new] == '*') count++; 
                    }
                }   
            }
            printf("%d", count);
        }
        putchar('\n');
        
    }
    
    
    return 0;
}