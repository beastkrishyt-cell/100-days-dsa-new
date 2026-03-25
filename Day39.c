#include <stdio.h>
void swap(int *x, int *y) { int temp = *x; *x = *y; *y = temp; }
void insert(int heap[], int *n, int val) {
    heap[*n] = val;
    int i = *n;
    (*n)++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}
void display(int heap[], int n) {
    for (int i = 0; i < n; i++) printf("%d ", heap[i]);
    printf("\n");
}
int main() {
    int heap[1000], n = 0;
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) { int v; scanf("%d", &v); insert(heap, &n, v); }
        else if (type == 2) display(heap, n);
    }
    return 0;
}
