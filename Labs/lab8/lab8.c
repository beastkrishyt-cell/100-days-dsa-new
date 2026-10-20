#include <stdio.h>
#include <stdlib.h>

#define MAX 10

// ---------- Adjacency Matrix ----------
int adjMatrix[MAX][MAX];
int vertices;

// ---------- Adjacency List ----------
struct Node {
    int vertex;
    struct Node* next;
};

struct Node* adjList[MAX];

// ---------- Queue for BFS ----------
int queue[MAX], front = -1, rear = -1;

void enqueue(int v) {
    if(rear == MAX-1) return;
    if(front == -1) front = 0;
    queue[++rear] = v;
}

int dequeue() {
    if(front == -1) return -1;
    int val = queue[front];
    if(front == rear)
        front = rear = -1;
    else
        front++;
    return val;
}

// ---------- Graph Creation ----------
void createGraph() {
    int edges, src, dest;

    printf("Enter number of vertices: ");
    scanf("%d", &vertices);

    // Initialize
    for(int i=0;i<vertices;i++) {
        adjList[i] = NULL;
        for(int j=0;j<vertices;j++)
            adjMatrix[i][j] = 0;
    }

    printf("Enter number of edges: ");
    scanf("%d", &edges);

    for(int i=0;i<edges;i++) {
        printf("Enter edge (src dest): ");
        scanf("%d %d", &src, &dest);

        // Matrix
        adjMatrix[src][dest] = 1;
        adjMatrix[dest][src] = 1; // undirected

        // List
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = dest;
        newNode->next = adjList[src];
        adjList[src] = newNode;

        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->vertex = src;
        newNode->next = adjList[dest];
        adjList[dest] = newNode;
    }
}

// ---------- Display Matrix ----------
void displayMatrix() {
    printf("\nAdjacency Matrix:\n");
    for(int i=0;i<vertices;i++) {
        for(int j=0;j<vertices;j++) {
            printf("%d ", adjMatrix[i][j]);
        }
        printf("\n");
    }
}

// ---------- Display List ----------
void displayList() {
    printf("\nAdjacency List:\n");
    for(int i=0;i<vertices;i++) {
        struct Node* temp = adjList[i];
        printf("%d -> ", i);
        while(temp) {
            printf("%d -> ", temp->vertex);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}

// ---------- DFS ----------
int visitedDFS[MAX];

void DFS(int v) {
    printf("%d ", v);
    visitedDFS[v] = 1;

    struct Node* temp = adjList[v];
    while(temp) {
        if(!visitedDFS[temp->vertex])
            DFS(temp->vertex);
        temp = temp->next;
    }
}

// ---------- BFS ----------
void BFS(int start) {
    int visited[MAX] = {0};

    enqueue(start);
    visited[start] = 1;

    while(front != -1) {
        int v = dequeue();
        printf("%d ", v);

        struct Node* temp = adjList[v];
        while(temp) {
            if(!visited[temp->vertex]) {
                enqueue(temp->vertex);
                visited[temp->vertex] = 1;
            }
            temp = temp->next;
        }
    }
}

// ---------- Main ----------
int main() {
    int choice, start;

    while(1) {
        printf("\n--- MENU ---\n");
        printf("1. Create Graph\n");
        printf("2. Display Adjacency Matrix\n");
        printf("3. Display Adjacency List\n");
        printf("4. DFS Traversal\n");
        printf("5. BFS Traversal\n");
        printf("6. Exit\n");

        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                createGraph();
                break;

            case 2:
                displayMatrix();
                break;

            case 3:
                displayList();
                break;

            case 4:
                for(int i=0;i<MAX;i++) visitedDFS[i] = 0;
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                printf("DFS: ");
                DFS(start);
                break;

            case 5:
                printf("Enter starting vertex: ");
                scanf("%d", &start);
                printf("BFS: ");
                BFS(start);
                break;

            case 6:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    }
}