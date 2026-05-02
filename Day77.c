#include <stdio.h>
int adj[100][100];
int visited[100];
int n;
void dfs(int v) {
    visited[v] = 1;
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) dfs(i);
    }
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
    dfs(0);
    int connected = 1;
    for (int i = 0; i < n; i++) {
        if (!visited[i]) { connected = 0; break; }
    }
    if (connected) printf("YES\n");
    else printf("NO\n");
    return 0;
}
