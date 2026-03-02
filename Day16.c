#include <stdio.h>
int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[1000];
    for (int i = 0; i < n; i++) scanf("%d", &a[i]);
    int visited[1000] = {0};
    for (int i = 0; i < n; i++) {
        if (visited[i]) continue;
        int count = 1;
        for (int j = i + 1; j < n; j++) {
            if (a[i] == a[j]) {
                count++;
                visited[j] = 1;
            }
        }
        printf("%d:%d\n", a[i], count);
    }
    return 0;
}
