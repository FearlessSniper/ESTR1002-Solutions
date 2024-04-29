/**
 * @file lab7ex3.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief Exercise 3 - using the return values of strcmp()
 * @version 0.1
 * @date 19-10-2023
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

// a <= b <= c <= d
// a <= b && b <= c && c <= d
// a >= b && b >= c && c >= d
// a == b && b == c && c == d
int main(int argc, char **argv) {
    char last[128];
    fgets(last, 128, stdin);
    last[strcspn(last, "\r\n")] = '\0';
    char cur[128];
    int is_eq = 1, is_asc = 1, is_desc = 1;
    while (fgets(cur, 128, stdin) != NULL)
    {
        cur[strcspn(cur, "\r\n")] = '\0';
        int cmp = strcmp(last, cur);
        is_eq &= cmp == 0; // is_eq = is_eq & cmp == 0
        is_asc &= cmp <= 0; // lhs appears before rhs: negative
        is_desc &= cmp >= 0;
        strcpy(last, cur);
    }
    if (is_eq) {
        printf("identical");
    }
    else if (is_asc) {
        printf("ascending");
    }
    else if (is_desc) {
        printf("descending");
    }
    else {
        printf("whatever");
    }
    return 0;
}