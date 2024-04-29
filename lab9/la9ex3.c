#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

void set_board(int x, int y, int n, char board[15][15], char inc) {
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) {
                board[x][y] += inc;
                continue;
            }
            int new_x = x+dx, new_y = y+dy;
            while (new_x >= 0 && new_x < n && new_y >= 0 && new_y < n) {
                board[new_x][new_y] += inc;
                new_x += dx, new_y += dy;
            }
        }
    }
}

int is_board_full(int n, char board[15][15]) {
    int is_full = 1;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n && is_full; j++)
        {
            is_full &= board[i][j];
        }
    }
    return is_full;
}

void nqueen(int row, int N, int *count, char board[15][15], int board_size) {
    if (N == 0) {
        (*count)++;
        return;
    }
    for (int i = 0; i < board_size; i++)
    {
        // place a queen
        if (board[i][row] == 0) {
            set_board(i, row, board_size, board, 1);
            // if (is_board_full(board_size, board)) {
            //     if (N == 1) (*count)++;
            // } else {
            //     nqueen(N-1, count, board, board_size);
            // }
            nqueen(row+1, N-1, count, board, board_size);
            set_board(i, row, board_size, board, -1);
        }
    }
    
}

int main(int argc, char **argv) {
    int N;
    scanf("%d", &N);
    int count = 0;
    char board[15][15] = {0};
    nqueen(0, N, &count, board, N);
    printf("%d", count);
    return 0;
}