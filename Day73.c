#include <stdio.h>
#include <string.h>
int main() {
    char s[1000];
    if (scanf("%999s", s) != 1) return 0;
    int freq[256] = {0};
    int len = strlen(s);
    for (int i = 0; i < len; i++) freq[(unsigned char)s[i]]++;
    for (int i = 0; i < len; i++) {
        if (freq[(unsigned char)s[i]] == 1) {
            printf("%c\n", s[i]);
            return 0;
        }
    }
    printf("$\n");
    return 0;
}
