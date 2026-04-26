#include <stdio.h>
#define SIZE 10
int hashTable[SIZE];
void initTable() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}
int h(int key) { return key % SIZE; }
void insert(int key) {
    int index = h(key);
    int i = 0;
    while (hashTable[(index + i * i) % SIZE] != -1) {
        i++;
        if (i == SIZE) { printf("Table Full\n"); return; }
    }
    hashTable[(index + i * i) % SIZE] = key;
}
void display() {
    for (int i = 0; i < SIZE; i++) {
        if (hashTable[i] == -1) printf("%d: -\n", i);
        else printf("%d: %d\n", i, hashTable[i]);
    }
}
int main() {
    initTable();
    int n;
    if (scanf("%d", &n) != 1) return 0;
    for (int i = 0; i < n; i++) {
        int key; scanf("%d", &key);
        insert(key);
    }
    display();
    return 0;
}
