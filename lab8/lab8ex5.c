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

typedef struct brick {
    int x, y;
} brick_t;

typedef brick_t rect_t;

typedef struct {
    int left;
    int right;
    int top;
    int bottom;
} bounds_t;

bounds_t in_bounds(brick_t t, rect_t r) {
    bounds_t bounds;
    bounds.left = t.x <= 0;
    bounds.right = t.x < r.x-1;
    bounds.top = t.y <= 0;
    bounds.bottom = t.y < r.y-1;
    return bounds;
}

bounds_t space_around(brick_t t, rect_t r) {
    bounds_t bounds;
    bounds.left = t.x;
    bounds.right = r.x-2-t.x;
    bounds.top = t.y;
    bounds.bottom = r.y-2-t.y;
    return bounds;
}

int in_rect(bounds_t bounds) {
    return bounds.left && bounds.right && bounds.top && bounds.bottom;
}
void _snakes(int x, int y, int w, int b, int n, int *count, int space) {
    if (space > 0) {
        // all round space; no check
        if (n == 2) {
            *count += 9;
            return;
        }
        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++) {
                _snakes(x+i, y+j, w, b, n-1, count, space-1);
            }
        }
    }
    brick_t myBrick = {x, y};
    rect_t play_area = {w, b};
    bounds_t bounds = in_bounds(myBrick, play_area);
    int is_in_rect = in_rect(bounds);
    if (n == 1 && is_in_rect) {
        *count += 1;
        return;
    }
    long sum = 0;
    for (int i = -1; i <= 1; i++) {
        if (!bounds.left && i == -1) continue;
        if (!bounds.right && i == 1) continue;
        for (int j = -1; j <= 1; j++)
        {
            if (!bounds.top && j == -1) continue;
            if (!bounds.bottom && j == 1) continue;
            _snakes(x+i, y+j, w, b, n-1, count, space-1);
        }
    }
}

int min(int a, int b) {
    return (a < b)? a: b;
}

long snakes(int w, int b, int n) {
    // Extra space w
    // Extra space b
    // additional length = (l-2)/2
    int x = (w-1) / 2;
    int y = (b-1) / 2;
    int count = 0;
    int all_round_space = min((w-2)/2, (b-2)/2);
    _snakes(x, y, w, b, n, &count, all_round_space);
    return count;

}

int main(int argc, char **argv) {
    int n, w, b;
    scanf("%d%d%d", &n, &w, &b);
    printf("%ld", snakes(w, b, n));
    return 0;
}