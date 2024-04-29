#include <stdio.h>

int main() {
    double r_start = -1.2345678, r_end = 9.8765432;
    while ((r_end-r_start)>=1.0)
    {
        double d;
        scanf("%lf", &d);
        double r1_start = r_start, r1_end = d;
        double r2_start = d, r2_end = r_end;
        double r1_size = r1_end - r1_start;
        double r2_size = r2_end - r2_start;
        if (r2_size > r1_size || (r2_size == r1_size && r2_end > r1_end)) {
            r_start = r2_start;
            r_end = r2_end;
        }
        else {
            r_start = r1_start;
            r_end = r1_end;
        }
        printf("(%.7f,%.7f)\n", r_start, r_end);
    }
    
    return 0;
}
