#include <stdio.h>
void reverse(int arr[], int start, int end) {
    while (start < end) {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}
int main() {
    int n, k;
    if (scanf("%d %d", &n, &k) != 2) return 0;
    int a[1000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    k = k % n;
    if (k < 0) k += n;
    reverse(a, 0, n - 1);
    reverse(a, 0, k - 1);
    reverse(a, k, n - 1);
    for (int i = 0; i < n; i++) printf("%d ", a[i]);
    printf("\n");
    return 0;
}
