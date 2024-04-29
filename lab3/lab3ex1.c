#include <stdio.h>

int main(void) {
    char *elephant_head = "          __     __\n         /  \\~~~/  \\\n   ,----(     ..    )\n  /      \\__     __/\n /|         (\\  |(\n^ \\   /___\\  /\\ |";
    int n; // number of lines of elephant leg
    scanf("%d", &n);
    puts(elephant_head);
    if (n == 1) {
        printf("   |__|   |__|-\"\n");
        return 0;
    } else {
        printf("   |  |   |  |-\"\n");
    }
    for (int i = 0; i < n-2; i++) {
        printf("   |  |   |  |\n");
    }
    printf("   |__|   |__|\n");
    return 0;
}
