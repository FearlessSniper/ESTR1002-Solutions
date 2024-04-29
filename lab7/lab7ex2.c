/**
 * @file lab7ex2.c
 * @author aydenwong (aydenwongfs@gmail.com)
 * @brief 
 * @version 0.1
 * @date 19-10-2023
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

int main(int argc, char **argv) {
    char str[400000];
    fgets(str, 400000, stdin);
    str[strcspn(str, "\r\n")] = '\0';
    char *tok = strtok(str, " ");
    while (tok != NULL)
    {
        for (int i = strlen(tok)-1; i >= 0; i--)
        {
            if (isalpha(tok[i])) {
                putchar(tolower(tok[i]));
                break;
            }
        }
        tok = strtok(NULL, " ");
    }
    return 0;
}