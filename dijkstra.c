
#include <stdio.h>
#include "museum.h"

void dijkstra(int source, int destination) {
    int distance[V];
    int visited[V] = {0};
    int parent[V];
    int path[V];
    int pathCount = 0;
    int i, j, u, v;

    for (i = 0; i < V; i++) {
        distance[i] = INF;
        parent[i] = -1;
    }

    distance[source] = 0;

    for (i = 0; i < V - 1; i++) {
        int minimum = INF;
        u = -1;

        for (j = 0; j < V; j++) {
            if (!visited[j] && distance[j] < minimum) {
                minimum = distance[j];
                u = j;
            }
        }

        if (u == -1) {
            break;
        }

        visited[u] = 1;

        for (v = 0; v < V; v++) {
            if (graph[u][v] > 0 &&
                !visited[v] &&
                distance[u] + graph[u][v] < distance[v]) {

                distance[v] = distance[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    if (distance[destination] == INF) {
        printf("\nNo route exists between these rooms.\n");
        return;
    }

    v = destination;

    while (v != -1) {
        path[pathCount++] = v;
        v = parent[v];
    }

    printf("\nSHORTEST ROUTE\n");

    for (i = pathCount - 1; i >= 0; i--) {
        printf("%s", rooms[path[i]]);

        if (i > 0) {
            printf(" -> ");
        }
    }

    printf("\nTotal walking time: %d minutes\n",
           distance[destination]);
}
