#include <stdio.h>
int stack[1000], top = -1;
int main() {
    int n, m;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int val; scanf("%d", &val);
        stack[++top] = val;
    }
    if (scanf("%d", &m) != 1) return 0;
    for (int i = 0; i < m; i++) {
        if (top >= 0) top--;
    }
    for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
    return 0;
}
