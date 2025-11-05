#include <stdio.h>

#define MAX 20

int findParent(int parent[], int i) {
    if (parent[i] == i)
        return i;
    return findParent(parent, parent[i]);
}

void kruskal(int cost[MAX][MAX], int n) {
    int parent[MAX];
    int edges = 0, minCost = 0;

    for (int i = 0; i < n; i++)
        parent[i] = i;

    printf("\nUsing Kruskal's Algorithm:\n");
    while (edges < n - 1) {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (findParent(parent, i) != findParent(parent, j) && cost[i][j] < min) {
                    min = cost[i][j];
                    a = i;
                    b = j;
                }
            }
        }

        if (a != -1 && b != -1) {
            parent[findParent(parent, a)] = findParent(parent, b);
            printf("Edge %d: (%d - %d) cost: %d\n", edges + 1, a + 1, b + 1, min);
            minCost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = 9999;
    }
    printf("Minimum cost using Kruskal's Algorithm: %d\n", minCost);
}

void prims(int cost[MAX][MAX], int n) {
    int visited[MAX] = {0};
    visited[0] = 1;
    int edges = 0, minCost = 0;

    printf("\nUsing Prim's Algorithm:\n");
    while (edges < n - 1) {
        int min = 9999, a = -1, b = -1;
        for (int i = 0; i < n; i++) {
            if (visited[i]) {
                for (int j = 0; j < n; j++) {
                    if (!visited[j] && cost[i][j] < min) {
                        min = cost[i][j];
                        a = i;
                        b = j;
                    }
                }
            }
        }

        if (a != -1 && b != -1) {
            printf("Edge %d: (%d - %d) cost: %d\n", edges + 1, a + 1, b + 1, min);
            visited[b] = 1;
            minCost += min;
            edges++;
        }
        cost[a][b] = cost[b][a] = 9999;
    }
    printf("Minimum cost using Prim's Algorithm: %d\n", minCost);
}

int main() {
    int n;
    int cost[MAX][MAX];

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    printf("Enter cost adjacency matrix (9999 for no edge):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &cost[i][j]);

    int cost1[MAX][MAX], cost2[MAX][MAX];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) {
            cost1[i][j] = cost[i][j];
            cost2[i][j] = cost[i][j];
        }

    prims(cost1, n);
    kruskal(cost2, n);

    return 0;
}
