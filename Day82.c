#include <stdio.h>
int lowerBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] >= x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int upperBound(int arr[], int n, int x) {
    int low = 0, high = n - 1, ans = n;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] > x) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}
int main() {
    int n, x;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) scanf("%d", &arr[i]);
    if (scanf("%d", &x) != 1) return 0;
    int lb = lowerBound(arr, n, x);
    int ub = upperBound(arr, n, x);
    printf("%d %d\n", lb, ub);
    return 0;
}
