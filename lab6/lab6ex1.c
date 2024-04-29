#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, char **argv) {
    int occ[128];
    for (size_t i = 0; i < 128; i++)
    {
        occ[i] = 0;
    }
    char c;
    do {
        c = getchar();
        occ[tolower(c)]++;
    } while (c != EOF && c != '\n');
    int is_unique = 1;
    for (int i = 0; i < 128 && is_unique; i++)
    {
        is_unique &= occ[i] <= 1;
    }
    if (is_unique) {
        printf("yes");
    } else {
        printf("no");
    }
    
    
    return 0;
}