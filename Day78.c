#include <stdio.h>
#include <limits.h>
int adj[100][100];
int inMST[100];
int key[100];
int n;
int minKey() {
    int min = INT_MAX, idx = -1;
    for (int v = 0; v < n; v++) {
        if (!inMST[v] && key[v] < min) {
            min = key[v]; idx = v;
        }
    }
    return idx;
}
int main() {
    int m;
    if (scanf("%d %d", &n, &m) != 2) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
        inMST[i] = 0;
        key[i] = INT_MAX;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w; adj[v][u] = w;
    }
    key[0] = 0;
    int totalWeight = 0;
    for (int count = 0; count < n; count++) {
        int u = minKey();
        inMST[u] = 1;
        totalWeight += key[u];
        for (int v = 0; v < n; v++) {
            if (adj[u][v] && !inMST[v] && adj[u][v] < key[v]) {
                key[v] = adj[u][v];
            }
        }
    }
    printf("%d\n", totalWeight);
    return 0;
}
