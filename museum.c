
#include <stdio.h>
#include "museum.h"

int graph[V][V] = {
    {0, 4, 2, 0, 0, 0},
    {4, 0, 1, 5, 0, 0},
    {2, 1, 0, 8, 10, 0},
    {0, 5, 8, 0, 2, 6},
    {0, 0, 10, 2, 0, 3},
    {0, 0, 0, 6, 3, 0}
};

const char rooms[V][20] = {
    "Entrance",
    "History",
    "Art",
    "Science",
    "Sculpture",
    "Exit"
};

struct Exhibit exhibits[E] = {
    {104, "Paintings", 30, 80},
    {101, "Ancient Coins", 25, 60},
    {106, "Space Models", 40, 100},
    {102, "Pottery", 20, 50},
    {105, "Sculptures", 35, 90},
    {103, "Old Maps", 15, 40}
};

void displayRooms(void) {
    int i;

    printf("\nMUSEUM ROOMS\n");

    for (i = 0; i < V; i++) {
        printf("%d. %s\n", i, rooms[i]);
    }
}

void displayConnections(void) {
    int i, j;

    printf("\nMUSEUM CONNECTIONS\n");

    for (i = 0; i < V; i++) {
        for (j = i + 1; j < V; j++) {
            if (graph[i][j] != 0) {
                printf("%s <-> %s : %d minutes\n",
                       rooms[i], rooms[j], graph[i][j]);
            }
        }
    }
}

void displayExhibits(void) {
    int i;

    printf("\n%-8s %-20s %-12s %-8s\n",
           "ID", "Exhibit", "Time", "Value");

    for (i = 0; i < E; i++) {
        printf("%-8d %-20s %-12d %-8d\n",
               exhibits[i].id,
               exhibits[i].name,
               exhibits[i].time,
               exhibits[i].value);
    }
}
