
#include <stdio.h>
#include "museum.h"

void primsAlgorithm(void) {
    int key[V];
    int parent[V];
    int inMST[V] = {0};
    int i, count, u, v;
    int totalCost = 0;

    for (i = 0; i < V; i++) {
        key[i] = INF;
        parent[i] = -1;
    }

    key[0] = 0;

    for (count = 0; count < V; count++) {
        int minimum = INF;
        u = -1;

        for (i = 0; i < V; i++) {
            if (!inMST[i] && key[i] < minimum) {
                minimum = key[i];
                u = i;
            }
        }

        if (u == -1) {
            printf("\nMuseum graph is disconnected.\n");
            return;
        }

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

    printf("\nMINIMUM SPANNING TREE (PRIM'S ALGORITHM)\n\n");

    printf("%-15s %-15s %-10s\n",
           "From Room", "To Room", "Weight");

    for (i = 1; i < V; i++) {
        printf("%-15s %-15s %-10d\n",
               rooms[parent[i]], rooms[i], key[i]);

        totalCost += key[i];
    }

    printf("\nTotal minimum connection cost: %d minutes\n",
           totalCost);
}
