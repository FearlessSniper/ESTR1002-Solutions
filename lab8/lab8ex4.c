#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

char *max_string(char seq[26][26], int i, int j, int n) {
    char *s = malloc(sizeof(char) * 26);
    s[0] = seq[i][j];
    s[1] = '\0';
    if (i == n-1) return s;
    char *s1 = max_string(seq, i+1, j, n);
    char *s2 = max_string(seq, i+1, j+1, n);
    if (strcmp(s1, s2) > 0) {
        // s1 > s2
        strcat(s, s1);
    } else {
        // s1 <= s2; but s1==s2 makes no difference
        strcat(s, s2);
    }
    free(s1);
    free(s2);
    return s;
}

int main(int argc, char **argv) {
    int n;
    scanf("%d", &n);
    char seq[26][26];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < i+1; j++)
        {
            scanf(" %c", &(seq[i][j]));
        }
    }
    char *s = max_string(seq, 0, 0, n);
    puts(s);
    free(s);
    return 0;
}