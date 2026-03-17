#include <stdio.h>
#include <stdlib.h>
int stack[1000], top = -1;
void push(int val) { stack[++top] = val; }
void pop() { if (top >= 0) top--; }
void display() {
    for (int i = 0; i <= top; i++) printf("%d ", stack[i]);
    printf("\n");
}
int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int val; scanf("%d", &val);
            push(val);
        } else if (type == 2) { pop(); }
        else if (type == 3) { display(); }
    }
    return 0;
}
