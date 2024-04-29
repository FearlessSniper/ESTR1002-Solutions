#include <stdio.h>

int main() {
    int a[10], b[10];
    int n;
    scanf("%d", &n);
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", (a+i));
    }
    for (size_t i = 0; i < n; i++)
    {
        scanf("%d", (b+i));
    }
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            printf("%d ", a[i]^b[j]);
        }
        printf("\n");
        
    }
    
}
