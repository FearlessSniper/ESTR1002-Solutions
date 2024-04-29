/**
 * @file lab7ex4.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief Exercise 4 - searching strings using binary search
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

// Searches target in an array of string `dict`. Assumes dict is sorted
// and uses binary search.
int bsearch_string(char **dict, int n, char *target, int rel_pos) {
    int cmp = strcmp(dict[n/2], target);
    if (n == 1 && cmp != 0) return -1;
    if (cmp == 0) return n/2 + rel_pos;
    else if (cmp < 0) return bsearch_string(dict+n/2+1, n-(n/2+1), target, rel_pos+n/2+1);
    else return bsearch_string(dict, n/2, target, rel_pos);  // [0..n/2-1] has n/2-1+1 = n/2 elements
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    getchar(); // consume newline
    char dict[100000][28];
    char *s_ptrs[100000];
    for (int i = 0; i < n; i++) {
        fgets(dict[i], 48, stdin);
        dict[i][strcspn(dict[i], "\r\n")] = '\0';
        s_ptrs[i] = dict[i];
    }
    int k;
    scanf("%d", &k);
    getchar();
    for (int i = 0; i < k; i++)
    {
        char line[48];
        fgets(line, 48, stdin);
        line[strcspn(line, "\r\n")] = '\0';
        int pos = bsearch_string(s_ptrs, n, line, 0);
        if (pos != -1) pos++; // returned index is zero-indexed
        printf("%d\n", pos);
    }
    
    return 0;
}