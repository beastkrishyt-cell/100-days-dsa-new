#include <stdio.h>
int adj[100][100];
int inDegree[100];
int n;
void topologicalSort() {
    int queue[100], front = 0, rear = 0;
    for (int i = 0; i < n; i++) {
        if (inDegree[i] == 0) queue[rear++] = i;
    }
    int count = 0;
    while (front < rear) {
        int u = queue[front++];
        printf("%d ", u);
        for (int i = 0; i < n; i++) {
            if (adj[u][i]) {
                if (--inDegree[i] == 0) queue[rear++] = i;
            }
        }
        count++;
    }
    printf("\n");
}
int main() {
    int m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        inDegree[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1; inDegree[v]++;
    }
    topologicalSort();
    return 0;
}
