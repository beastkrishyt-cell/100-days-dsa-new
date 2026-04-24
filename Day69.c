#include <stdio.h>
#include <limits.h>
int adj[100][100];
int dist[100];
int visited[100];
int n;
int minDistance() {
    int min = INT_MAX, min_index;
    for (int v = 0; v < n; v++) {
        if (visited[v] == 0 && dist[v] <= min) {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}
void dijkstra(int src) {
    for (int i = 0; i < n; i++) {
        dist[i] = INT_MAX;
        visited[i] = 0;
    }
    dist[src] = 0;
    for (int count = 0; count < n - 1; count++) {
        int u = minDistance();
        visited[u] = 1;
        for (int v = 0; v < n; v++) {
            if (!visited[v] && adj[u][v] && dist[u] != INT_MAX && dist[u] + adj[u][v] < dist[v]) {
                dist[v] = dist[u] + adj[u][v];
            }
        }
    }
    for (int i = 0; i < n; i++) {
        if (dist[i] == INT_MAX) printf("INF ");
        else printf("%d ", dist[i]);
    }
    printf("\n");
}
int main() {
    int m, s;
    if (scanf("%d %d %d", &n, &m, &s) != 3) return 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) adj[i][j] = 0;
    }
    for (int i = 0; i < m; i++) {
        int u, v, w; scanf("%d %d %d", &u, &v, &w);
        adj[u][v] = w;
    }
    dijkstra(s);
    return 0;
}
