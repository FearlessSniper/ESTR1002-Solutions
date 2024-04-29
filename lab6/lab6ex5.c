#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

const int STR_LEN = 128;

// TC: a

long long pow_i(long long x, long long a) {
    long long ans = 1;
    for (long long i = 0; i < a; i++) {
        ans *= x;
    }
    return ans;
}

int get_index(char c) {
    if (isdigit(c)) {
        return c - '0';
    } else if (isalpha(c)) {
        return c - 'a' + 10;
    } else {
        // trap debug here
        return -1;
    }
}

const int VALS[] = {1, 0}; // for the first unique map a value of 1; then 0; else 2, 3, 4...

int main(int argc, char **argv) {
    char str[STR_LEN];
    fgets(str, STR_LEN, stdin);
    str[strcspn(str, "\r\n")] = '\0';
    int occs[36]; // 10 digits + 26 alphabet
    memset(occs, 0, sizeof(int) * 36);
    int unique_count = 0;
    int str_len = strlen(str);
    for (int i = 0; i < str_len; i++)
    {
        int tgt_i = get_index(str[i]);
        if (occs[tgt_i] == 0) unique_count++;
        occs[tgt_i]++;
    }
    // short circuit minimum base
    if (unique_count < 2) unique_count = 2;
    // reset occs
    for (int i = 0; i < 36; i++)
    {
        occs[i] = -1;
    }

    // unique_count is the minimum base
    // now let's use occs as a map: map char to value it represent
    long long min_secs = 0;
    long long multiplier = pow_i(unique_count, str_len-1);
    int cur_unique_count = 0; // unique characters seen so far
    for (int i = 0; i < str_len; i++) {
        int tgt_i = get_index(str[i]);
        if (occs[tgt_i] == -1) {
            // we haven't seen the character: assign a value to it
            if (cur_unique_count < 2) {
                occs[tgt_i] = VALS[cur_unique_count];
            } else {
                occs[tgt_i] = cur_unique_count;
            }
            cur_unique_count++;
        }
        min_secs += occs[tgt_i] * multiplier;
        multiplier /= unique_count;
    }
    printf("%lld", min_secs);
    return 0;
}