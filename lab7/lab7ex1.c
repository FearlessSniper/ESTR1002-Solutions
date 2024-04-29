#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str, int n) {
    // Check whether the string is palindrome, with n characters
    int ans = 1;  // default true
    for (size_t i = 0; i < n / 2 && ans; i++) {
        ans &= tolower(str[i]) == tolower(str[n - i - 1]);
    }
    return ans;
}

int main(int argc, char** argv) {
    char str[2048];
    while (fgets(str, 2048, stdin) != NULL)
    {
        str[strcspn(str, "\r\n")] = '\0';
        int len = strlen(str);
        if (is_palindrome(str, len)) {
            printf("palindrome\n");
        } else if (len > 2) {
            int found_sub_palindrome = 0;
            // Check len 2
            for (size_t i = 0; i < len - 2 + 1 && !found_sub_palindrome; i++) {
                found_sub_palindrome |= is_palindrome(str+i, 2);
            }
            // Check len 3
            for (size_t i = 0; i < len - 3 + 1 && !found_sub_palindrome; i++) {
                found_sub_palindrome |= is_palindrome(str+i, 3);
            }
            if (found_sub_palindrome) {
                printf("palindromic substring\n");
            } else {
                printf("whatever\n");
            }
        } else {
            printf("whatever\n");
        }
    }
    return 0;
}