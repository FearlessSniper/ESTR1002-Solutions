#include <stdio.h>
#include <math.h>

int feq(double a, double b) {
    return fabs(a-b) < 0.00001;
}

int main(void) {
    double x, y, v;
    scanf("%lf%lf%lf", &x, &y, &v);
    double min_diff = NAN;
    double result1=NAN, result2=NAN;
    int flag = 0;
    for (size_t i = 0; i < 6; i++)
    {
        double t;
        switch (i)
        {
        case 0:
            t = x+y;
            break;
        case 1:
            t=x-y;
            break;
        case 2:
            t=y-x;
            break;
        case 3:
            t=x*y;
            break;
        case 4:
            if (y!=0) t=x/y;
            break;
        case 5:
            if (x!=0) t=y/x;
            break;
        default:
            break;
        }
        double diff = fabs(t-v);
        if (isnan(min_diff) || diff < min_diff) {
            min_diff = diff;
            result1 = t;
            flag = 0;
            if (result1 == -0.0) result1 = 0.0;
        } else if (feq(diff, min_diff) && !feq(t, result1)) {
            result2 = t;
            flag = 1;
            if (result2 == -0.0) result2 = 0.0;
        }
    }
    if (flag && result1 > result2) {
        double t = result1;
        result1 = result2;
        result2 = t;
    }
    printf("%.4f", result1);
    if (flag) printf(" %.4f", result2);
    return 0;
}
