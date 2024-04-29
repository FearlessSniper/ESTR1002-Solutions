#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

const int WORD_LEN = 2048;
const int WORD_COUNT = 100;
const int LINE_LEN = 2048 * 100;

const char reversable[] = {'A', 'H', 'I', 'M', 'O', 'T', 'U', 'V', 'W', 'X', 'Y'};
const int REVERSABLE_LEN = 11;

// from cppreference.com/w/c/algorithm/qsort. hope it does not count as plagarism :)
int cmp_char(const void* a, const void* b)
{
    char arg1 = *(const char*)a;
    char arg2 = *(const char*)b;

    if (arg1 < arg2) return -1;
    if (arg1 > arg2) return 1;
    return 0;
}

// custom gets_s implementation
void _gets_s(char *s, int count) {
   fgets(s, count, stdin);
   // stackoverflow solution: strcspn
   s[strcspn(s, "\r\n")] = '\0';
}

int main(int argc, char **argv) {
    int n;
    scanf("%d\n", &n); // just add one more newline to consume
    char line[LINE_LEN];
    _gets_s(line, LINE_LEN);
    char dict[WORD_COUNT][WORD_LEN];
    char *tok = strtok(line, " ");
    int dict_size = 0;
    while (tok != NULL) {
        strcpy(dict[dict_size], tok);
        dict_size++;
        tok = strtok(NULL, " ");
    }
    int result[WORD_COUNT];
    for (int i = 0; i < n; i++) {
        char word[WORD_LEN];
        _gets_s(word, WORD_LEN);
        char rev_word[WORD_LEN];
        int len_word = strlen(word);
        result[i] = 1; // Default: pass
        // Reverse the word
        for (int j = len_word-1; j >= 0; j--) {
            if (bsearch(&word[j], reversable, REVERSABLE_LEN, sizeof(char), cmp_char) != NULL) {
                // word[i] is a reversable character
                rev_word[len_word-j-1] = word[j];
            } else {
                result[i] = 0;
                break;
            }
        }
        rev_word[len_word] = '\0';
        if (result[i]) {
            result[i] = 0;
            for (int j = 0; j < dict_size && !result[i]; j++) {
                // Search string in dictionary
                if (strcmp(rev_word, dict[j]) == 0) {
                    result[i] = 1;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (result[i]) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
