#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

int main(int argc, char **argv) {
    char sid[11];
    scanf("%s", sid);
    if (strncmp(sid, "10", 2) == 0) {
        printf("before 2010-11");
    } else if (strncmp(sid, "1155", 4) == 0) {
        printf("in and after 2010-11");
    } else {
        printf("invalid sid");
    }
    return 0;
}