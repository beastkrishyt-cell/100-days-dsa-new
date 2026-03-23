#include <stdio.h>
int queue[1000], pr[1000], size = 0;
void enqueue(int val, int p) {
    queue[size] = val; pr[size] = p; size++;
}
int peek() {
    int hp = -1, ind = -1;
    for (int i = 0; i < size; i++) {
        if (hp == pr[i] && ind > -1 && queue[ind] < queue[i]) {
            hp = pr[i]; ind = i;
        } else if (hp < pr[i]) {
            hp = pr[i]; ind = i;
        }
    }
    return ind;
}
void dequeue() {
    int ind = peek();
    if (ind != -1) {
        for (int i = ind; i < size - 1; i++) {
            queue[i] = queue[i + 1]; pr[i] = pr[i + 1];
        }
        size--;
    }
}
void display() {
    for (int i = 0; i < size; i++) printf("%d ", queue[i]);
    printf("\n");
}
int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int type; scanf("%d", &type);
        if (type == 1) {
            int val, p; scanf("%d %d", &val, &p);
            enqueue(val, p);
        } else if (type == 2) { dequeue(); }
        else if (type == 3) { display(); }
    }
    return 0;
}
