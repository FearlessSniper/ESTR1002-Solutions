#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 20

typedef struct {
    int x, y;
} Point;

double distance(const Point* a, const Point* b) {
    double dx = b->x - a->x;
    double dy = b->y - a->y;
    return sqrt(dx * dx + dy * dy);
}

void route_dist(const Point* points,
                int n,
                int* seq,
                int n_cur,
                char* chosen,
                double cur_dist,
                double* min,
                int* ans) {
    if (n_cur == n) {
        cur_dist += distance(&points[seq[0]], &points[seq[n - 1]]);
        if (cur_dist < *min) {
            // Copy current sequence to ans
            *min = cur_dist;
            for (int i = 0; i < BUF_SIZE; i++) {
                ans[i] = seq[i];
            }
        }
        return;
    }
    for (int i = 0; i < n; i++) {
        if (!chosen[i]) {
            chosen[i] = 1;
            seq[n_cur] = i;
            route_dist(points, n, seq, n_cur + 1, chosen,
                       cur_dist + distance(&points[seq[n_cur - 1]],
                                            &points[seq[n_cur]]),
                       min, ans);
            chosen[i] = 0;
        }
    }
}

int main(int argc, char** argv) {
    int n, s;
    scanf("%d%d", &n, &s);
    Point points[BUF_SIZE];
    for (int i = 0; i < n; i++) {
        scanf("%d%d", &points[i].x, &points[i].y);
    }
    int min_route[BUF_SIZE];
    char chosen[BUF_SIZE] = {0};
    chosen[s] = 1;
    int current_seq[BUF_SIZE];
    current_seq[0] = s;
    double min = LONG_MAX;
    route_dist(points, n, current_seq, 1, chosen, 0, &min, min_route);
    printf("%d", min_route[0]);
    for (int i = 1; i < n; i++) {
        printf(" %d", min_route[i]);
    }
    return 0;
}