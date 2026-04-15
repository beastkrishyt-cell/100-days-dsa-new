#include <stdio.h>
int isMinHeap(int arr[], int i, int n) {
    if (i >= (n - 1) / 2) return 1;
    if (arr[i] <= arr[2 * i + 1] && arr[i] <= arr[2 * i + 2] &&
        isMinHeap(arr, 2 * i + 1, n) && isMinHeap(arr, 2 * i + 2, n))
        return 1;
    return 0;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (isMinHeap(arr, 0, n)) printf("True\n");
    else printf("False\n");
    return 0;
}
