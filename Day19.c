#include <stdio.h>
#include <stdlib.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n < 2) return 0;
    int a[1000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int min_sum = a[0] + a[1];
    int pair1 = 0, pair2 = 1;
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            int sum = a[i] + a[j];
            if (abs(sum) < abs(min_sum)) {
                min_sum = sum;
                pair1 = i;
                pair2 = j;
            }
        }
    }
    printf("%d %d\n", a[pair1], a[pair2]);
    return 0;
}
