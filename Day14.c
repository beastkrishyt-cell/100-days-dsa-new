#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[100][100];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (scanf("%d", &a[i][j]) != 1) return 0;
    int iden = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j && a[i][j] != 1) iden = 0;
            else if (i != j && a[i][j] != 0) iden = 0;
        }
    }
    if (iden) printf("Identity Matrix\n");
    else printf("Not Identity Matrix\n");
    return 0;
}
