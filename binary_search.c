
#include <stdio.h>
#include "museum.h"

int binarySearch(struct Exhibit arr[], int n, int key) {
    int low = 0;
    int high = n - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (arr[mid].id == key) {
            return mid;
        }

        if (arr[mid].id < key) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    return -1;
}

void searchExhibit(void) {
    struct Exhibit sorted[E];
    int i, key, result;

    for (i = 0; i < E; i++) {
        sorted[i] = exhibits[i];
    }

    mergeSort(sorted, 0, E - 1);

    printf("\nEnter exhibit ID to search: ");

    if (scanf("%d", &key) != 1) {
        printf("Invalid input.\n");
        while (getchar() != '\n');
        return;
    }

    result = binarySearch(sorted, E, key);

    if (result == -1) {
        printf("\nExhibit not found.\n");
    }
    else {
        printf("\nEXHIBIT FOUND\n");
        printf("ID: %d\n", sorted[result].id);
        printf("Name: %s\n", sorted[result].name);
        printf("Visit time: %d minutes\n", sorted[result].time);
        printf("Interest value: %d\n", sorted[result].value);
    }
}
