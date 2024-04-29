#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char* max(char b[], char c[]) {
    if (strcmp(b, c) > 0)
        return b;
    else
        return c;
}
char* f(char array[25][25], int n, int i, int j, char str[30]) {
    strcpy(str, array[0]);
    strcat(str, f(array, n, i, j, str));
    if (i == n)
        return str;
    else
        return max(f(array, n, i + 1, j, str), f(array, n, i + 1, j + 1, str));
}

int main() {
    int n, b, i, k;
    char array[25][25] = {0};
    char str[30];
    scanf("%d\n", &n);
    for (i = 0; i < n; i++) {
        for (k = 0; k < i + 1; k++) {
            scanf(" %c", &b);
            array[i][k] = b;
        }
    }
    printf("%s", f(array, n, 0, 0, str));
    return 0;
}