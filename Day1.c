#include <stdio.h>
int main() {
    int n, pos, x;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d %d", &pos, &x) != 2) return 0;
    for (int i = n; i >= pos; i--) {
        arr[i] = arr[i - 1];
    }
    arr[pos - 1] = x;
    n++;
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}
