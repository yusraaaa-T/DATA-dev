#include <stdio.h>

#define MAX 100

int graph[MAX][MAX];   
int visited[MAX];
int n;                 
int i;
int j;
void DFS(int node, int cluster_id, int cluster[]) {
    visited[node] = 1;
    cluster[node] = cluster_id;

    for ( i= 0; i < n; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            DFS(i, cluster_id, cluster);
        }
    }
}

int main() {
    int cluster[MAX];
    int cluster_id = 0;

    printf("Dugum sayisini girin: ");
    scanf("%d", &n);

    printf("Adjacency matrix girin (0/1):\n");
    for ( i = 0; i < n; i++) {
        for ( j = 0; j < n; j++) {
            scanf("%d", &graph[i][j]);
        }
    }

    for ( i = 0; i < n; i++) {
        visited[i] = 0;
        cluster[i] = -1;
    }

    for ( i = 0; i < n; i++) {
        if (!visited[i]) {
            DFS(i, cluster_id, cluster);
            cluster_id++;
        }
    }

    printf("\nToplam cluster sayisi: %d\n", cluster_id);
    for (i = 0; i < n; i++) {
        printf("Dugum %d -> Cluster %d\n", i, cluster[i]);
    }

    return 0;
}

