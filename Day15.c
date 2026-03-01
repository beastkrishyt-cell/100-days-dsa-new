#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[100][100];
    int sum = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (scanf("%d", &a[i][j]) != 1) return 0;
            if (i == j) sum += a[i][j];
        }
    }
    printf("%d\n", sum);
    return 0;
}
