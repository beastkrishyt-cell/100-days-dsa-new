#include <stdio.h>
#define SIZE 10

int table[SIZE];

void init() {
    for(int i = 0; i < SIZE; i++) table[i] = -1;
}

int hash1(int key) {
    return key % SIZE;
}

int hash2(int key) {
    return 7 - (key % 7);
}

void insert(int key) {
    int index = hash1(key);
    int i = 0;

    while(table[index] != -1) {
        index = (hash1(key) + i * hash2(key)) % SIZE;
        i++;
        if(i == SIZE) {
            printf("Table Full\n");
            return;
        }
    }
    table[index] = key;
}

int search(int key) {
    int i = 0, index;

    while(i < SIZE) {
        index = (hash1(key) + i * hash2(key)) % SIZE;
        if(table[index] == key) return index;
        if(table[index] == -1) break;
        i++;
    }
    return -1;
}

void delete(int key) {
    int pos = search(key);
    if(pos != -1) table[pos] = -1;
}

void display() {
    for(int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, table[i]);
}