#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    int maxLen = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += arr[j];
            if (sum == 0 && (j - i + 1) > maxLen) {
                maxLen = j - i + 1;
            }
        }
    }
    printf("%d\n", maxLen);
    return 0;
}
