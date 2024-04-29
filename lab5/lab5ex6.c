#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if (c == 0) {
        if (a == 1) {
            printf("1");
        } else {
            printf("0");
        }
        return 0;
    }
    char *fac_count = calloc(b+1, sizeof(char));
    int count = 0; // count of integers matching criteria
    int i;
    // int i_max = (int)ceil(sqrt(b));
    // if (a == 1 && c == 0) count++; // patch for 1
    for (i = 2; i <= b; i++)
    {
        if (c == 1) {
            if (i >= a && (fac_count[i] == 0 || fac_count[i] == 1)) count++;
        }
        else if (i >= a && fac_count[i] == c) {
            count++;
        }
        if (fac_count[i] == 0) {
            for (int j = i+i; j <= b; j+=i)
            {
                (fac_count[j])++;
            }
            
        }
    }
    // for (i; i <= b; i++)
    // {
    //     if (i >= a && fac_count[i] == c) count++;
    // }
    printf("%d", count);
    free(fac_count);
    return 0;
}
