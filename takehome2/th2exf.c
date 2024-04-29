#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

typedef char Grid[20][20];

int mark_square(int n, int m, int N, Grid grid) {
    // Find the max side length at (n, m)
    int side_length = N - n;
    for (int i = 0; n+i < N; i++)
    {
        if (grid[n+i][m] == '#') {
            grid[n+i][m] = '*'; // we mark * as checked
        } else {
            side_length = i;
            break;
        }
    }
    // side_length = i + 1 here
    for (int i = 0; i < side_length; i++) // start mark from the next row
    {
        for (int j = 1; j < side_length; j++)
        {
            if (m + j >= N) return 0;
            if (grid[n+i][m+j] == '#') {
                grid[n+i][m+j] = '*';
            } else return 0;
        }
    }
    return 1; // sucessfully marked a min square
    
}

// The function name is a bit misleading; we are searching the first black cell
// plus marking the square
int search_black_cell(int N, Grid grid) {
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (grid[i][j] == '#') {
                // Find the max side length
                return mark_square(i, j, N, grid);
            }
        }
        
    }
    
}

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);
    Grid grid;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            scanf(" %c", &grid[i][j]);
        }
    }
    if (search_black_cell(N, grid) == 0) {
        printf("NO");
        return 0;
    }
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            // Marked all the square, should not have #
            if (grid[i][j] == '#') {
                printf("NO");
                return 0;
            }
        }
    }
    printf("YES");
    return 0;
}