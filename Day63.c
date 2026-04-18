#include <stdio.h>
#include <stdlib.h>
int adj[100][100];
int visited[100];
int n;
void dfs(int v) {
    visited[v] = 1;
    printf("%d ", v);
    for (int i = 0; i < n; i++) {
        if (adj[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}
int main() {
    int m, s;
    if (scanf("%d %d %d", &n, &m, &s) != 3) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        visited[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1; adj[v][u] = 1;
    }
    dfs(s);
    printf("\n");
    return 0;
}
