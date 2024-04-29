#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

enum CellType {
    EMPTY,
    NUM,
    MINE,
};

int in_bounds(int x, int y, int r, int c) {
    return x >= 0 && x < r && y >= 0 && y < c;
}

int has_mine(int x, int y, int r, int c, char board[][100]) {
    for (int dx = -1; dx <= 1; dx++)
    {
        for (int dy = -1; dy <= 1; dy++)
        {
            if (dx == 0 && dy == 0) continue;
            int new_x = x + dx, new_y = y + dy;
            if (in_bounds(new_x, new_y, r, c)) {
                if (board[new_x][new_y] == MINE) return 1;
            }
        }
    }
    return 0;
}

enum CellState {
    HIDDEN=0,
    REVEALED=1
};

struct Coords {
    int dx;
    int dy;
};

// We assumed that the coordinates are in bounds before calling, and the cell (x, y) must be
// empty
void flood_fill(int x, int y, enum CellState state[][100], int r, int c, char board[][100]) {
    state[x][y] = REVEALED;
    const struct Coords coords[] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
    for (int i = 0; i < 8; i++)
    {
        int new_x = x + coords[i].dx, new_y = y + coords[i].dy;
        if (in_bounds(new_x, new_y, r, c)) {
            if (state[new_x][new_y] == HIDDEN && board[new_x][new_y] == EMPTY) {
                flood_fill(new_x, new_y, state, r, c, board);
            } else if (board[new_x][new_y] == NUM) {
                state[new_x][new_y] = REVEALED;
            }
        }
    }
    
}

int main(int argc, char **argv) {
    int r, c;
    scanf("%d%d", &r, &c);
    char board[100][100];
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            char c;
            scanf(" %c", &c);
            switch (c)
            {
            case '.':
                board[i][j] = EMPTY;
                break;
            case '*':
                board[i][j] = MINE;
                break;
            default:
                break;
            }
        }
    }
    // Mark numbers
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (board[i][j] == EMPTY && has_mine(i, j, r, c, board)) {
                board[i][j] = NUM;
            }
        }
    }
    enum CellState states[100][100] = {HIDDEN};
    int reveal_count = 0;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (states[i][j] == HIDDEN && board[i][j] == EMPTY) {
                flood_fill(i, j, states, r, c, board);
                reveal_count++;
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (states[i][j] == HIDDEN && board[i][j] == NUM) {
                reveal_count++;
            }
        }
    }
    printf("%d", reveal_count);
    return 0;
}