#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

#define BUF_SIZE 0xFFFFF

int main(int argc, char **argv) {
    char s[BUF_SIZE]; // well, just a bit over 1 million...
    scanf("%s", s); // well, it saves us a bit of work...
    int len = strlen(s);
    int found = 0;
    int min_substr_len = len;
    for (int i = 1; !found && i < len; i++)
    {
        if (len % i != 0) continue;
        found = 1;
        int substr_count = len / i;
        char *substr_head = s;
        for (int j = 0; j < substr_count && found; j++)
        {
            found &= strncmp(s, substr_head, i) == 0;
            substr_head += i;
        }
        if (found) min_substr_len = i;
    }
    printf("%d", len/min_substr_len);
    

    return 0;
}