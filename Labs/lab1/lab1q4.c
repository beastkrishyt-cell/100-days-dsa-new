#include <stdio.h>
int main() {
    int r, c, i, j;
    printf("Enter rows and columns: ");
    scanf("%d %d", &r, &c);
    int a[r][c];
    printf("Enter matrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            scanf("%d", &a[i][j]);
        }
    }
    printf("\nMatrix:\n");
    for(i = 0; i < r; i++) {
        for(j = 0; j < c; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
    printf("\nRow sums:\n");
    for(i = 0; i < r; i++) {
        int sum = 0;
        for(j = 0; j < c; j++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
    }
    printf("\n\nColumn sums:\n");
    for(j = 0; j < c; j++) {
        int sum = 0;
        for(i = 0; i < r; i++) {
            sum += a[i][j];
        }
        printf("%d ", sum);
    }

    return 0;
}