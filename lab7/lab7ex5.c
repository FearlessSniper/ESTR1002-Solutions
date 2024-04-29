/**
 * @file lab7ex5.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief exercise 5 - acrostic
 * @version 0.1
 * @date 20-10-2023
 * 
 * @copyright Copyright (c) 2023
 * 
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <limits.h>
#include <math.h>

char first_letter(char *str) {
    int i = 0;
    while (str[i] != '\0')
    {
        if (isalpha(str[i]))
        {
            return str[i];
        }
        i++;
    }
    return '\0';
    
}

void to_lower_s(char *str) {
    int i = 0;
    while (str[i] != '\0')
    {
        str[i] = tolower(str[i]);
        i++;
    }
}

int main(int argc, char **argv) {
    char dict[200003];
    fgets(dict, 200003, stdin);
    dict[strcspn(dict, "\r\n")] = '\0';
    char s[200003];
    fgets(s, 200003, stdin);
    s[strcspn(s, "\r\n")] = '\0';
    // Build string of first letters
    char *tok = strtok(s, " ");
    int s_count = 0;
    while (tok != NULL)
    {
        s[s_count] = tolower(first_letter(tok));
        s_count++;
        tok = strtok(NULL, " ");
    }
    s[s_count] = '\0';
    // Search for occurences (naive)
    tok = strtok(dict, " ");
    while (tok != NULL) {
        to_lower_s(tok);
        int tok_len = strlen(tok);
        if (tok_len <= s_count) {
            for (int i = 0; i <= s_count-tok_len; i++)
            {
                int cmp = strncmp(tok, s+i, tok_len);
                if (cmp == 0) {
                    printf("%s\n", tok);
                    break;
                }
            }
        }
        tok = strtok(NULL, " ");
    }
    return 0;
}