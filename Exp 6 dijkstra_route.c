#include <stdio.h>
#define INF 9999
#define MAX 20

void dijkstra(int graph[MAX][MAX], int n, int start) {
    int cost[MAX][MAX], distance[MAX], visited[MAX], count, minDist, nextNode;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cost[i][j] = (graph[i][j] == 0) ? INF : graph[i][j];

    for (int i = 0; i < n; i++) {
        distance[i] = cost[start][i];
        visited[i] = 0;
    }

    distance[start] = 0;
    visited[start] = 1;
    count = 1;

    while (count < n - 1) {
        minDist = INF;
        for (int i = 0; i < n; i++)
            if (distance[i] < minDist && !visited[i]) {
                minDist = distance[i];
                nextNode = i;
            }

        visited[nextNode] = 1;

        for (int i = 0; i < n; i++)
            if (!visited[i] && minDist + cost[nextNode][i] < distance[i])
                distance[i] = minDist + cost[nextNode][i];

        count++;
    }

    printf("\nShortest distances from source city %d:\n", start + 1);
    for (int i = 0; i < n; i++)
        printf("To city %d: %d\n", i + 1, distance[i]);
}

int main() {
    int n, start;
    int graph[MAX][MAX];

    printf("Enter number of cities: ");
    scanf("%d", &n);

    printf("Enter distance matrix (0 if no direct road):\n");
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &graph[i][j]);

    printf("Enter starting city (1 to %d): ", n);
    scanf("%d", &start);

    dijkstra(graph, n, start - 1);

    return 0;
}
