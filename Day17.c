#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    if (n <= 0) return 0;
    int a[1000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int max = a[0];
    int min = a[0];
    for (int i = 1; i < n; i++) {
        if (a[i] > max) max = a[i];
        if (a[i] < min) min = a[i];
    }
    printf("Max: %d\nMin: %d\n", max, min);
    return 0;
}
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
