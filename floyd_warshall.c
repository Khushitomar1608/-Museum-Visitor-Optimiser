
#include <stdio.h>
#include "museum.h"

void floydWarshall(void) {
    int dist[V][V];
    int i, j, k;

    for (i = 0; i < V; i++) {
        for (j = 0; j < V; j++) {
            if (i == j) {
                dist[i][j] = 0;
            }
            else if (graph[i][j] != 0) {
                dist[i][j] = graph[i][j];
            }
            else {
                dist[i][j] = INF;
            }
        }
    }

    for (k = 0; k < V; k++) {
        for (i = 0; i < V; i++) {
            for (j = 0; j < V; j++) {

                if (dist[i][k] != INF &&
                    dist[k][j] != INF &&
                    dist[i][k] + dist[k][j] < dist[i][j]) {

                    dist[i][j] = dist[i][k] + dist[k][j];
                }
            }
        }
    }

    printf("\nALL-PAIRS SHORTEST DISTANCE MATRIX\n\n");

    printf("%-12s", "");

    for (i = 0; i < V; i++) {
        printf("%-12s", rooms[i]);
    }

    printf("\n");

    for (i = 0; i < V; i++) {
        printf("%-12s", rooms[i]);

        for (j = 0; j < V; j++) {
            if (dist[i][j] == INF) {
                printf("%-12s", "INF");
            }
            else {
                printf("%-12d", dist[i][j]);
            }
        }

        printf("\n");
    }
}
