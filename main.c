
#include <stdio.h>
#include "museum.h"

int main(void) {
    int choice;
    int source, destination;

    do {
        printf("\n====================================\n");
        printf("       MUSEUM VISITOR OPTIMIZER\n");
        printf("====================================\n");

        printf("1. Display Museum Information\n");
        printf("2. Find Shortest Route (Dijkstra)\n");
        printf("3. Display All-Pairs Shortest Paths (Floyd-Warshall)\n");
        printf("4. Generate Minimum Spanning Tree (Prim's)\n");
        printf("5. Sort Exhibits (Merge Sort)\n");
        printf("6. Search Exhibit (Binary Search)\n");
        printf("7. Select Exhibits (0/1 Knapsack)\n");
        printf("8. Generate Graph Visualizations\n");
        printf("9. Exit\n");

        printf("\nEnter your choice: ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Enter a number.\n");

            while (getchar() != '\n');

            continue;
        }

        switch (choice) {

            case 1:
                displayRooms();
                displayConnections();
                displayExhibits();
                break;

            case 2:
                printf("\nEnter source room ID (0-5): ");

                if (scanf("%d", &source) != 1 ||
                    source < 0 || source >= V) {
                    printf("Invalid source room.\n");
                    while (getchar() != '\n');
                    break;
                }

                printf("Enter destination room ID (0-5): ");

                if (scanf("%d", &destination) != 1 ||
                    destination < 0 || destination >= V) {
                    printf("Invalid destination room.\n");
                    while (getchar() != '\n');
                    break;
                }

                dijkstra(source, destination);
                break;

            case 3:
                floydWarshall();
                break;

            case 4:
                primsAlgorithm();
                break;

            case 5:
                sortExhibits();
                break;

            case 6:
                searchExhibit();
                break;

            case 7:
                selectExhibits();
                break;

            case 8:
                printf("\nGenerating museum graph...\n");
                generateMuseumGraph();

                printf("\nGenerating Dijkstra route graph "
                       "(Entrance to Exit)...\n");
                generateDijkstraGraph(0, 5);

                printf("\nGenerating Prim's MST graph...\n");
                generatePrimGraph();
                break;

            case 9:
                printf("\nExiting Museum Visitor Optimizer.\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 9);

    return 0;
}
