#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int compare_char(const void *a, const void *b) {
    const char *c_a = a;
    const char *c_b = b;
    return *c_a - *c_b;
}

int main(int argc, char **argv) {
    char line[30];
    fgets(line, 30, stdin);
    line[strcspn(line, "\r\n")] = '\0';
    int n = strlen(line); // n: number of characters
    qsort(line, n, sizeof(char), compare_char); // why do i have to do this...
    printf("%d\n", n * (n-1) * (n-1));
    char permu[4] = {0};
    for (int i = 0; i < n; i++)
    {
        permu[0] = line[i];
        for (int j = 0; j < n; j++)
        {
            if (line[j] == permu[0]) continue;
            permu[1] = line[j];
            for (int k = 0; k < n; k++)
            {
                if (line[k] == permu[1]) continue;
                permu[2] = line[k];
                puts(permu);
            }
        }
    }
    
    return 0;
}