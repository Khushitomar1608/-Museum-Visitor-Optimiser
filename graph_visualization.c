
#include <stdio.h>
#include "museum.h"

/* 1. Display Complete Museum Graph */
void generateMuseumGraph(void) {

    int i, j;

    printf("\n");
    printf("========================================\n");
    printf("          COMPLETE MUSEUM GRAPH\n");
    printf("========================================\n");

    printf("\nROOMS:\n");

    for (i = 0; i < V; i++) {
        printf("(%d) %s\n", i, rooms[i]);
    }

    printf("\nCONNECTIONS AND WEIGHTS:\n\n");

    for (i = 0; i < V; i++) {

        for (j = i + 1; j < V; j++) {

            if (graph[i][j] > 0) {

                printf("%-12s <--- %d min ---> %s\n",
                       rooms[i], graph[i][j], rooms[j]);
            }
        }
    }

    printf("\n========================================\n");
}


/* 2. Display Dijkstra Shortest Route */
void generateDijkstraGraph(int source, int destination) {

    int distance[V];
    int visited[V] = {0};
    int parent[V];
    int path[V];

    int i, j, u, v;
    int pathCount = 0;

    if (source < 0 || source >= V ||
        destination < 0 || destination >= V) {

        printf("Invalid room selection.\n");
        return;
    }

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

        if (u == -1)
            break;

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
        printf("No route exists.\n");
        return;
    }

    v = destination;

    while (v != -1) {
        path[pathCount++] = v;
        v = parent[v];
    }

    printf("\n");
    printf("========================================\n");
    printf("       DIJKSTRA SHORTEST ROUTE\n");
    printf("========================================\n\n");

    for (i = pathCount - 1; i >= 0; i--) {

        printf("%s", rooms[path[i]]);

        if (i > 0) {

            int current = path[i];
            int next = path[i - 1];

            printf(" --(%d min)--> ", graph[current][next]);
        }
    }

    printf("\n\nTotal Walking Time: %d minutes\n",
           distance[destination]);

    printf("========================================\n");
}


/* 3. Display Prim's Minimum Spanning Tree */
void generatePrimGraph(void) {

    int key[V];
    int parent[V];
    int inMST[V] = {0};

    int i, j, u, v;
    int totalWeight = 0;
    int edgeCount = 0;

    for (i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (i = 0; i < V - 1; i++) {

        int minimum = INF;
        u = -1;

        for (j = 0; j < V; j++) {

            if (!inMST[j] && key[j] < minimum) {
                minimum = key[j];
                u = j;
            }
        }

        if (u == -1)
            break;

        inMST[u] = 1;

        for (v = 0; v < V; v++) {

            if (graph[u][v] > 0 &&
                !inMST[v] &&
                graph[u][v] < key[v]) {

                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printf("\n");
    printf("========================================\n");
    printf("     PRIM'S MINIMUM SPANNING TREE\n");
    printf("========================================\n\n");

    for (i = 1; i < V; i++) {

        if (parent[i] == -1) {
            printf("Graph is disconnected. MST cannot connect all rooms.\n");
            return;
        }

        printf("%s --(%d min)-- %s\n",
               rooms[parent[i]], graph[i][parent[i]], rooms[i]);

        totalWeight += graph[i][parent[i]];
        edgeCount++;
    }

    printf("\nTotal MST Weight: %d minutes\n", totalWeight);
    printf("Total Edges: %d\n", edgeCount);

    printf("========================================\n");
}


