#include <stdio.h>
int mySqrt(int x) {
    if (x == 0 || x == 1) return x;
    int start = 1, end = x, ans;
    while (start <= end) {
        int mid = start + (end - start) / 2;
        if (mid <= x / mid) {
            ans = mid;
            start = mid + 1;
        } else {
            end = mid - 1;
        }
    }
    return ans;
}
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    printf("%d\n", mySqrt(n));
    return 0;
}
