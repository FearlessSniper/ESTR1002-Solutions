#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef int IArray[5];
int main(int argc, char** argv) {
    // unsigned long long a[21][21][5][16][16][16];
    unsigned long long (*c)[21][21][5][16][16][16] = malloc(sizeof (unsigned long long) * 21 * 21 * 5 * 16 * 16 * 16);
    IArray array[5];
    IArray (*a) = malloc(sizeof(IArray));
    return 0;
}