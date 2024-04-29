/**
 * @file th2exb.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief Sliding windows, huh...
 * @version 0.1
 * @date 27-11-2023
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

int main(int argc, char **argv) {
    int n, k;
    scanf("%d%d", &n, &k);
    int a[1000000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    long long cur_sum = 0;
    // Find the sum of the first window
    for (int i = 0; i < k; i++)
    {
        cur_sum += a[i];
    }
    long long max_sum = cur_sum;
    for (int i = 0; i+k < n; i++)
    {
        cur_sum = cur_sum + a[i+k] - a[i];
        if (cur_sum > max_sum) {
            max_sum = cur_sum;
        }
    }
    printf("%lld", max_sum);
    
    
    return 0;
}