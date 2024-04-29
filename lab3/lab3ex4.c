#include <stdio.h>
#include <math.h>


int main(void) {
    double x, y, v;
    scanf("%lf%lf%lf", &x, &y, &v);
    int count = 1;
    double t = x + y;
    double min_d = fabs(t-v);
    double result = t;

    t = x - y;
    if (fabs(t-v) < min_d){
        min_d = fabs(t-v);
        result = t;
    }
    else if (fabs(t-v) == min_d && t != result) count++;

    t = y - x;
    if (fabs(t-v) < min_d) {
        min_d = fabs(t-v);
        result = t;
    }
    else if (fabs(t-v) == min_d && t != result) count++;

    t = x * y;
    if (fabs(t-v) < min_d) {min_d = fabs(t-v); result=t;}
    else if (fabs(t-v) == min_d && t != result) count++;

    t = x / y;
    if (fabs(t-v) < min_d) {min_d = fabs(t-v); result=t;}
    else if (fabs(t-v) == min_d && t != result) count++;

    t = y / x;
    if (fabs(t-v) < min_d) {min_d = fabs(t-v); result=t;}
    else if (fabs(t-v) == min_d && t != result) count++;

    if (count > 1) {
        printf("%.4f %.4f\n", -fabs(result), fabs(result));
    } else {
        printf("%.4f\n", result);
    }
    return 0;
}
