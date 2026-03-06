#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[1000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int count = 0;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            if (sum == 0) count++;
        }
    }
    printf("%d\n", count);
    return 0;
}
