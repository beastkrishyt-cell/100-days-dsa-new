#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

struct node {
    int key;
    struct node* next;
};

struct node* table[SIZE];

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->key = key;
    newNode->next = table[index];
    table[index] = newNode;
}

int search(int key) {
    int index = hash(key);
    struct node* temp = table[index];

    while(temp) {
        if(temp->key == key) return 1;
        temp = temp->next;
    }
    return 0;
}

void delete(int key) {
    int index = hash(key);
    struct node *temp = table[index], *prev = NULL;

    while(temp) {
        if(temp->key == key) {
            if(prev == NULL)
                table[index] = temp->next;
            else
                prev->next = temp->next;
            free(temp);
            return;
        }
        prev = temp;
        temp = temp->next;
    }
}

void display() {
    for(int i = 0; i < SIZE; i++) {
        struct node* temp = table[i];
        printf("%d -> ", i);
        while(temp) {
            printf("%d -> ", temp->key);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}