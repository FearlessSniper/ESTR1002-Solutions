#include <ctype.h>
#include <limits.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int is_palindrome(char* str, int n) {
    // Check whether the string is palindrome, with n characters
    // n-i-1
    if (n == 1) return 0; // Define one char not palindrome
    int ans = 1;  // default true
    for (size_t i = 0; i < n / 2 && ans; i++) {
        ans &= tolower(str[i]) == tolower(str[n - i - 1]);
    }
    return ans;
}

int main(int argc, char** argv) {
    char str[2048];
    while (fgets(str, 2048, stdin) != NULL) {
        str[strcspn(str, "\r\n")] = '\0';
        int len = strlen(str);
        if (is_palindrome(str, len)) {
            printf("palindrome");
        } else {
            char *tok = strtok(str, " ");
            int is_sub_palindrome = 0;
            while (tok != NULL && !is_sub_palindrome) {
                is_sub_palindrome |= is_palindrome(tok, strlen(tok));
                tok = strtok(NULL, " ");
            }
            if (is_sub_palindrome)
            {
                printf("palindromic substring");
            } else {
                printf("whatever");
            }
        }
    }
    return 0;
}