#include <stdio.h>
int main() {
    int n, k;
    if (scanf("%d", &n) != 1) return 0;
    int arr[1000];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    if (scanf("%d", &k) != 1) return 0;
    int count = 0;
    int found = 0;
    for (int i = 0; i < n; i++) {
        count++;
        if (arr[i] == k) {
            found = 1;
            break;
        }
    }
    if (found) {
        printf("Found\n");
    } else {
        printf("Not Found\n");
    }
    printf("%d\n", count);
    return 0;
}
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
// update 2
// update 1
