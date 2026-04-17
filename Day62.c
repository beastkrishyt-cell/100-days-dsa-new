#include <stdio.h>
#include <stdlib.h>
struct Node { int dest; struct Node* next; };
struct List { struct Node* head; };
struct Graph { int V; struct List* array; };
struct Node* newAdjListNode(int dest) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->dest = dest; newNode->next = NULL;
    return newNode;
}
struct Graph* createGraph(int V) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->array = (struct List*)malloc(V * sizeof(struct List));
    for (int i = 0; i < V; ++i) graph->array[i].head = NULL;
    return graph;
}
void addEdge(struct Graph* graph, int src, int dest) {
    struct Node* newNode = newAdjListNode(dest);
    newNode->next = graph->array[src].head;
    graph->array[src].head = newNode;
    newNode = newAdjListNode(src);
    newNode->next = graph->array[dest].head;
    graph->array[dest].head = newNode;
}
int main() {
    int n, m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    struct Graph* graph = createGraph(n);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        addEdge(graph, u, v);
    }
    for (int v = 0; v < graph->V; ++v) {
        struct Node* pCrawl = graph->array[v].head;
        printf("%d: ", v);
        while (pCrawl) {
            printf("%d ", pCrawl->dest);
            pCrawl = pCrawl->next;
        }
        printf("\n");
    }
    return 0;
}
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
// update 2
// update 3
// update 1
