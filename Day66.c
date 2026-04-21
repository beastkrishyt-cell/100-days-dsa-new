#include <stdio.h>
int adj[100][100];
int visited[100];
int recStack[100];
int n;
int isCyclicUtil(int v) {
    if (visited[v] == 0) {
        visited[v] = 1;
        recStack[v] = 1;
        for (int i = 0; i < n; i++) {
            if (adj[v][i]) {
                if (!visited[i] && isCyclicUtil(i)) return 1;
                else if (recStack[i]) return 1;
            }
        }
    }
    recStack[v] = 0;
    return 0;
}
int main() {
    int m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        visited[i] = 0; recStack[i] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        adj[u][v] = 1;
    }
    int cycle = 0;
    for (int i = 0; i < n; i++) {
        if (isCyclicUtil(i)) { cycle = 1; break; }
    }
    if (cycle) printf("YES\n");
    else printf("NO\n");
    return 0;
}
