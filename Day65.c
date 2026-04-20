#include <stdio.h>
int adj[100][100];
int visited[100];
int n;
int hasCycleDFS(int v, int parent) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i]) {
            if (!visited[i]) {
                if (hasCycleDFS(i, v)) return 1;
            } else if (i != parent) {
                return 1;
            }
        }
    }
    return 0;
}
int main() {
    int m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1; adj[v][u] = 1;
    }
    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            if (hasCycleDFS(i, -1)) {
                cycle = 1;
                break;
            }
        }
    }
    if (cycle) printf("YES\n");
    else printf("NO\n");
    return 0;
}
