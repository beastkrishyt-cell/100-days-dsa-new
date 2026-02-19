#include <stdio.h>
int main() {
    int n1, n2;
    if (scanf("%d", &n1) != 1) return 0;
    int arr1[1000];
    for (int i = 0; i < n1; i++) {
        scanf("%d", &arr1[i]);
    }
    if (scanf("%d", &n2) != 1) return 0;
    int arr2[1000];
    for (int i = 0; i < n2; i++) {
        scanf("%d", &arr2[i]);
    }
    int arr3[2000];
    int i = 0, j = 0, k = 0;
    while (i < n1 && j < n2) {
        if (arr1[i] < arr2[j]) {
            arr3[k++] = arr1[i++];
        } else {
            arr3[k++] = arr2[j++];
        }
    }
    while (i < n1) {
        arr3[k++] = arr1[i++];
    }
    while (j < n2) {
        arr3[k++] = arr2[j++];
    }
    for (int l = 0; l < n1 + n2; l++) {
        printf("%d ", arr3[l]);
    }
    printf("\n");
    return 0;
}
