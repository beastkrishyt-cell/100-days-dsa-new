#include <stdio.h>
int main() {
    int r, c;
    if (scanf("%d %d", &r, &c) != 2) return 0;
    int a[100][100], b[100][100], sum[100][100];
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (scanf("%d", &a[i][j]) != 1) return 0;
    for (int i = 0; i < r; ++i)
        for (int j = 0; j < c; ++j)
            if (scanf("%d", &b[i][j]) != 1) return 0;
    for (int i = 0; i < r; ++i) {
        for (int j = 0; j < c; ++j) {
            sum[i][j] = a[i][j] + b[i][j];
            printf("%d ", sum[i][j]);
        }
        printf("\n");
    }
    return 0;
}
