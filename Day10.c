#include <stdio.h>
#include <string.h>
int main() {
    char str[1000];
    if (scanf("%999s", str) != 1) return 0;
    int len = strlen(str);
    int left = 0, right = len - 1;
    int isPal = 1;
    while (left < right) {
        if (str[left] != str[right]) {
            isPal = 0;
            break;
        }
        left++;
        right--;
    }
    if (isPal) {
        printf("Palindrome\n");
    } else {
        printf("Not Palindrome\n");
    }
    return 0;
}
